#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Background{
    private:
        sf::RenderWindow* window;
        sf::Sprite backgound;
        sf::Texture image;
        std::string path;

    public:
        Background();
        Background(sf::RenderWindow* window, std::string path);
        void create(sf::RenderWindow* window, std::string path);
        void draw();
};
