#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/ResourceManager.h"

namespace gol
{

Background::Background(const std::filesystem::path &filepath)
{
    m_background.setTexture(ResourceManager::Instance().getTexture(filepath));
    m_background.setScale(background::SCALE_X, background::SCALE_Y);
}

void Background::render(sf::RenderWindow &window) const
{
    window.draw(m_background);
}

} // namespace gol
