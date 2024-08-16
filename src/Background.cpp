#include "headers/Background.h"

#include "headers/ResourceManager.h"

namespace gol
{

Background::Background(const std::filesystem::path &filepath)
{
    m_background.setTexture(ResourceManager::Instance().getTexture(filepath));
    m_background.setScale(SCALE_X, SCALE_Y);
}

void Background::render(sf::RenderWindow &window) const
{
    window.draw(m_background);
}

} // namespace gol
