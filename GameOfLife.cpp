#include "headers/GameOfLife.h"
#include "headers/Background.h"
#include "headers/Button.h"
#include "headers/Title.h"
#include <SFML/Window/Event.hpp>

GameOfLife::GameOfLife(sf::RenderWindow* window){
    this->window = window;
    this->state = gc::GAME::STATE::PAUSED;
}

void GameOfLife::start(){

    Background background(window, "./resources/images/nasa-2.jpg");
    Map map(window);
    Title title(window, "Conway's Game of Life", "./resources/fonts/FloppyDisk.ttf");
    Button restart_button(window, "./resources/icons/restart.png");
    Button close_button(window, "./resources/icons/close.png");
    restart_button.move(-65, 0);

    this->state = gc::GAME::STATE::RUNNING;

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || close_button.is_clicked())
                window->close();
        }

        if(state == gc::GAME::RESTARTED){
            map.initilize_cells(25);
            state = gc::GAME::STATE::RUNNING;
        }

        window->clear();
        background.draw();
        title.draw();
        restart_button.draw();
        close_button.draw();
        map.draw();

        if(timer.getElapsedTime().asSeconds() > 2.0f){
            map.update();
            timer.restart();
        }

        if(restart_button.is_clicked()){
            this->state = gc::GAME::RESTARTED;
        }

        window->display();
    }


}
