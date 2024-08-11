#include "headers/Button.h"

#include <utility>

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

Button::Button(const std::filesystem::path &path)
{
    loadTexture(path);
    setStartPosition();
    setScale(button::SCALE);
}

void Button::setStartPosition()
{
    m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);
    m_button.setPosition(button::POSITION_X, button::POSITION_Y);
}

void Button::render(sf::RenderWindow &window) const
{
    window.draw(m_button);
}

void Button::move(float positionX, float positionY)
{
    m_button.move(positionX, positionY);
}

void Button::setScale(float scale)
{
    m_scale = scale;
    m_button.setScale(m_scale, m_scale);
}

void Button::loadTexture(const std::filesystem::path &path)
{
    bool isTextureLoadedSuccessfully = m_texture.loadFromFile(path.string());

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from " << path.string() << "!")
        return;
    }

    m_button.setTexture(m_texture);
    m_texture.setSmooth(true);
}

std::pair<uint32_t, uint32_t> Button::getPosition() const
{
    return std::make_pair(m_button.getPosition().x, m_button.getPosition().y);
}

bool Button::isPressed(sf::RenderWindow &window)
{
    auto mousePosition = sf::Mouse::getPosition(window);
    auto translatedPosition = window.mapPixelToCoords(mousePosition);

    bool isMouseOnButton = m_button.getGlobalBounds().contains(translatedPosition);
    bool isMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    isMouseOnButton
        ? m_button.setScale(m_scale * button::INCREASE_FACTOR, m_scale * button::INCREASE_FACTOR)
        : m_button.setScale(m_scale, m_scale);

    return isMousePressed and isMouseOnButton;
}

} // namespace gol
