#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

class Button{
    private:
        sf::RenderWindow* window;
        sf::Texture texture;
        sf::Sprite button;
        std::string path;

    public:
        Button();
        Button(sf::RenderWindow* window, std::string path);
        void move(float position_x, float position_y);
        void create(sf::RenderWindow* window, std::string path);
        void draw();
        bool is_pressed();
};
