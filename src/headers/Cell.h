#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameConstants.h"

namespace gol
{

class Cell
{
  public:
    Cell();

    void draw();

    bool isAlive() const;

    void setPosition(float position_x, float position_y);
    void setState(cell::State state);
    void setWindow(sf::RenderWindow *window);

    std::pair<uint32_t, uint32_t> getPosition();

  private:
    sf::RenderWindow *m_window;
    sf::RectangleShape m_cell;

    cell::State m_state;
};

} // namespace gol
