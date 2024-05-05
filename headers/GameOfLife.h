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
        Button restart_button;
        Button close_button;
        Button pause_button;
        Button play_button;
        Background background;
        Title title;
        Map map;

    public:
        GameOfLife(sf::RenderWindow* window);
        void start();
};
