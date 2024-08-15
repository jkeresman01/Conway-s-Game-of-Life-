#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Cell.h"
#include "GameConstants.h"

namespace gol
{

class Map
{
  public:
    Map();

    void render(sf::RenderWindow &window) const;
    void update();
    void reshuffle();

    Cell *getCellAtPosition_CurrentGeneration(uint32_t positionX, uint32_t positionY);
    Cell *getCellAtPosition_NextGeneration(uint32_t positionX, uint32_t positionY);

  private:
    void copyGenerations();
    void updateCellState(uint32_t positionX, uint32_t positionY);
    uint32_t countAliveNeighbours(uint32_t positionX, uint32_t positionY);

    cell::State getRandomCellState(uint32_t criteriaForAlive);

  private:
    Cell m_currentGeneration[map::ROWS][map::COLUMNS];
    Cell m_nextGeneration[map::ROWS][map::COLUMNS];
};

} // namespace gol
