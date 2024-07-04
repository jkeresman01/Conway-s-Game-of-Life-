#pragma once

#include "Background.h"
#include "Button.h"
#include "Title.h"
#include "Map.h"

#include <SFML/System/Clock.hpp>

namespace gol
{

class GameOfLife
{
    public:
        GameOfLife();

        void run();

    private:
        void pollEvents();
        void updateState();
        void drawGame();

    private:
        sf::RenderWindow m_window;
        sf::Clock m_clock;

        Background m_background;
        Button m_reshuffleButton;
        Button m_closeButton;
        Button m_pauseButton;
        Button m_playButton;
        Title m_title;
        Map m_map;

        game::State m_state;
};
    
}// gol
