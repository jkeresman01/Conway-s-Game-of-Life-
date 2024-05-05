#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class Title{
    private:
        sf::RenderWindow* window;
        sf::Font font;
        sf::Text text;

    public:
        Title();
        Title(sf::RenderWindow* window, std::string text, std::string path);
        void create(sf::RenderWindow* window, std::string text, std::string path);
        void draw();
};
