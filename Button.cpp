#include "headers/Button.h"

Button::Button(){}

Button::Button(sf::RenderWindow* window, std::string path){
    this->window = window;
    this->path = path;
    this->texture.loadFromFile(path);
    this->texture.setSmooth(true);
    this->button.setTexture(texture);
    this->button.setOrigin(this->button.getGlobalBounds().width/ 2, this->button.getGlobalBounds().height / 2);
    this->button.setPosition(1240 - 80, 40);
    this->button.setScale(1.2f, 1.2f);
}

void Button::move(float position_x, float position_y){
    this->button.move(position_x, position_y);
}

void Button::draw(){
    window->draw(button);
}

bool Button::is_clicked(){
    auto mouse_position = sf::Mouse::getPosition(*window); 
    auto translated_position = window->mapPixelToCoords(mouse_position);

    bool mouse_is_on_button = button.getGlobalBounds().contains(translated_position); 
    bool mouse_is_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    return mouse_is_on_button && mouse_is_pressed;
}
