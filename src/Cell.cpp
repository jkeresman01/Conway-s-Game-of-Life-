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

void Cell::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void Cell::setPosition(float t_positionX, float t_positionY)
{
    m_cell.setPosition(t_positionX, t_positionY);
}

void Cell::setState(cell::State t_state)
{
    m_state = t_state;
    m_state ? m_cell.setFillColor(cell::Colors::ALIVE) : m_cell.setFillColor(cell::Colors::DEAD);
}

} // namespace gol
