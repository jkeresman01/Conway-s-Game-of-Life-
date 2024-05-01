#include "headers/Cell.h"
#include "headers/GameConstants.h"
#include <cstdlib>

Cell::Cell(){}

Cell::Cell(sf::RenderWindow *window){
    this->window = window;
    this->shape.setSize(sf::Vector2f(GK::CELL::HEIGHT, GK::CELL::WIDTH));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(GK::CELL::BORDER_THICKNESS);
    this->shape.setPosition(GK::CELL::START_POSITION_X, GK::CELL::START_POSITION_Y);
    this->shape.setOrigin(GK::CELL::ORIGIN_X, GK::CELL::ORIGIN_Y);
    generate_number(100, 1) >= 10 ? set_state(GK::CELL::DEAD) : set_state(GK::CELL::ALIVE);
}

void Cell::draw(){
    this->window->draw(shape);
}

void Cell::set_position(float x, float y){
    this->shape.setPosition(x, y);
}

void Cell::set_state(GK::CELL::CellState cell_state){
    this->is_alive = cell_state;
    this->is_alive ? this->shape.setFillColor(sf::Color(250, 191, 106, 100))
                   : this->shape.setFillColor(sf::Color(250, 191, 106, 15));
}

int Cell::generate_number(int max, int min){
     return rand() % (max - min + 1) + min;
}
