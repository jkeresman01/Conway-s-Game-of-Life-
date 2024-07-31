#pragma once

#include "Background.h"
#include "Button.h"
#include "Map.h"
#include "Title.h"

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

    void checkButtonState(const sf::Event &event);

    void checkIfCloseButtonIsPressed(const sf::Event &event);

    void checkIfResfuffleButtonIsPressed();
    void checkIfPauseButtonIsPressed();
    void checkIfPlayButtonIsPressed();

    void reshuffleMap();
    void updateMap();

    void pollEvents();
    void updateState();
    void draw();

    void clearScreen();
    void drawEntities();
    void displayEntities();

    bool isMapUpdateTime();

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

} // namespace gol
