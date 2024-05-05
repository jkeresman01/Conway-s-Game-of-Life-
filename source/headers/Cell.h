#pragma once
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Cell{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape shape;
        gc::CELL::STATE cell_state;

    public:
        Cell();
        void set_window(sf::RenderWindow* window);
        void draw();
        void set_position(float x, float y);
        void set_state(gc::CELL::STATE cell_state);
        bool is_alive();
};
