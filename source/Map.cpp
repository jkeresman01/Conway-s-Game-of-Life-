#include "headers/Cell.h"
#include "headers/GameConstants.h"
#include "headers/Map.h"

#include <algorithm>

Map::Map()
{
}

void Map::create(sf::RenderWindow* t_window)
{
    m_window = t_window;
    initializeCells(gc::map::CRITERIA_20_PERCENT_ALIVE_CELLS);
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

void Map::draw()
{
    for(size_t i = 0; i < gc::map::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::map::COLUMNS; ++j)
        {
            if(!isBorder(i, j))
            {
                m_currentGeneration[i][j].draw();
            }
        }
    }
}

void Map::initializeCells(int t_criteriaForAlive)
{
    for(size_t i = 0; i < gc::map::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::map::COLUMNS; ++j)
        {
            m_currentGeneration[i][j].setWindow(m_window);
            m_currentGeneration[i][j].setPosition(
                    gc::cell::START_POSITION_X + (j * gc::cell::WIDTH), 
                    gc::cell::START_POSITION_Y + (i * gc::cell::HEIGHT));

            if(!isBorder(i, j))
            {
                gc::cell::State randomCellState = getRandomCellState(t_criteriaForAlive);
                m_currentGeneration[i][j].setState(randomCellState);
            }

            m_nextGeneration[i][j] = m_currentGeneration[i][j];
       }
   }
}

bool Map::isBorder(int i, int j)
{
    return i == 0 or i == gc::map::ROWS - 1 or j == 0 or j == gc::map::COLUMNS - 1;
}

int Map::generateNumber(int t_max, int t_min)
{
    return rand() % (t_max - t_min + 1) + t_min;
}

gc::cell::State Map::getRandomCellState(int t_criteriaForAlive){
    int possiblityForAlive = generateNumber(100, 1);
    return possiblityForAlive <= t_criteriaForAlive ? gc::cell::State::ALIVE : gc::cell::State::DEAD;
    
}

void Map::changeForNextGeneration(Cell &t_cell, int t_positionX, int t_positionY)
{
    int aliveNeighbours = countAliveNeighboursAtPosition(t_positionX, t_positionY);

    if(t_cell.isAlive() and aliveNeighbours > gc::game::OVERPOPULATION_CRITERIA or aliveNeighbours < gc::game::UNDERPOPULATION_CRITERIA)
    {
        m_nextGeneration[t_positionX][t_positionY].setState(gc::cell::DEAD);
    }

    if(!t_cell.isAlive() and aliveNeighbours == gc::game::BORN_CRITERIA)
    {
        m_nextGeneration[t_positionX][t_positionY].setState(gc::cell::ALIVE);
    }
}

int Map::countAliveNeighboursAtPosition(int t_positionX, int t_positionY)
{
    Cell neighbours[gc::cell::NUMBER_OF_NEIGHBOURS]
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

    return std::count_if(neighbours, neighbours + gc::cell::NUMBER_OF_NEIGHBOURS, [](Cell &cell){ return cell.isAlive();});
}
