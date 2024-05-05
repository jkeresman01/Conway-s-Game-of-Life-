#include "headers/GameOfLife.h"
#include <SFML/Graphics/RenderWindow.hpp>

int main(){
    srand(time(nullptr));

    sf::RenderWindow window;
    window.create(sf::VideoMode(gc::SCREEN::WIDTH, gc::SCREEN::HEIGHT), "", sf::Style::None);
    window.setPosition(sf::Vector2i(100, 100));
    window.setFramerateLimit(gc::GAME::FRAMES_PER_SECOND);

    GameOfLife game_of_life(&window);
    game_of_life.start();

    return 0;
}
