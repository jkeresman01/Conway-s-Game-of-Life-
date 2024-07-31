#include "headers/Map.h"

#include <algorithm>

namespace gol
{

void Map::create(sf::RenderWindow *t_window)
{
    m_window = t_window;

    initCells();
}

void Map::initCells()
{
    for (size_t i = 0; i < map::ROWS; ++i)
    {
        for (size_t j = 0; j < map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].setWindow(m_window);
            m_currentGeneration[i][j].setPosition(cell::START_POSITION_X + (j * cell::WIDTH),
                                                  cell::START_POSITION_Y + (i * cell::HEIGHT));

            m_nextGeneration[i][j] = m_currentGeneration[i][j];
        }
    }
}

void Map::draw()
{
    for (size_t i = 0; i < map::ROWS; ++i)
    {
        for (size_t j = 0; j < map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].draw();
        }
    }
}

Cell *Map::getCellAtPosition_CurrentGeneration(uint32_t t_positionX, uint32_t t_positonY)
{
    return &m_currentGeneration[t_positionX][t_positonY];
}

Cell *Map::getCellAtPosition_NextGeneration(uint32_t t_positionX, uint32_t t_positonY)
{
    return &m_nextGeneration[t_positionX][t_positonY];
}

void Map::update()
{
    for (size_t i = 1; i < map::ROWS - 1; ++i)
    {
        for (size_t j = 1; j < map::COLUMNS - 1; ++j)
        {
            changeForNextGeneration(m_currentGeneration[i][j], i, j);
        }
    }

    copyGenerations();
}

void Map::copyGenerations()
{
    for (size_t i = 1; i < map::ROWS - 1; ++i)
    {
        for (size_t j = 1; j < map::COLUMNS - 1; ++j)
        {
            m_currentGeneration[i][j] = m_nextGeneration[i][j];
        }
    }
}

void Map::reshuffle()
{
    for (size_t i = 1; i < map::ROWS - 1; ++i)
    {
        for (size_t j = 1; j < map::COLUMNS - 1; ++j)
        {
            cell::State randomCellState = getRandomCellState(map::Critera::RANDOM);
            m_currentGeneration[i][j].setState(randomCellState);
        }
    }
}

uint32_t Map::generateNumber(uint32_t t_max, uint32_t t_min)
{
    return rand() % (t_max - t_min + 1) + t_min;
}

cell::State Map::getRandomCellState(uint32_t t_criteriaForAlive)
{
    uint32_t possiblityForAlive = generateNumber(100, 1);
    return possiblityForAlive <= t_criteriaForAlive ? cell::State::ALIVE : cell::State::DEAD;
}

void Map::changeForNextGeneration(Cell &t_cell, uint32_t t_positionX, uint32_t t_positionY)
{
    uint32_t numberOfAliveNeighbours = countAliveNeighboursAtPosition(t_positionX, t_positionY);

    if (t_cell.isAlive() and numberOfAliveNeighbours >= game::Criteria::OVERPOPULATION or
        numberOfAliveNeighbours < game::Criteria::UNDERPOPULATION)
    {
        m_nextGeneration[t_positionX][t_positionY].setState(cell::State::DEAD);
    }
    else if (!t_cell.isAlive() and numberOfAliveNeighbours == game::Criteria::BORN)
    {
        m_nextGeneration[t_positionX][t_positionY].setState(cell::State::ALIVE);
    }
    else
    {
        m_nextGeneration[t_positionX][t_positionY] = m_currentGeneration[t_positionX][t_positionY];
    }
}

uint32_t Map::countAliveNeighboursAtPosition(uint32_t t_positionX, uint32_t t_positionY)
{
    Cell neighbours[]{
        m_currentGeneration[t_positionX - 1][t_positionY],     m_currentGeneration[t_positionX + 1][t_positionY],
        m_currentGeneration[t_positionX][t_positionY - 1],     m_currentGeneration[t_positionX][t_positionY + 1],
        m_currentGeneration[t_positionX - 1][t_positionY - 1], m_currentGeneration[t_positionX + 1][t_positionY + 1],
        m_currentGeneration[t_positionX + 1][t_positionY - 1], m_currentGeneration[t_positionX - 1][t_positionY + 1],
    };

    return std::count_if(neighbours, neighbours + cell::NUMBER_OF_NEIGHBOURS,
                         [](Cell &cell) { return cell.isAlive(); });
}

} // namespace gol
