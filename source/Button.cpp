#include "headers/Button.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

void Button::create(sf::RenderWindow *t_window,
                    const std::filesystem::path &t_path) 
{
    m_window = t_window;

    initButton(t_path);
}

void Button::initButton(const std::filesystem::path &t_path)
{
    setTexture(t_path);

    m_button.setOrigin(m_button.getGlobalBounds().width  / 2,
                       m_button.getGlobalBounds().height / 2);
    m_button.setPosition(gc::button::POSITION_X, gc::button::POSITION_Y);

    setScale(gc::button::SCALE);
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
    loadTexture(t_path);
    m_texture.setSmooth(true);
}

void Button::loadTexture(const std::filesystem::path &t_path)
{
    if(!m_texture.loadFromFile(t_path.string()))
    {
        LOG_ERROR("Failed to load texture from " << t_path.string() << "!")
    }

    m_button.setTexture(m_texture);
}

bool Button::isPressed()
{
    auto mousePosition = sf::Mouse::getPosition(*m_window); 
    auto translatedPosition = m_window->mapPixelToCoords(mousePosition);

    bool isMouseOnButton = m_button.getGlobalBounds().contains(translatedPosition); 
    bool isMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    isMouseOnButton ? m_button.setScale(m_scaleFactor * 1.1f, m_scaleFactor * 1.1f)
                    : m_button.setScale(m_scaleFactor, m_scaleFactor);

    return isMousePressed and isMouseOnButton;
}
