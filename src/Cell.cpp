#include "headers/Cell.h"

namespace gol
{

Cell::Cell() : m_window(nullptr)
{
    m_cell.setSize(sf::Vector2f(cell::WIDTH, cell::HEIGHT));
    m_cell.setOutlineColor(sf::Color::Black);
    m_cell.setOutlineThickness(cell::OUTLINE_THICKNESS);
    m_cell.setPosition(cell::START_POSITION_X, cell::START_POSITION_Y);
    m_cell.setOrigin(cell::ORIGIN_X, cell::ORIGIN_Y);

    setState(cell::State::DEAD);
}

void Cell::draw()
{
    m_window->draw(m_cell);
}

bool Cell::isAlive() const
{
    return m_state;
}

sf::Color Cell::getColor()
{
    return m_cell.getFillColor();
}

void Cell::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

void Cell::setPosition(float positionX, float positionY)
{
    m_cell.setPosition(positionX, positionY);
}

void Cell::setState(cell::State state)
{
    m_state = state;
    m_state ? m_cell.setFillColor(cell::Colors::YELLLOW_ALIVE)                    : m_cell.setFillColor(cell::Colors::TRANSPARENT_DEAD);
}

} // namespace gol
