#include "headers/Title.h"
#include "headers/GameConstants.h"

Title::Title()
{
}

void Title::create(sf::RenderWindow* t_window, const std::string t_text, const std::string t_path)
{
    m_window = t_window;
    m_font.loadFromFile(t_path);
    m_text.setString(t_text);
    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color(250, 191, 106));
    m_text.setPosition(gc::title::POSITION_X, gc::title::POSITION_Y);
    m_text.setCharacterSize(gc::title::FONT_SIZE);
}

void Title::draw()
{
    m_window->draw(m_text);
}
