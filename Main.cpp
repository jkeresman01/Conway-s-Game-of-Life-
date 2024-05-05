#include "headers/GameOfLife.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <ctime>

int main(){
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(gc::SCREEN::WIDTH, gc::SCREEN::HEIGHT), "", sf::Style::None);
    window.setPosition(sf::Vector2i(gc::SCREEN::POSITION_X, gc::SCREEN::POSITION_Y));
    window.setFramerateLimit(gc::GAME::FRAMES_PER_SECOND);

    GameOfLife game_of_life(&window);
    game_of_life.start();

    return 0;
}
