#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

class Button{
    private:
        sf::RenderWindow* window;
        sf::Texture texture;
        sf::Sprite sprite;
        std::string path;

    public:
        Button(sf::RenderWindow* window, std::string path);
        void draw();
};
