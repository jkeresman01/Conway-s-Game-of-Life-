#include "headers/Map.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdlib>
#include <ctime>

int main() {

    srand(time(nullptr));
    
    sf::RenderWindow window(sf::VideoMode(1240, 720), "", sf::Style::Default);
    window.setPosition(sf::Vector2i(100, 100));
    window.setFramerateLimit(60);

    sf::Sprite backgorund;
    sf::Texture background_texture;
    if(!background_texture.loadFromFile("./resources/images/nasa-2.jpg")){
        return EXIT_FAILURE;
    }

    backgorund.setTexture(background_texture);
    backgorund.setScale(0.3, 0.3);

    sf::Font title_font;
    if(!title_font.loadFromFile("./resources/fonts/FloppyDisk.ttf")){
        return EXIT_FAILURE;
    }

    sf::Text title("Conway's Game of Life", title_font, 66);
    title.setFillColor(sf::Color(250, 191, 106));
    title.setPosition(50, 0);

    sf::Sprite pause_button;
    sf::Texture pause_button_texture;
    if(!pause_button_texture.loadFromFile("./resources/icons/pause_icon.png")){
        return EXIT_FAILURE;
    }
    pause_button.setTexture(pause_button_texture);
    pause_button.setOrigin(pause_button.getGlobalBounds().width/2, pause_button.getGlobalBounds().height /2);
    pause_button.setPosition(1240 - 110, 40);
    pause_button.setScale(0.8f, 0.8f);
    pause_button_texture.setSmooth(true);

    sf::Sprite play_button;
    sf::Texture play_button_texture;
    if(!play_button_texture.loadFromFile("./resources/icons/play_icon.png")){
        return EXIT_FAILURE;
    }
    play_button.setTexture(play_button_texture);
    play_button.setOrigin(play_button.getGlobalBounds().width/2, play_button.getGlobalBounds().height /2);
    play_button.setPosition(1240 - 50, 40);
    play_button.setScale(0.7f, 0.7f);
    play_button_texture.setSmooth(true);

    sf::Sprite refresh_button;
    sf::Texture refresh_button_texture;
    if(!refresh_button_texture.loadFromFile("./resources/icons/refresh_icon.png")){
        return EXIT_FAILURE;
    }
    refresh_button.setTexture(refresh_button_texture);
    refresh_button.setOrigin(refresh_button.getGlobalBounds().width/2, refresh_button.getGlobalBounds().height /2);
    refresh_button.setPosition(1240 - 170, 40);
    refresh_button.setScale(1.25f, 1.25f);
    refresh_button_texture.setSmooth(true);


    sf::RectangleShape button_menu(sf::Vector2f(200.f, 600.f));
    button_menu.setOrigin(50.f, 25.f);
    button_menu.setFillColor(sf::Color(250, 191, 106, 15));
    button_menu.setPosition(1240 - 160.f, 115);
    button_menu.setOutlineColor(sf::Color::Black);
    button_menu.setOutlineThickness(0.6f);

    Map map(&window);
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(backgorund);
        window.draw(title);
        window.draw(pause_button);
        window.draw(play_button);
        window.draw(refresh_button);
        window.draw(button_menu);
        map.draw();
        if(clock.getElapsedTime().asSeconds() > 2.f){
            map.update();
            clock.restart();
        }

        window.display();
    }

    return 0;
}
