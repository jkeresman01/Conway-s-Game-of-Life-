#pragma once

#include "Cell.h"
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map
{
    public:
        Map() = default;

        void create(sf::RenderWindow *t_window);
        void draw();
        void update();
        void reshuffle();

    private:
        void initCells();
        void changeForNextGeneration(Cell &t_cell, int t_positionX, int t_positonY);

        int generateNumber(int t_max, int t_min);
        int countAliveNeighboursAtPosition(int t_positionX, int t_positonY);

        bool isBorder(int t_i, int t_j);

        gc::cell::State getRandomCellState(int t_criteriaForAlive);

    private:
        sf::RenderWindow *m_window;

        Cell m_currentGeneration[gc::map::ROWS][gc::map::COLUMNS];
        Cell m_nextGeneration[gc::map::ROWS][gc::map::COLUMNS];
};
