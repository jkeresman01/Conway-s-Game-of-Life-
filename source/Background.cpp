#include "headers/Background.h"
#include "headers/GameConstants.h"
#include "headers/Logger.h"

void Background::create(sf::RenderWindow* t_window, const std::string &t_path)
{
    if(!m_image.loadFromFile(t_path))
    {
        LOG_ERROR("ERROR: Image can't be loaded from " << t_path << "!");
    }

    m_window = t_window;
    m_backgound.setTexture(m_image);
    m_backgound.setScale(gc::background::SCALE_X, gc::background::SCALE_Y);
}

void Background::draw()
{
    m_window->draw(m_backgound);
}


