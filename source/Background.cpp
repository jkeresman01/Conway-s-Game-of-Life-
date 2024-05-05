#include "headers/Background.h"
#include "headers/GameConstants.h"

Background::Background(){}

Background::Background(sf::RenderWindow* window, std::string path){
    this->window = window;
    this->path = path;
    this->image.loadFromFile(path);
    this->backgound.setTexture(image);
    this->backgound.setScale(gc::BACKGROUND::SCALE_X, gc::BACKGROUND::SCALE_Y);
}

void Background::create(sf::RenderWindow* window, std::string path){
    this->window = window;
    this->path = path;
    this->image.loadFromFile(path);
    this->backgound.setTexture(image);
    this->backgound.setScale(gc::BACKGROUND::SCALE_X, gc::BACKGROUND::SCALE_Y);
}

void Background::draw(){
    this->window->draw(this->backgound);
}


