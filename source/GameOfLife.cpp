#include "headers/GameOfLife.h"

#include <SFML/Window/Event.hpp>

namespace gol
{

GameOfLife::GameOfLife()
    : m_window(sf::VideoMode(screen::WIDTH, screen::HEIGHT), "", sf::Style::None),
    m_state(game::RUNNING)
{
    initGameOfLife();
}

void GameOfLife::initGameOfLife()
{
   initWindow(); 
   initBackgound();
   initTitle();
   initButtons();
   initMap();
}

void GameOfLife::initWindow()
{
    m_window.setPosition(sf::Vector2i(screen::POSITION_X, screen::POSITION_Y));
}

void GameOfLife::initBackgound()
{
    m_background.create(&m_window, "resources/images/background.jpg");
}

void GameOfLife::initMap()
{
    m_map.create(&m_window);
    m_map.reshuffle();
}

void GameOfLife::initTitle()
{
    m_title.create(&m_window, "Conway's Game of Life", "resources/fonts/FloppyDisk.ttf");
}

void GameOfLife::initButtons()
{
    initCloseButton();
    initPauseButton();
    initPlayButton();
    initReshuffleButton();
}

void GameOfLife::initCloseButton()
{
    m_closeButton.create(&m_window, "resources/icons/close.png");
    m_closeButton.setScale(0.5f);
    m_closeButton.move(0, -20);
}

void GameOfLife::initPauseButton()
{
    m_pauseButton.create(&m_window, "resources/icons/pause.png");
    m_pauseButton.move(-100, title::POSITION_Y);
}

void GameOfLife::initPlayButton()
{
    m_playButton.create(&m_window, "resources/icons/play.png");
    m_playButton.move(-150, title::POSITION_Y);
}

void GameOfLife::initReshuffleButton()
{
    m_reshuffleButton.create(&m_window, "resources/icons/restart.png");
    m_reshuffleButton.move(-50, title::POSITION_Y);
}

void GameOfLife::run()
{
    while (m_window.isOpen()) 
    {
        pollEvents();
        updateState();
        draw();
    }
}

void GameOfLife::pollEvents()
{
    sf::Event event;

    while (m_window.pollEvent(event)) 
    {
        checkButtonState(event);
    }
}

void GameOfLife::checkButtonState(const sf::Event &t_event)
{
    checkIfCloseButtonIsPressed(t_event);

    checkIfPlayButtonIsPressed();
    checkIfPauseButtonIsPressed();
    checkIfResfuffleButtonIsPressed();
}

void GameOfLife::checkIfCloseButtonIsPressed(const sf::Event &t_event)
{
    if (m_closeButton.isPressed() or t_event.type == sf::Event::Closed)
    {
        m_window.close();
    }
}

void GameOfLife::checkIfResfuffleButtonIsPressed()
{
    if(m_reshuffleButton.isPressed())
    {
        m_state = game::State::RESHUFFLED;
    }
}

void GameOfLife::checkIfPauseButtonIsPressed()
{
    if(m_pauseButton.isPressed())
    {
        m_state = game::State::PAUSED;
    }
}

void GameOfLife::checkIfPlayButtonIsPressed()
{
    if(m_playButton.isPressed())
    {
        m_state = game::State::RUNNING;
    }
}

void GameOfLife::updateState()
{
    reshuffleMap();
    updateMap();
}

void GameOfLife::reshuffleMap()
{
    if(m_state == game::State::RESHUFFLED)
    {
        m_map.reshuffle();
        m_state = game::State::RUNNING;
    }
}

void GameOfLife::updateMap()
{
    if(isMapUpdateTime())
    {
        m_map.update();
        m_clock.restart();
    }
}

bool GameOfLife::isMapUpdateTime()
{
    return m_clock.getElapsedTime().asSeconds() > game::REFRESH_TIME_SECONDS and
           m_state != game::PAUSED;
}

void GameOfLife::draw()
{
    clearScreen();
    drawEntities();
    displayEntities();
}

void GameOfLife::clearScreen()
{
    m_window.clear();
}

void GameOfLife::drawEntities()
{
    m_background.draw();
    m_reshuffleButton.draw();
    m_closeButton.draw();
    m_pauseButton.draw();
    m_playButton.draw();
    m_title.draw();
    m_map.draw();
}

void GameOfLife::displayEntities()
{
    m_window.display();
}
    
} // gol
