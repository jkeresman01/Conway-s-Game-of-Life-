#include "headers/Cell.h"

namespace gol
{

Cell::Cell()
{
    m_cell.setSize(sf::Vector2f(m_width, m_height));
    m_cell.setOutlineColor(sf::Color::Black);
    m_cell.setOutlineThickness(OUTLINE_THICKNESS);
    m_cell.setPosition(START_POSITION_X, START_POSITION_Y);
    m_cell.setOrigin(ORIGIN_X, ORIGIN_Y);

    setState(State::DEAD);
}

void Cell::render(sf::RenderWindow &window) const
{
    window.draw(m_cell);
}

void Cell::setPosition(float positionX, float positionY)
{
    m_cell.setPosition(positionX, positionY);
}

void Cell::setState(State state)
{
    m_state = state;
    m_state == State::ALIVE ? m_cell.setFillColor(sf::Color(250, 191, 106, 180))
                            : m_cell.setFillColor(sf::Color(250, 191, 106, 10));
}

} // namespace gol
