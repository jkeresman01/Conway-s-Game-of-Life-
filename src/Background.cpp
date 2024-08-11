#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

Background::Background(const std::filesystem::path &filepath)
{
    loadTexture(filepath);
}

void Background::render(sf::RenderWindow &window) const
{
    window.draw(m_background);
}

void Background::loadTexture(const std::filesystem::path &path)
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

} // namespace gol
