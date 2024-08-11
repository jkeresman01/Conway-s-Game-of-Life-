#include "headers/GameOfLife.h"

#include <SFML/Window/Event.hpp>

namespace gol
{

GameOfLife::GameOfLife()
    : m_window(sf::VideoMode(screen::WIDTH, screen::HEIGHT), "", sf::Style::None),
      m_background("resources/images/background.jpg"),
      m_title("Conway's Game of Life", "resources/fonts/FloppyDisk.ttf"),
      m_closeButton("resources/icons/close.png"), m_playButton("resources/icons/play.png"),
      m_pauseButton("resources/icons/pause.png"), m_reshuffleButton("resources/icons/restart.png"),
      m_state(game::RESHUFFLED)
{

    m_window.setPosition(sf::Vector2i(screen::POSITION_X, screen::POSITION_Y));

    m_closeButton.setScale(0.5f);
    m_closeButton.move(0, -20);
    m_playButton.move(-150, title::POSITION_Y);
    m_pauseButton.move(-100, title::POSITION_Y);
    m_reshuffleButton.move(-50, title::POSITION_Y);
}

void GameOfLife::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void GameOfLife::processEvents()
{
    sf::Event event;

    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed or m_closeButton.isPressed(m_window))
        {
            m_window.close();
        }
    }

    if (m_reshuffleButton.isPressed(m_window))
    {
        m_state = game::State::RESHUFFLED;
    }

    if (m_pauseButton.isPressed(m_window))
    {
        m_state = game::State::PAUSED;
    }

    if (m_playButton.isPressed(m_window))
    {
        m_state = game::State::RUNNING;
    }
}

void GameOfLife::update()
{
    if (m_clock.getElapsedTime().asSeconds() > game::REFRESH_TIME_SECONDS and
        m_state != game::PAUSED)
    {
        m_map.update();
        m_clock.restart();
    }

    if (m_state == game::RESHUFFLED)
    {
        m_map.reshuffle();
        m_state = game::RUNNING;
    }
}

void GameOfLife::render()
{
    m_window.clear();
    m_background.render(m_window);
    m_reshuffleButton.render(m_window);
    m_closeButton.render(m_window);
    m_pauseButton.render(m_window);
    m_playButton.render(m_window);
    m_title.render(m_window);
    m_map.render(m_window);
    m_window.display();
}

} // namespace gol
