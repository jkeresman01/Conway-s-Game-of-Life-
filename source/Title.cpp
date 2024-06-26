#include "headers/Title.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

void Title::create(sf::RenderWindow *t_window,
                   const std::string &t_text,
                   const std::filesystem::path &t_path)
{

    m_window = t_window;

    initText(t_path, t_text);
}

void Title::initText(const std::filesystem::path &t_path,
                     const std::string &t_text)
{
    loadFont(t_path);

    m_text.setString(t_text);
    m_text.setFillColor(sf::Color(250, 191, 106));
    m_text.setPosition(gc::title::POSITION_X, gc::title::POSITION_Y);
    m_text.setCharacterSize(gc::title::FONT_SIZE);
}

void Title::loadFont(const std::filesystem::path &t_path)
{
    if(!m_font.loadFromFile(t_path))
    {
        LOG_ERROR("Failed to load font from " << t_path << "!");
    }

    m_text.setFont(m_font);
}

void Title::draw()
{
    m_window->draw(m_text);
}
