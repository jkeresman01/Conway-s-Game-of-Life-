#include "headers/Button.h"

#include <utility>

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

void Button::create(sf::RenderWindow *window, const std::filesystem::path &path)
{
    initButton(path);
    setWindow(window);
}

void Button::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

void Button::initButton(const std::filesystem::path &path)
{
    setTexture(path);
    setStartPosition();
    setScale(button::SCALE);
}

void Button::setStartPosition()
{
    m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);
    m_button.setPosition(button::POSITION_X, button::POSITION_Y);
}

void Button::draw()
{
    m_window->draw(m_button);
}

void Button::move(float positionX, float positionY)
{
    m_button.move(positionX, positionY);
}

void Button::setScale(float scaleFactor)
{
    m_scaleFactor = scaleFactor;
    m_button.setScale(m_scaleFactor, m_scaleFactor);
}

void Button::setTexture(const std::filesystem::path &path)
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

std::pair<uint32_t, uint32_t> Button::getPosition()
{
    return std::make_pair(m_button.getPosition().x, m_button.getPosition().y);
}

bool Button::isPressed()
{
    auto mousePosition = sf::Mouse::getPosition(*m_window);
    auto translatedPosition = m_window->mapPixelToCoords(mousePosition);

    bool isMouseOnButton = m_button.getGlobalBounds().contains(translatedPosition);
    bool isMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    isMouseOnButton ? m_button.setScale(m_scaleFactor * button::INCREASE_FACTOR,
                                        m_scaleFactor * button::INCREASE_FACTOR)
                    : m_button.setScale(m_scaleFactor, m_scaleFactor);

    return isMousePressed and isMouseOnButton;
}

} // namespace gol
