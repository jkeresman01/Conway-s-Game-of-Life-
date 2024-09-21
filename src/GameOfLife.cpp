#include "headers/GameOfLife.h"
#include "headers/Textures.h"

#include <SFML/Window/Event.hpp>

namespace gol
{

GameOfLife::GameOfLife()
    : m_window(sf::VideoMode(SCREEN_WIDTH, SCREE_HEIGHT), "", sf::Style::None),
      m_background(textures::Background), m_title("Conway's Game of Life"),
      m_closeButton(textures::CloseButton), m_playButton(textures::PlayButton),
      m_pauseButton(textures::PauseButton), m_reshuffleButton(textures::ReshuffleButton),
      m_state(RESHUFFLED)
{

    m_window.setPosition(sf::Vector2i(POSITION_X, POSITION_Y));

    m_closeButton.setScale(0.5f);
    m_closeButton.move(0, -20);
    m_playButton.move(-150, 10);
    m_pauseButton.move(-100, 10);
    m_reshuffleButton.move(-50, 10);
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
        m_state = RESHUFFLED;
    }

    if (m_pauseButton.isPressed(m_window))
    {
        m_state = PAUSED;
    }

    if (m_playButton.isPressed(m_window))
    {
        m_state = RUNNING;
    }
}

void GameOfLife::update()
{
    if (m_clock.getElapsedTime().asSeconds() > REFRESH_TIME_SECONDS and m_state != PAUSED)
    {
        m_map.update();
        m_clock.restart();
    }

    if (m_state == RESHUFFLED)
    {
        m_map.reshuffle();
        m_state = RUNNING;
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
