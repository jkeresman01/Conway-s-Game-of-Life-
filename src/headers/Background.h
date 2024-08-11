#pragma once

#include <filesystem>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace gol
{

class Background
{
  public:
    explicit Background(const std::filesystem::path &filepath);

    void render(sf::RenderWindow &window) const;

  private:
    void loadTexture(const std::filesystem::path &filepath);

  private:
    sf::Sprite m_background;
    sf::Texture m_texture;
};

} // namespace gol
