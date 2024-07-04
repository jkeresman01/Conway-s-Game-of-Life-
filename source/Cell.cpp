#include "headers/Cell.h"

#include "headers/GameConstants.h"

namespace gol
{

Cell::Cell()
{
    m_cell.setSize(sf::Vector2f(cell::HEIGHT, cell::WIDTH));
    m_cell.setOutlineColor(sf::Color::Black);
    m_cell.setOutlineThickness(cell::BORDER_THICKNESS);
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

void Cell::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void Cell::setPosition(float t_positionX, float t_positionY)
{
    m_cell.setPosition(t_positionX, t_positionY);
}

void Cell::setState(const cell::State &t_state)
{
    m_state = t_state;
    m_state ? m_cell.setFillColor(sf::Color(250, 191, 106, 180))
            : m_cell.setFillColor(sf::Color(250, 191, 106, 10));
}
    
} // gol
