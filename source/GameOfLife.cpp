#include "headers/GameOfLife.h"
#include "headers/Background.h"
#include "headers/Button.h"
#include "headers/Title.h"

#include <SFML/Window/Event.hpp>

GameOfLife::GameOfLife(sf::RenderWindow* t_window)
{
    m_window = t_window;
    m_background.create(t_window, "./resources/images/background.jpg");
    m_map.create(t_window);
    m_title.create(t_window, "Conway's Game of Life", "./resources/fonts/FloppyDisk.ttf");
    m_closeButton.create(t_window, "./resources/icons/close.png");
    m_closeButton.setScale(0.5f);
    m_closeButton.move(0, -20);
    m_reshuffleButton.create(t_window,  "./resources/icons/restart.png");
    m_reshuffleButton.move(-50, gc::title::POSITION_Y);
    m_pauseButton.create(t_window, "./resources/icons/pause.png");
    m_pauseButton.move(-100, gc::title::POSITION_Y);
    m_playButton.create(t_window, "./resources/icons/play.png");
    m_playButton.move(-150, gc::title::POSITION_Y);
    m_state = gc::game::State::RUNNING;
}

void GameOfLife::run()
{
    while (m_window->isOpen()) 
    {
        sf::Event event;
        while (m_window->pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed or m_closeButton.isPressed())
            {
                m_window->close();
            }
        }

        if(m_state == gc::game::RESHUFFLED)
        {
            m_map.initializeCells(gc::map::CRITERIA_20_PERCENT_ALIVE_CELLS);
            m_state = gc::game::RUNNING;
        }

        if(m_clock.getElapsedTime().asSeconds() > gc::game::REFRESH_TIME_SECONDS and m_state != gc::game::PAUSED)
        {
            m_map.update();
            m_clock.restart();
        }

        if(m_reshuffleButton.isPressed())
        {
            m_state = gc::game::RESHUFFLED;
        }

        if(m_pauseButton.isPressed())
        {
            m_state = gc::game::PAUSED;
        }

        if(m_playButton.isPressed())
        {
            m_state = gc::game::RUNNING;
        }

        m_window->clear();
        m_background.draw();
        m_reshuffleButton.draw();
        m_closeButton.draw();
        m_pauseButton.draw();
        m_playButton.draw();
        m_title.draw();
        m_map.draw();
        m_window->display();
    }
}
