#include "headers/Button.h"

#include "headers/ResourceManager.h"

namespace gol
{

Button::Button(const std::filesystem::path &filepath)
{
    m_button.setTexture(ResourceManager::Instance().getTexture(filepath));
    m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);
    m_button.setPosition(POSITION_X, POSITION_Y);

    setScale(SCALE);
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

bool Button::isPressed(sf::RenderWindow &window)
{
    auto mousePosition = sf::Mouse::getPosition(window);
    auto translatedPosition = window.mapPixelToCoords(mousePosition);

    bool isMouseOnButton = m_button.getGlobalBounds().contains(translatedPosition);
    bool isMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    isMouseOnButton ? m_button.setScale(m_scale * INCREASE_FACTOR, m_scale * INCREASE_FACTOR)
                    : m_button.setScale(m_scale, m_scale);

    return isMousePressed and isMouseOnButton;
}

} // namespace gol
