#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameConstants.h"

class Cell
{
    public:
        Cell();

        void draw();

        bool isAlive() const;

        void setPosition(float t_position_x, float t_position_y);
        void setState(gc::cell::State t_state);
        void setWindow(sf::RenderWindow* t_window);

    private:
        sf::RenderWindow *m_window;
        sf::RectangleShape m_cell;

        gc::cell::State m_state;
};
