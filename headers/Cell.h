#pragma once
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Cell{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape shape;
        bool is_alive;

    private:
        int generate_number(int max, int min);

    public:
        Cell();
        Cell(sf::RenderWindow *window);
        void draw();
        void set_position(float x, float y);
        void set_state(GK::CELL::CellState cell_state);

};
