#pragma once

#include "Background.h"
#include "Button.h"
#include "Map.h"
#include "Title.h"
#include <SFML/System/Clock.hpp>

class GameOfLife{
    private:
        sf::RenderWindow* window;
        gc::GAME::STATE state;
        sf::Clock timer;

    public:
        GameOfLife(sf::RenderWindow* window);
        void start();
};
