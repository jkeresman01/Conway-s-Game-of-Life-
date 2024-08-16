#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace gol
{

enum class State
{
    DEAD  = 0,
    ALIVE = 1,
};

class Cell
{
  public:
    Cell();

    void render(sf::RenderWindow &window) const;

    void setPosition(float position_x, float position_y);
    void setState(State state);

    bool isAlive() const { return m_state == State::ALIVE; }

    float getWidth() const { return m_height; }
    float getHeight() const { return m_height; }
    State getState() const { return m_state; }
    sf::Vector2f getPosition() const { return m_position; };

  private:
    sf::RectangleShape m_cell;
    State m_state;
    sf::Vector2f m_position;
    float m_height = 10.0f;
    float m_width  = 10.0f;

    const float ORIGIN_X = 5.0f;
    const float ORIGIN_Y = 5.0f;

    const float START_POSITION_X = 45.0f;
    const float START_POSITION_Y = 100.0f;

    const float OUTLINE_THICKNESS = 0.5f;
};

} // namespace gol
