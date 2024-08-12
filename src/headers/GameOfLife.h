#pragma once

#include "Background.h"
#include "Button.h"
#include "Label.h"
#include "Map.h"
#include "ResourceManager.h"

#include <SFML/System/Clock.hpp>

namespace gol
{

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
    ResourceManager m_resourceManager;

    game::State m_state;
};

} // namespace gol
