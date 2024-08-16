#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Cell.h"

namespace gol
{

class Map
{
  public:
    Map();

    void render(sf::RenderWindow &window) const;
    void update();
    void reshuffle();

    Cell *getCellAtPosition_CurrentGeneration(uint32_t positionX, uint32_t positionY)
    {
        return &m_currentGeneration[positionX][positionY];
    }

    Cell *getCellAtPosition_NextGeneration(uint32_t positionX, uint32_t positionY)
    {
        return &m_nextGeneration[positionX][positionY];
    }

  private:
    void changeGenerations();
    void updateCellState(uint32_t positionX, uint32_t positionY);
    uint32_t countAliveNeighbours(uint32_t positionX, uint32_t positionY);

    State getRandomCellState(uint32_t criteriaForAlive) const;

  private:
    static const uint32_t ROWS    = 60;
    static const uint32_t COLUMNS = 120;

    Cell m_currentGeneration[ROWS][COLUMNS];
    Cell m_nextGeneration[ROWS][COLUMNS];

    const uint32_t NUMBER_OF_NEIGHBOURS = 8;

    const float START_POSITION_X = 45.0f;
    const float START_POSITION_Y = 100.0f;

    const int32_t UNDERPOPULATION = 2;
    const int32_t REPRODUCTION    = 3;
    const int32_t OVERPOPULATION  = 4;

    const uint32_t TWENTY_PERCENT_ALIVE = 20;
};

} // namespace gol
