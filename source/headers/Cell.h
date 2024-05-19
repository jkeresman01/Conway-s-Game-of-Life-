#pragma once
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Cell{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape cell;
        gc::CELL::STATE state;

    public:
        Cell();
        void draw();
        void set_window(sf::RenderWindow* window);
        void set_position(float position_x, float position_y);
        void set_state(gc::CELL::STATE state);
        bool is_alive();
};
