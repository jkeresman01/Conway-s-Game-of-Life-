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
    setImage(t_path);
    setWindow(t_window);
}

void Background::draw()
{
    m_window->draw(m_background);
}

void Background::setImage(const std::filesystem::path &t_path)
{
    bool isTextureLoadedSuccessfully = m_texture.loadFromFile(t_path.string());

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from " << t_path.string() << "!");
        return;
    }

    m_background.setTexture(m_texture);
    m_background.setScale(background::SCALE_X, background::SCALE_Y);
}

void Background::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

} // namespace gol
