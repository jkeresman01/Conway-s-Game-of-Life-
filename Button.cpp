#include "headers/Button.h"
#include "headers/GameConstants.h"

Button::Button(){}

Button::Button(sf::RenderWindow* window, std::string path){
    this->window = window;
    this->path = path;
    this->texture.loadFromFile(path);
    this->texture.setSmooth(true);
    this->button.setTexture(texture);
    this->button.setOrigin(this->button.getGlobalBounds().width / 2, this->button.getGlobalBounds().height / 2);
    this->button.setPosition(gc::BUTTON::POSITION_X, gc::BUTTON::POSITION_Y);
    set_scale(gc::BUTTON::SCALE_X, gc::BUTTON::SCALE_Y);
}

void Button::create(sf::RenderWindow* window, std::string path){
    this->window = window;
    this->path = path;
    this->texture.loadFromFile(path);
    this->texture.setSmooth(true);
    this->button.setTexture(texture);
    this->button.setOrigin(this->button.getGlobalBounds().width/ 2, this->button.getGlobalBounds().height / 2);
    this->button.setPosition(gc::BUTTON::POSITION_X, gc::BUTTON::POSITION_Y);
    set_scale(gc::BUTTON::SCALE_X, gc::BUTTON::SCALE_Y);
}

void Button::move(float position_x, float position_y){
    this->button.move(position_x, position_y);
}

void Button::set_scale(float scale_x, float scale_y){
    this->scale_factor = scale_x;
    this->button.setScale(scale_x, scale_y);
}

void Button::draw(){
    window->draw(button);
}

bool Button::is_pressed(){
    auto mouse_position = sf::Mouse::getPosition(*window); 
    auto translated_position = window->mapPixelToCoords(mouse_position);

    bool mouse_is_on_button = button.getGlobalBounds().contains(translated_position); 
    bool mouse_is_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    mouse_is_on_button
                ? button.setScale(scale_factor * 1.1f, scale_factor * 1.1f)
                : button.setScale(scale_factor, scale_factor);

    return mouse_is_on_button && mouse_is_pressed;
}
