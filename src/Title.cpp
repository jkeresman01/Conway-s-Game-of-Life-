#include "headers/Title.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

void Title::create(sf::RenderWindow *window, const std::string &text,
                   const std::filesystem::path &path)
{
    initText(path, text);
    setWindow(window);
}

void Title::initText(const std::filesystem::path &path,
                     const std::string &text)
{
    loadFont(path);
    setDefaultSettings(text);
}

void Title::setDefaultSettings(const std::string &text)
{
    m_text.setString(text);
    m_text.setFillColor(sf::Color(250, 191, 106));
    m_text.setPosition(title::POSITION_X, title::POSITION_Y);
    m_text.setCharacterSize(title::FONT_SIZE);
}

void Title::loadFont(const std::filesystem::path &path)
{
    bool isFontLoadedSuccessfully = m_font.loadFromFile(path);

    if (!isFontLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load font from " << path << "!");
        return;
    }

    m_text.setFont(m_font);
}

void Title::draw()
{
    m_window->draw(m_text);
}

void Title::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

} // namespace gol
