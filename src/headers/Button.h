#pragma once

#include <filesystem>
#include <string>
#include <utility>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Mouse.hpp>

namespace gol
{

class Button
{
  public:
    explicit Button(const std::filesystem::path &filepath);

    void render(sf::RenderWindow &window) const;

    void move(float positionX, float positionY);
    bool isPressed(sf::RenderWindow &window);

    void setScale(float scale);

  private:
    void loadTexture(const std::filesystem::path &path);
    void setStartPosition();

  private:
    sf::Texture m_texture;
    sf::Sprite m_button;
    float m_scale;
};

} // namespace gol
