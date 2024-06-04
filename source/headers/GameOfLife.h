#pragma once

#include "Background.h"
#include "Button.h"
#include "Title.h"
#include "Map.h"

#include <SFML/System/Clock.hpp>

class GameOfLife
{
    public:
        GameOfLife(sf::RenderWindow* t_window);
        void run();

    private:
        sf::RenderWindow* m_window;
        sf::Clock m_clock;
        gc::game::State m_state;
        Background m_background;
        Button m_reshuffleButton;
        Button m_closeButton;
        Button m_pauseButton;
        Button m_playButton;
        Title m_title;
        Map m_map;
};
