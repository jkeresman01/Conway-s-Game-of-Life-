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
    Button() = default;

    void create(sf::RenderWindow *window, const std::filesystem::path &path);

    void draw();

    void move(float positionX, float positionY);

    bool isPressed();

    void setScale(float scale);
    void setTexture(const std::filesystem::path &path);
    void setWindow(sf::RenderWindow *window);

    std::pair<uint32_t, uint32_t> getPosition();

  private:
    void initButton(const std::filesystem::path &path);

    void loadTexture(const std::filesystem::path &path);
    void setStartPosition();

  private:
    sf::RenderWindow *m_window;
    sf::Texture m_texture;
    sf::Sprite m_button;

    float m_scaleFactor;
};

} // namespace gol
