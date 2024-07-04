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

        void create(sf::RenderWindow *t_window);
        void update();
        void reshuffle();

    private:
        void initCells();
        void copyGenerations();
        void changeForNextGeneration(Cell &t_cell, uint32_t t_positionX, uint32_t t_positonY);

        uint32_t generateNumber(uint32_t t_max, uint32_t t_min);
        uint32_t countAliveNeighboursAtPosition(uint32_t t_positionX, uint32_t t_positonY);

        bool isBorder(uint32_t t_rowIndex, uint32_t t_columnIndex);

        cell::State getRandomCellState(uint32_t t_criteriaForAlive);

    private:
        sf::RenderWindow *m_window;

        Cell m_currentGeneration[map::ROWS][map::COLUMNS];
        Cell m_nextGeneration   [map::ROWS][map::COLUMNS];
};

} // gol
