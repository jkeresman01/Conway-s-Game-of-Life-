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

    void create(sf::RenderWindow *t_window, const std::filesystem::path &t_path);

    void draw();

    void setImage(const std::filesystem::path &t_path);
    void setWindow(sf::RenderWindow *t_window);

  private:
    void initBackground(sf::RenderWindow *t_window, const std::filesystem::path &t_path);

  private:
    sf::RenderWindow *m_window;
    sf::Sprite m_background;
    sf::Texture m_texture;
};

} // namespace gol
