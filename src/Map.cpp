#include "headers/Map.h"

#include <algorithm>

namespace gol
{

void Map::create(sf::RenderWindow *window)
{
    setWindow(window);
    initCells();
}

void Map::initCells()
{
    for (size_t i = 0; i < map::ROWS; ++i)
    {
        for (size_t j = 0; j < map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].setWindow(m_window);
            m_currentGeneration[i][j].setPosition(
                    cell::START_POSITION_X + (j * cell::WIDTH),
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

uint32_t Map::generateNumber(uint32_t max, uint32_t min)
{
    return rand() % (max - min + 1) + min;
}

cell::State Map::getRandomCellState(uint32_t criteriaForAlive)
{
    uint32_t possiblityForAlive = generateNumber(100, 1);
    return possiblityForAlive <= criteriaForAlive ? cell::State::ALIVE : cell::State::DEAD;
}

void Map::changeForNextGeneration(Cell &cell, uint32_t positionX, uint32_t positionY)
{
    uint32_t aliveNeighbours = countAliveNeighboursAtPosition(positionX, positionY);

    if (cell.isAlive() and aliveNeighbours >= game::Criteria::OVERPOPULATION or
        aliveNeighbours < game::Criteria::UNDERPOPULATION)
    {
        m_nextGeneration[positionX][positionY].setState(cell::State::DEAD);
    }
    else if (!cell.isAlive() and aliveNeighbours == game::Criteria::BORN)
    {
        m_nextGeneration[positionX][positionY].setState(cell::State::ALIVE);
    }
    else
    {
        m_nextGeneration[positionX][positionY] = m_currentGeneration[positionX][positionY];
    }
}

uint32_t Map::countAliveNeighboursAtPosition(uint32_t positionX, uint32_t positionY)
{
    Cell neighbours[]{
        m_currentGeneration[positionX - 1][positionY],
        m_currentGeneration[positionX + 1][positionY],
        m_currentGeneration[positionX][positionY - 1],
        m_currentGeneration[positionX][positionY + 1],
        m_currentGeneration[positionX - 1][positionY - 1],
        m_currentGeneration[positionX + 1][positionY + 1],
        m_currentGeneration[positionX + 1][positionY - 1],
        m_currentGeneration[positionX - 1][positionY + 1],
    };

    return std::count_if(neighbours, neighbours + cell::NUMBER_OF_NEIGHBOURS,
                         [](Cell &cell) { return cell.isAlive(); });
}

Cell *Map::getCellAtPosition_CurrentGeneration(uint32_t positionX, uint32_t positionY)
{
    return &m_currentGeneration[positionX][positionY];
}

Cell *Map::getCellAtPosition_NextGeneration(uint32_t positionX, uint32_t positionY)
{
    return &m_nextGeneration[positionX][positionY];
}

void Map::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

} // namespace gol
