#include "headers/Label.h"

#include "headers/Colors.h"
#include "headers/Fonts.h"
#include "headers/ResourceManager.h"

namespace gol
{

Label::Label(const std::string &text)
{
    m_text.setString(text);
    m_text.setPosition(POSITION_X, POSITION_Y);
    m_text.setCharacterSize(FONT_SIZE);
    m_text.setFont(ResourceManager::Instance().getFont(fonts::FloppyDisk));
    m_text.setFillColor(colors::Brown);
}

void Label::render(sf::RenderWindow &window) const
{
    window.draw(m_text);
}

} // namespace gol
