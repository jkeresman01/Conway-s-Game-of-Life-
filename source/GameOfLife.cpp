#include "headers/GameOfLife.h"
#include "headers/Background.h"
#include "headers/Button.h"
#include "headers/Title.h"

#include <SFML/Window/Event.hpp>

GameOfLife::GameOfLife(sf::RenderWindow* window){
    this->window = window;
    this->background.create(window, "./resources/images/nasa-2.jpg");
    this->map.create(window);
    this->title.create(window, "Conway's Game of Life", "./resources/fonts/FloppyDisk.ttf");
    this->close_button.create(window, "./resources/icons/close.png");
    this->close_button.set_scale(0.5f);
    this->close_button.move(0, -20);
    this->reshuffle_button.create(window,  "./resources/icons/restart.png");
    this->reshuffle_button.move(-50, gc::TITLE::POSITION_Y);
    this->pause_button.create(window, "./resources/icons/pause.png");
    this->pause_button.move(-100, gc::TITLE::POSITION_Y);
    this->play_button.create(window, "./resources/icons/play.png");
    this->play_button.move(-150, gc::TITLE::POSITION_Y);
    this->state = gc::GAME::STATE::RUNNING;
}

void GameOfLife::start(){
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed or close_button.is_pressed())
                window->close();
        }

        if(state == gc::GAME::RESHUFFLED){
            map.initilize_cells(gc::MAP::CRITERIA_20_PERCENT_ALIVE_CELLS);
            state = gc::GAME::STATE::RUNNING;
        }

        if(clock.getElapsedTime().asSeconds() > gc::GAME::REFRESH_TIME_SECONDS and state != gc::GAME::PAUSED){
            map.update();
            clock.restart();
        }

        if(reshuffle_button.is_pressed()){
            this->state = gc::GAME::RESHUFFLED;
        }

        if(pause_button.is_pressed()){
            this->state = gc::GAME::PAUSED;
        }

        if(play_button.is_pressed()){
            this->state = gc::GAME::RUNNING;
        }

        window->clear();
        background.draw();
        reshuffle_button.draw();
        close_button.draw();
        pause_button.draw();
        play_button.draw();
        title.draw();
        map.draw();
        window->display();
    }
}
