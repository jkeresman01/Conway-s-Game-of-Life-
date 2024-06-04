#include "headers/GameOfLife.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <ctime>

int main()
{
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), "", sf::Style::None);
    window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));
    window.setFramerateLimit(gc::game::FRAMES_PER_SECOND);

    GameOfLife gameOfLife(&window);
    gameOfLife.run();

    return 0;
}
