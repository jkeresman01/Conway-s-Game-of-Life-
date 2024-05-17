#include "headers/Cell.h"
#include "headers/GameConstants.h"

Cell::Cell(){
    this->shape.setSize(sf::Vector2f(gc::CELL::HEIGHT, gc::CELL::WIDTH));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(gc::CELL::BORDER_THICKNESS);
    this->shape.setPosition(gc::CELL::START_POSITION_X, gc::CELL::START_POSITION_Y);
    this->shape.setOrigin(gc::CELL::ORIGIN_X, gc::CELL::ORIGIN_Y);
    set_state(gc::CELL::DEAD);
}

void Cell::draw(){
    this->window->draw(shape);
}

bool Cell::is_alive(){
    return this->cell_state;
}

void Cell::set_window(sf::RenderWindow *window){
    this->window = window;
}

void Cell::set_position(float x, float y){
    this->shape.setPosition(x, y);
}

void Cell::set_state(gc::CELL::STATE cell_state){
    this->cell_state = cell_state;
    this->cell_state ? this->shape.setFillColor(sf::Color(250, 191, 106, 180))
                     : this->shape.setFillColor(sf::Color(250, 191, 106, 10));
}