#pragma once
#include "GameConstants.h"

#include <SFML/Graphics/RectangleShape.hpp>
class Map{
    private:
        sf::RectangleShape map[GK::MAP::ROWS][GK::MAP::COLUMNS];

    private:
        void update();

    public:
        void draw();
    
};
