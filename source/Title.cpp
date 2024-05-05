#include "headers/Title.h"
#include "headers/GameConstants.h"

Title::Title(){}

Title::Title(sf::RenderWindow* window, std::string text, std::string path){
    this->window = window;
    this->font.loadFromFile(path);
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setFillColor(sf::Color(250, 191, 106));
    this->text.setPosition(gc::TITLE::POSITION_X, gc::TITLE::POSITION_Y);
    this->text.setCharacterSize(gc::TITLE::FONT_SIZE);
}

void Title::create(sf::RenderWindow* window, std::string text, std::string path){
    this->window = window;
    this->font.loadFromFile(path);
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setFillColor(sf::Color(250, 191, 106));
    this->text.setPosition(gc::TITLE::POSITION_X, gc::TITLE::POSITION_Y);
    this->text.setCharacterSize(gc::TITLE::FONT_SIZE);
}

void Title::draw(){
    this->window->draw(text);
}
