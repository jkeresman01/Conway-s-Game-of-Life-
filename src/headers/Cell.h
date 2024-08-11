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

    void render(sf::RenderWindow &window) const;
    bool isAlive() const;

    void setPosition(float position_x, float position_y);
    void setState(cell::State state);

  private:
    sf::RectangleShape m_cell;
    cell::State m_state;
};

} // namespace gol
