#pragma once

#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Cell
{
    public:
        Cell();
        void draw();
        bool isAlive() const;
        void setPosition(const float t_position_x, const float t_position_y);
        void setState(const gc::cell::State t_state);
        void setWindow(sf::RenderWindow* t_window);

    private:
        sf::RenderWindow* m_window;
        sf::RectangleShape m_cell;
        gc::cell::State m_state;
};
