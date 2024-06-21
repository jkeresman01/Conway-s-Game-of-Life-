#include "headers/Cell.h"
#include "headers/GameConstants.h"

Cell::Cell()
{
    m_cell.setSize(sf::Vector2f(gc::cell::HEIGHT, gc::cell::WIDTH));
    m_cell.setOutlineColor(sf::Color::Black);
    m_cell.setOutlineThickness(gc::cell::BORDER_THICKNESS);
    m_cell.setPosition(gc::cell::START_POSITION_X, gc::cell::START_POSITION_Y);
    m_cell.setOrigin(gc::cell::ORIGIN_X, gc::cell::ORIGIN_Y);

    setState(gc::cell::DEAD);
}

void Cell::draw()
{
    m_window->draw(m_cell);
}

bool Cell::isAlive() const
{
    return m_state;
}

void Cell::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void Cell::setPosition(float t_positionX, float t_positionY)
{
    m_cell.setPosition(t_positionX, t_positionY);
}

void Cell::setState(gc::cell::State t_state)
{
    m_state = t_state;
    m_state ? m_cell.setFillColor(sf::Color(250, 191, 106, 180))
            : m_cell.setFillColor(sf::Color(250, 191, 106, 10));
}
