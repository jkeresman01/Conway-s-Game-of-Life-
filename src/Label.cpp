#include "headers/Label.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

Label::Label(const std::string &text, const std::filesystem::path &filepath)
{
    loadFont(filepath);
    setInitSettings(text);
}

void Label::loadFont(const std::filesystem::path &filepath)
{
    bool isFontLoadedSuccessfully = m_font.loadFromFile(filepath);

    if (!isFontLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load font from " << filepath.string() << "!");
        return;
    }

    m_text.setFont(m_font);
}

void Label::setInitSettings(const std::string &text)
{
    m_text.setString(text);
    m_text.setFillColor(sf::Color(250, 191, 106));
    m_text.setPosition(title::POSITION_X, title::POSITION_Y);
    m_text.setCharacterSize(title::FONT_SIZE);
}

void Label::render(sf::RenderWindow &window) const
{
    window.draw(m_text);
}

} // namespace gol
