#include "headers/Button.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace gol
{

void Button::create(sf::RenderWindow *t_window,
                    const std::filesystem::path &t_path) 
{
    initButton(t_path);
    setWindow(t_window);
}

void Button::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void Button::initButton(const std::filesystem::path &t_path)
{
    setTexture(t_path);
    setStartPosition();
    setScale(button::SCALE);
}

void Button::setStartPosition()
{
    m_button.setOrigin(m_button.getGlobalBounds().width  / 2,
                       m_button.getGlobalBounds().height / 2);
    m_button.setPosition(button::POSITION_X, button::POSITION_Y);
}

void Button::draw()
{
    m_window->draw(m_button);
}

void Button::move(float t_positionX, float t_positionY)
{
    m_button.move(t_positionX, t_positionY);
}

void Button::setScale(float t_scaleFactor)
{
    m_scaleFactor = t_scaleFactor;
    m_button.setScale(m_scaleFactor, m_scaleFactor);
}

void Button::setTexture(const std::filesystem::path &t_path)
{
    if(!m_texture.loadFromFile(t_path.string()))
    {
        LOG_ERROR("Failed to load texture from " << t_path.string() << "!")
    }

    m_button.setTexture(m_texture);
    m_texture.setSmooth(true);
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
    
}
