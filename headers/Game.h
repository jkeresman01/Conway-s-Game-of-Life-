#pragma once

#include "Map.h"
#include <SFML/System/Clock.hpp>

class Game{
    private:
        Map map;
        gc::GAME::STATE state;
        sf::Clock timer;

    public:
        void start();
};
