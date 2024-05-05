#pragma once

#include "Background.h"
#include "Button.h"
#include <SFML/Graphics/Texture.hpp>

class Menu{
    private:
        sf::RenderWindow* window;
        Button close_button;
        Button refresh_button;

    public:
        Menu(sf::RenderWindow* window, sf::Texture close_button, sf::Texture refresh_button);
        void draw();
};
