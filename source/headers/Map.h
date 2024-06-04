#pragma once

#include "Cell.h"
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map
{
    public:
        Map();
        void create(sf::RenderWindow *t_window);
        void initializeCells(const int t_criteriaForAlive);
        void draw();
        void update();

    private:
        int generateNumber(int t_max, int t_min);
        gc::cell::State getRandomCellState(int t_criteriaForAlive);
        int calculateAliveNeighboursAtPosition(int t_positionX, int t_positonY);
        void changeForNextGeneration(Cell &t_cell, int t_positionX, int t_positonY);
        bool isBorder(int i, int j);

    private:
        sf::RenderWindow* m_window;
        Cell m_currentGeneration[gc::map::ROWS][gc::map::COLUMNS];
        Cell m_nextGeneration[gc::map::ROWS][gc::map::COLUMNS];
};
