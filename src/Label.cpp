#include "headers/Label.h"

#include "headers/GameConstants.h"
#include "headers/ResourceManager.h"

namespace gol
{

Label::Label(const std::string &text, const std::filesystem::path &filepath)
{
    m_text.setString(text);
    m_text.setFillColor(sf::Color(250, 191, 106));
    m_text.setPosition(title::POSITION_X, title::POSITION_Y);
    m_text.setCharacterSize(title::FONT_SIZE);
    m_text.setFont(ResourceManager::Instance().getFont(filepath));
}

void Label::render(sf::RenderWindow &window) const
{
    window.draw(m_text);
}

} // namespace gol
