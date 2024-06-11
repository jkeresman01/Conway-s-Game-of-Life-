#include "headers/Background.h"
#include "headers/GameConstants.h"

#include <iostream>

Background::Background()
{
}

void Background::create(sf::RenderWindow* t_window, const std::string t_path)
{
    m_path = t_path;

    if(m_image.loadFromFile(m_path))
    {
        std::cerr << "Can't load image from " << m_path << "\n";
    }

    m_window = t_window;
    m_backgound.setTexture(m_image);
    m_backgound.setScale(gc::background::SCALE_X, gc::background::SCALE_Y);
}

void Background::draw()
{
    m_window->draw(m_backgound);
}


