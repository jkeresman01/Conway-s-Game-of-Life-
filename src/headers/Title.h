#pragma once

#include <filesystem>
#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

namespace gol
{

class Title
{
  public:
    Title() = default;

    void create(sf::RenderWindow *window, const std::string &text,
                const std::filesystem::path &path);

    void draw();

    void setWindow(sf::RenderWindow *window);

  private:
    void initText(const std::filesystem::path &path, const std::string &text);

    void loadFont(const std::filesystem::path &path);

    void setDefaultSettings(const std::string &text);

  private:
    sf::RenderWindow *m_window;
    sf::Font m_font;
    sf::Text m_text;
};

} // namespace gol
