#pragma once

#include "Background.h"
#include "Button.h"
#include "Title.h"
#include "Map.h"

#include <SFML/System/Clock.hpp>

class GameOfLife{
    private:
        sf::RenderWindow* window;
        sf::Clock clock;
        gc::GAME::STATE state;
        Background background;
        Button reshuffle_button;
        Button close_button;
        Button pause_button;
        Button play_button;
        Title title;
        Map map;

    public:
        GameOfLife(sf::RenderWindow* window);
        void start();
};
