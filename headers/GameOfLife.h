#pragma once

#include "Background.h"
#include "Button.h"
#include "Map.h"
#include "Title.h"
#include <SFML/System/Clock.hpp>

class GameOfLife{
    private:
        sf::RenderWindow* window;
        sf::Clock timer;
        gc::GAME::STATE state;
        Background background;
        Button restart_button;
        Button close_button;
        Button pause_button;
        Button play_button;
        Title title;
        Map map;
        int generation_change_counter;

    public:
        GameOfLife(sf::RenderWindow* window);
        void start();
};
