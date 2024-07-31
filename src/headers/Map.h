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
    Map() = default;

    void draw();

    void create(sf::RenderWindow *window);
    void update();
    void reshuffle();

    Cell *getCellAtPosition_CurrentGeneration(uint32_t positionX,
                                              uint32_t positonY);
    Cell *getCellAtPosition_NextGeneration(uint32_t positionX,
                                           uint32_t positonY);

    void setWindow(sf::RenderWindow *window);

  private:
    void initCells();
    void copyGenerations();
    void changeForNextGeneration(Cell &cell,
                                 uint32_t positionX,
                                 uint32_t positonY);

    uint32_t generateNumber(uint32_t max, uint32_t min);
    uint32_t countAliveNeighboursAtPosition(uint32_t positionX,
                                            uint32_t positonY);

    cell::State getRandomCellState(uint32_t criteriaForAlive);

  private:
    sf::RenderWindow *m_window;

    Cell m_currentGeneration[map::ROWS][map::COLUMNS];
    Cell m_nextGeneration[map::ROWS][map::COLUMNS];
};

} // namespace gol
