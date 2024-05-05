#include "headers/Title.h"

Title::Title(){}

Title::Title(sf::RenderWindow* window, std::string text, std::string path){
    this->window = window;
    this->font.loadFromFile(path);
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setFillColor(sf::Color(250, 191, 106));
    this->text.setPosition(50, 0);
    this->text.setCharacterSize(66);
}

void Title::create(sf::RenderWindow* window, std::string text, std::string path){
    Title(window, text, path);
}

void Title::draw(){
    this->window->draw(text);
}
