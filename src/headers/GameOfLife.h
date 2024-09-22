#pragma once

#include "Background.h"
#include "Button.h"
#include "Label.h"
#include "Map.h"
#include "ResourceManager.h"

#include <SFML/System/Clock.hpp>

namespace gol
{

enum GameState
{
    PAUSED = 0,
    RUNNING = 1,
    RESHUFFLED = 2,
};

class GameOfLife
{
  public:
    GameOfLife();

    void run();

  private:
    void processEvents();
    void update();
    void render();

  private:
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    Background m_background;
    Button m_reshuffleButton;
    Button m_closeButton;
    Button m_pauseButton;
    Button m_playButton;
    Label m_title;
    Map m_map;
    GameState m_state;

    static const uint32_t SCREEN_WIDTH = 1280;
    static const uint32_t SCREE_HEIGHT = 720;

    const uint32_t POSITION_X = 300;
    const uint32_t POSITION_Y = 200;

    const float REFRESH_TIME_SECONDS = 2.0f;
};

} // namespace gol
