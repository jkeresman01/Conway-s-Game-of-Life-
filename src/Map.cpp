#include "headers/Map.h"
#include "headers/Random.h"

#include <algorithm>
#include <cstring>

namespace gol
{

Map::Map()
{
    for (size_t i = 0; i < map::ROWS; ++i)
    {
        for (size_t j = 0; j < map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].setPosition(cell::START_POSITION_X + (j * cell::WIDTH),
                                                  cell::START_POSITION_Y + (i * cell::HEIGHT));
            m_nextGeneration[i][j] = m_currentGeneration[i][j];
        }
    }
}

void Map::render(sf::RenderWindow &window) const
{
    for (size_t i = 0; i < map::ROWS; ++i)
    {
        for (size_t j = 0; j < map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].render(window);
        }
    }
}

void Map::update()
{
    for (size_t i = 1; i < map::ROWS - 1; ++i)
    {
        for (size_t j = 1; j < map::COLUMNS - 1; ++j)
        {
            updateCellState(i, j);
        }
    }

    copyGenerations();
}

void Map::updateCellState(uint32_t positionX, uint32_t positionY)
{
    uint32_t aliveNeighbours = countAliveNeighbours(positionX, positionY);
    Cell cell = m_currentGeneration[positionX][positionY];

    if (cell.isAlive() and aliveNeighbours >= State::OVERPOPULATION or
        aliveNeighbours < State::UNDERPOPULATION)
    {
        m_nextGeneration[positionX][positionY].setState(cell::DEAD);
    }
    else if (!cell.isAlive() and aliveNeighbours == State::REPRODUCTION)
    {
        m_nextGeneration[positionX][positionY].setState(cell::ALIVE);
    }
    else
    {
        m_nextGeneration[positionX][positionY] = m_currentGeneration[positionX][positionY];
    }
}

uint32_t Map::countAliveNeighbours(uint32_t positionX, uint32_t positionY)
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
                         [](const Cell &cell) { return cell.isAlive(); });
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
            cell::State cellState = getRandomCellState(map::RANDOM);
            m_currentGeneration[i][j].setState(cellState);
        }
    }
}

cell::State Map::getRandomCellState(uint32_t criteriaForAlive)
{
    uint32_t possiblityForAlive = Random::generate(100);
    return possiblityForAlive <= criteriaForAlive ? cell::ALIVE : cell::DEAD;
}

Cell *Map::getCellAtPosition_CurrentGeneration(uint32_t positionX, uint32_t positionY)
{
    return &m_currentGeneration[positionX][positionY];
}

Cell *Map::getCellAtPosition_NextGeneration(uint32_t positionX, uint32_t positionY)
{
    return &m_nextGeneration[positionX][positionY];
}

} // namespace gol
