#pragma once

#include <filesystem>
#include <string>
#include <utility>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>

namespace gol
{

class Button
{
  public:
    explicit Button(const std::filesystem::path &filepath);

    void render(sf::RenderWindow &window) const;

    bool isPressed(sf::RenderWindow &window);
    void move(float positionX, float positionY);

    void setScale(float scale);

  private:
    sf::Sprite m_button;
    float m_scale;

    const uint32_t POSITION_X = 1260;
    const uint32_t POSITION_Y = 40;

    const float INCREASE_FACTOR = 1.1f;
    const float SCALE = 1.2f;
};

} // namespace gol
