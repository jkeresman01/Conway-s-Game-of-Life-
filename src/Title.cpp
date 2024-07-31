#include "headers/Title.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

void Title::create(sf::RenderWindow *t_window, const std::string &t_text,
                   const std::filesystem::path &t_path)
{
    initText(t_path, t_text);
    setWindow(t_window);
}

void Title::initText(const std::filesystem::path &t_path,
                     const std::string &t_text)
{
    loadFont(t_path);
    setDefaultSettings(t_text);
}

void Title::setDefaultSettings(const std::string &t_text)
{
    m_text.setString(t_text);
    m_text.setFillColor(sf::Color(250, 191, 106));
    m_text.setPosition(title::POSITION_X, title::POSITION_Y);
    m_text.setCharacterSize(title::FONT_SIZE);
}

void Title::loadFont(const std::filesystem::path &t_path)
{
    bool isFontLoadedSuccessfully = m_font.loadFromFile(t_path);

    if (!isFontLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load font from " << t_path << "!");
        return;
    }

    m_text.setFont(m_font);
}

void Title::draw()
{
    m_window->draw(m_text);
}

void Title::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

} // namespace gol
