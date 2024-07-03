#include "headers/Map.h"

#include <algorithm>

#include "headers/Cell.h"
#include "headers/GameConstants.h"

typedef gc::cell::State CellState;

void Map::create(sf::RenderWindow* t_window)
{
    m_window = t_window;

    initCells();
}

void Map::initCells()
{
    for(size_t i = 0; i < gc::map::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].setWindow(m_window);
            m_currentGeneration[i][j].setPosition(
                    gc::cell::START_POSITION_X + (j * gc::cell::WIDTH), 
                    gc::cell::START_POSITION_Y + (i * gc::cell::HEIGHT));

            m_nextGeneration[i][j] = m_currentGeneration[i][j];
       }
   }
}

void Map::draw()
{
    for(size_t i = 0; i < gc::map::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].draw();
        }
    }
}

void Map::update()
{
    for(size_t i = 0; i < gc::map::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::map::COLUMNS; ++j)
        {
            if(!isBorder(i, j))
            {
                changeForNextGeneration(m_currentGeneration[i][j], i, j);
            }
        }
    }

    copyGenerations();
}

void Map::copyGenerations()
{
    for(size_t i = 0; i < gc::map::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::map::COLUMNS; ++j)
        {
            if(!isBorder(i, j))
            {
                m_currentGeneration[i][j] = m_nextGeneration[i][j];
            }
        }
    }
}

void Map::reshuffle()
{
    for(size_t i = 0; i < gc::map::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::map::COLUMNS; ++j)
        {
            if(!isBorder(i, j))
            {
                CellState randomCellState = getRandomCellState(gc::map::RANDOM_20_PERCENT_ALIVE);
                m_currentGeneration[i][j].setState(randomCellState);
            }
        }
    }
}

bool Map::isBorder(uint32_t t_rowIndex, uint32_t t_columnIndex)
{
    return t_rowIndex    == 0 or t_rowIndex    == gc::map::ROWS    - 1 or 
           t_columnIndex == 0 or t_columnIndex == gc::map::COLUMNS - 1;
}

uint32_t Map::generateNumber(uint32_t t_max, uint32_t t_min)
{
    return rand() % (t_max - t_min + 1) + t_min;
}

CellState Map::getRandomCellState(uint32_t t_criteriaForAlive){
    uint32_t possiblityForAlive = generateNumber(100, 1);
    return possiblityForAlive <= t_criteriaForAlive ? CellState::ALIVE : CellState::DEAD;
}

void Map::changeForNextGeneration(Cell &t_cell, uint32_t t_positionX, uint32_t t_positionY)
{
    uint32_t numberOfAliveNeighbours = countAliveNeighboursAtPosition(t_positionX, t_positionY);

    if(t_cell.isAlive() and numberOfAliveNeighbours > gc::game::OVERPOPULATION_CRITERIA or 
       numberOfAliveNeighbours < gc::game::UNDERPOPULATION_CRITERIA)
    {
        m_nextGeneration[t_positionX][t_positionY].setState(CellState::DEAD);
    }

    if(!t_cell.isAlive() and numberOfAliveNeighbours == gc::game::BORN_CRITERIA)
    {
        m_nextGeneration[t_positionX][t_positionY].setState(CellState::ALIVE);
    }
}

uint32_t Map::countAliveNeighboursAtPosition(uint32_t t_positionX, uint32_t t_positionY)
{
    Cell neighbours[]
    {
        m_currentGeneration[t_positionX - 1][t_positionY],
        m_currentGeneration[t_positionX + 1][t_positionY],
        m_currentGeneration[t_positionX][t_positionY - 1],
        m_currentGeneration[t_positionX][t_positionY + 1],
        m_currentGeneration[t_positionX - 1][t_positionY - 1],
        m_currentGeneration[t_positionX + 1][t_positionY + 1],
        m_currentGeneration[t_positionX + 1][t_positionY - 1],
        m_currentGeneration[t_positionX - 1][t_positionY + 1],
    };

    return std::count_if(neighbours, neighbours + gc::cell::NUMBER_OF_NEIGHBOURS, 
            [](Cell &cell){ return cell.isAlive(); });
}
