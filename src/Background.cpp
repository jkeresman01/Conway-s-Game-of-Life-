#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

void Background::create(sf::RenderWindow *window,
                        const std::filesystem::path &path)
{
    initBackground(window, path);
}

void Background::initBackground(sf::RenderWindow *window,
                                const std::filesystem::path &path)
{
    setImage(path);
    setWindow(window);
}

void Background::draw()
{
    m_window->draw(m_background);
}

void Background::setImage(const std::filesystem::path &path)
{
    bool isTextureLoadedSuccessfully = m_texture.loadFromFile(path.string());

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from " << path.string() << "!");
        return;
    }

    m_background.setTexture(m_texture);
    m_background.setScale(background::SCALE_X, background::SCALE_Y);
}

void Background::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

} // namespace gol
