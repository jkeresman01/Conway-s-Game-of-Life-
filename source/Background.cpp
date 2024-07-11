#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

void Background::create(sf::RenderWindow *t_window,
                        const std::filesystem::path &t_path)
{
    initBackground(t_window, t_path);
}

void Background::initBackground(sf::RenderWindow *t_window,
                                const std::filesystem::path &t_path)
{
    m_window = t_window;

    setImage(t_path);
}

void Background::draw()
{
    m_window->draw(m_backgound);
}

void Background::setImage(const std::filesystem::path &t_path)
{
    loadTexture(t_path);

    m_backgound.setScale(background::SCALE_X, background::SCALE_Y);
}
    
void Background::loadTexture(const std::filesystem::path &t_path)
{
    if(!m_texture.loadFromFile(t_path.string()))
    {
        LOG_ERROR("Failed to load texture from " << t_path.string() << "!");
    }

    m_backgound.setTexture(m_texture);
}
    
} // gol
