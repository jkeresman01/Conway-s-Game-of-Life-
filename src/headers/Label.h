#pragma once

#include <filesystem>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

namespace gol
{

class Label
{
  public:
    Label(const std::string &text, const std::filesystem::path &filepath);

    void render(sf::RenderWindow &window) const;

  private:
    sf::Text m_text;

    const uint32_t POSITION_X = 50;
    const uint32_t POSITION_Y = 10;

    const uint32_t FONT_SIZE = 66;
};

} // namespace gol
