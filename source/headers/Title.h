#pragma once

#include <filesystem>
#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

namespace gol
{
    
class Title
{
    public:
        Title() = default;

        void create(sf::RenderWindow *t_window,
                    const std::string &t_text,
                    const std::filesystem::path &t_path);

        void draw();

    private:
        void initText(const std::filesystem::path &t_path,
                      const std::string &t_text);

        void loadFont(const std::filesystem::path &t_path);

        void setDefaultSettings(const std::string &t_text);

    private:
        sf::RenderWindow *m_window;
        sf::Font m_font;
        sf::Text m_text;
};

} // gol
