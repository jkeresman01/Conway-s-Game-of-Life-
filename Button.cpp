#include "headers/Button.h"

Button::Button(sf::RenderWindow* window, std::string path){
    this->window = window;
    this->path = path;
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
}

void Button::draw(){
    window->draw(this->sprite);
}
