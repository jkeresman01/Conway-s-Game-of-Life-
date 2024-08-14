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
};

} // namespace gol
