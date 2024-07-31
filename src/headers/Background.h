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
    Background() = default;

    void create(sf::RenderWindow *window,
                const std::filesystem::path &path);

    void draw();

    void setImage(const std::filesystem::path &path);
    void setWindow(sf::RenderWindow *window);

  private:
    void initBackground(sf::RenderWindow *window,
                        const std::filesystem::path &path);

  private:
    sf::RenderWindow *m_window;
    sf::Sprite m_background;
    sf::Texture m_texture;
};

} // namespace gol
