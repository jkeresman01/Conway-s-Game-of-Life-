#pragma once

#include <filesystem>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace gol
{

class Background
{
  public:
    explicit Background(const std::filesystem::path &filepath);

    void render(sf::RenderWindow &window) const;

  private:
    sf::Sprite m_background;
};

} // namespace gol
