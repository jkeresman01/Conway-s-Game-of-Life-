#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Background
{
    public:
        Background();
        void create(sf::RenderWindow* t_window, const std::string t_path);
        void draw();

    private:
        sf::RenderWindow* m_window;
        sf::Sprite m_backgound;
        sf::Texture m_image;
        std::string m_path;
};
