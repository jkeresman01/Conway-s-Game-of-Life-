#include "headers/GameOfLife.h"

#include <ctime>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "headers/Background.h"
#include "headers/Button.h"
#include "headers/Title.h"

GameOfLife::GameOfLife()
    : m_window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), "", sf::Style::None),
    m_state(gc::game::RUNNING)
{
    m_window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));

    m_background.create(&m_window, "resources/images/background.jpg");

    m_map.create(&m_window);
    m_map.reshuffle();

    m_title.create(&m_window, "Conway's Game of Life", "resources/fonts/FloppyDisk.ttf");

    m_closeButton.create(&m_window, "resources/icons/close.png");
    m_closeButton.setScale(0.5f);
    m_closeButton.move(0, -20);

    m_reshuffleButton.create(&m_window,  "resources/icons/restart.png");
    m_reshuffleButton.move(-50, gc::title::POSITION_Y);

    m_pauseButton.create(&m_window, "resources/icons/pause.png");
    m_pauseButton.move(-100, gc::title::POSITION_Y);

    m_playButton.create(&m_window, "resources/icons/play.png");
    m_playButton.move(-150, gc::title::POSITION_Y);

    srand(time(nullptr));
}

void GameOfLife::run()
{
    while (m_window.isOpen()) 
    {
        sf::Event event;

        while (m_window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed or m_closeButton.isPressed())
            {
                m_window.close();
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

        }

        if(m_state == gc::game::RESHUFFLED)
        {
            m_map.reshuffle();
            m_state = gc::game::RUNNING;
        }

        if(m_clock.getElapsedTime().asSeconds() > gc::game::REFRESH_TIME_SECONDS and m_state != gc::game::PAUSED)
        {
            m_map.update();
            m_clock.restart();
        }

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
}
