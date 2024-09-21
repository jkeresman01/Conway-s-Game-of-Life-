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
    Label(const std::string &text);

    void render(sf::RenderWindow &window) const;

  private:
    sf::Text m_text;

    static constexpr uint32_t POSITION_X = 50;
    static constexpr uint32_t POSITION_Y = 10;

    static constexpr uint32_t FONT_SIZE = 66;
};

} // namespace gol
