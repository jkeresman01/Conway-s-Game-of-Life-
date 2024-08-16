#include "headers/Label.h"

#include "headers/ResourceManager.h"

namespace gol
{

Label::Label(const std::string &text, const std::filesystem::path &filepath)
{
    m_text.setString(text);
    m_text.setPosition(POSITION_X, POSITION_Y);
    m_text.setCharacterSize(FONT_SIZE);
    m_text.setFont(ResourceManager::Instance().getFont(filepath));
    m_text.setFillColor(sf::Color(250, 191, 106));
}

void Label::render(sf::RenderWindow &window) const
{
    window.draw(m_text);
}

} // namespace gol
