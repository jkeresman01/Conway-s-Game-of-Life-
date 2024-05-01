#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <ctime>

int agenerate_number(int max, int min){
    return rand() % (max - min + 1) + min;
}

void draw_map(sf::RenderWindow &window, sf::RectangleShape rectangles[][95]){
    float height = 10.0f;
    float width = 10.0f;

    sf::RectangleShape rec(sf::Vector2f(width, height));
    rec.setFillColor(sf::Color(250, 191, 106, 10));
    rec.setPosition(50, 95);
    rec.setOrigin(5.0f, 5.0f);
    rec.setOutlineColor(sf::Color::White);
    rec.setOutlineThickness(0.5f);

    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 95; j++){
            rectangles[i][j]= rec;
            rectangles[i][j].setPosition(rec.getPosition().x + (j* width), rec.getPosition().y + (i * height ));
            if(agenerate_number(100, 1) <= 25){
                rectangles[i][j].setFillColor(sf::Color(250, 191, 106));
            }
        }
    }

    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 95; j++){
            window.draw(rectangles[i][j]);
        }
    }
}

int main()
{
    srand(time(nullptr));
    sf::RenderWindow window(sf::VideoMode(1240, 720), "");
    window.setFramerateLimit(60);

    sf::Sprite sprite;
    sf::Texture texture;
    if(!texture.loadFromFile("./resources/images/nasa-2.jpg")){
        return EXIT_FAILURE;
    }
    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);

    sf::Font park_tech_font;
    if(!park_tech_font.loadFromFile("./resources/fonts/FloppyDisk.ttf")){
        return EXIT_FAILURE;
    }

    sf::Text game_name("Conway's Game of Life", park_tech_font, 69);
    game_name.setFillColor(sf::Color(250, 191, 106));
    game_name.setPosition(40, 0);

    sf::Clock clock;

    sf::RectangleShape  rectangles[60][95];

    while (window.isOpen())
    {
        sf::Time start = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.draw(game_name);
        draw_map(window, rectangles);
        window.display();
        //return EXIT_SUCCESS;
    }

    return 0;
}
