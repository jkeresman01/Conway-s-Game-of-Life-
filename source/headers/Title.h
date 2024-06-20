#pragma once

#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Title
{
    public:
        Title() = default;

        void create(sf::RenderWindow *t_window, const std::string &t_text, const std::string &t_path);
        void draw();

    private:
        sf::RenderWindow *m_window;
        sf::Font m_font;
        sf::Text m_text;
};
