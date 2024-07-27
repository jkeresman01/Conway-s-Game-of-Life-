#pragma once

#include <filesystem>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Mouse.hpp>

namespace gol
{

class Button
{
    public:
        Button() = default;

        void create(sf::RenderWindow *t_window,
                    const std::filesystem::path &t_path);

        void draw();

        void move(float t_positionX, float t_positionY);

        bool isPressed();

        void setScale(float scale);
        void setTexture(const std::filesystem::path &t_path);
        void setWindow(sf::RenderWindow *t_window);

    private:
        void initButton(const std::filesystem::path &t_path);

        void loadTexture(const std::filesystem::path &t_path);
        void setStartPosition();

    private:
        sf::RenderWindow *m_window;
        sf::Texture m_texture;
        sf::Sprite m_button;

        float m_scaleFactor;
};
    
}
