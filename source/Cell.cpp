#include "headers/Cell.h"
#include "headers/GameConstants.h"

Cell::Cell(){
    this->cell.setSize(sf::Vector2f(gc::CELL::HEIGHT, gc::CELL::WIDTH));
    this->cell.setOutlineColor(sf::Color::Black);
    this->cell.setOutlineThickness(gc::CELL::BORDER_THICKNESS);
    this->cell.setPosition(gc::CELL::START_POSITION_X, gc::CELL::START_POSITION_Y);
    this->cell.setOrigin(gc::CELL::ORIGIN_X, gc::CELL::ORIGIN_Y);
    set_state(gc::CELL::DEAD);
}

void Cell::draw(){
    this->window->draw(cell);
}

bool Cell::is_alive(){
    return this->state;
}

void Cell::set_window(sf::RenderWindow *window){
    this->window = window;
}

void Cell::set_position(float position_x, float position_y){
    this->cell.setPosition(position_x, position_y);
}

void Cell::set_state(gc::CELL::STATE state){
    this->state = state;
    this->state ? this->cell.setFillColor(sf::Color(250, 191, 106, 180))
                : this->cell.setFillColor(sf::Color(250, 191, 106, 10));
}
