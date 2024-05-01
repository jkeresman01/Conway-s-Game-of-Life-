#pragma once
#include "Cell.h"
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map{
    private:
        sf::RenderWindow* window;
        Cell cells[GK::MAP::ROWS][GK::MAP::COLUMNS];

    private:
        void change_next_generation(Cell &cell);
        void create_map();

    public:
        Map(sf::RenderWindow* window);
        void draw();
        void update();
};
