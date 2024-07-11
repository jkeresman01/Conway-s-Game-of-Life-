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
        void initGameOfLife();

        void initBackgound();
        void initWindow();
        void initMap();
        void initButtons();
        void initTitle();

        void initCloseButton();
        void initPauseButton();
        void initPlayButton();
        void initReshuffleButton();

        void pollEvents();
        void updateState();
        void drawGame();

        void checkIfCloseButtonIsPressed(const sf::Event &t_event);

        void checkIfResfuffleButtonIsPressed();
        void checkIfPauseButtonIsPressed();
        void checkIfPlayButtonIsPressed();

        void reshuffleMap();
        void updateMap();

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
    
} // gol
