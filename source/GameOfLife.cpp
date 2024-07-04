#include "headers/GameOfLife.h"

#include <SFML/Window/Event.hpp>

namespace gol
{

GameOfLife::GameOfLife()
    : m_window(sf::VideoMode(screen::WIDTH, screen::HEIGHT), "", sf::Style::None),
    m_state(game::RUNNING)
{
    m_window.setPosition(sf::Vector2i(screen::POSITION_X, screen::POSITION_Y));

    m_background.create(&m_window, "resources/images/background.jpg");

    m_map.create(&m_window);
    m_map.reshuffle();

    m_title.create(&m_window, "Conway's Game of Life", "resources/fonts/FloppyDisk.ttf");

    m_closeButton.create(&m_window, "resources/icons/close.png");
    m_closeButton.setScale(0.5f);
    m_closeButton.move(0, -20);

    m_reshuffleButton.create(&m_window,  "resources/icons/restart.png");
    m_reshuffleButton.move(-50, title::POSITION_Y);

    m_pauseButton.create(&m_window, "resources/icons/pause.png");
    m_pauseButton.move(-100, title::POSITION_Y);

    m_playButton.create(&m_window, "resources/icons/play.png");
    m_playButton.move(-150, title::POSITION_Y);
}

void GameOfLife::run()
{
    while (m_window.isOpen()) 
    {
        pollEvents();
        updateState();
        drawGame();
    }
}

void GameOfLife::pollEvents()
{
    sf::Event event;

    while (m_window.pollEvent(event)) 
    {
        if ( m_closeButton.isPressed() or event.type == sf::Event::Closed)
        {
            m_window.close();
        }

        if(m_reshuffleButton.isPressed())
        {
            m_state = game::State::RESHUFFLED;
        }

        if(m_pauseButton.isPressed())
        {
            m_state = game::State::PAUSED;
        }

        if(m_playButton.isPressed())
        {
            m_state = game::State::RUNNING;
        }

    }
}

void GameOfLife::updateState()
{
    if(m_state == game::State::RESHUFFLED)
    {
        m_map.reshuffle();
        m_state = game::State::RUNNING;
    }

    if(m_clock.getElapsedTime().asSeconds() > game::REFRESH_TIME_SECONDS and m_state != game::PAUSED)
    {
        m_map.update();
        m_clock.restart();
    }
}

void GameOfLife::drawGame()
{
    m_window.clear();
    m_background.draw();
    m_reshuffleButton.draw();
    m_closeButton.draw();
    m_pauseButton.draw();
    m_playButton.draw();
    m_title.draw();
    m_map.draw();
    m_window.display();
}
    
} // gol
