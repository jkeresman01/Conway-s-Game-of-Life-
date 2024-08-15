#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace gol
{

const sf::Texture &ResourceManager::getTexture(const std::filesystem::path &filepath)
{
    std::unordered_map<std::string, sf::Texture>::const_iterator it;
    if (it = m_textures.find(filepath.string()); it == m_textures.end())
    {
        loadTexture(filepath);
        it = m_textures.find(filepath);
    }
    return it->second;
}

void ResourceManager::loadTexture(const std::filesystem::path &filepath)
{
    sf::Texture texture;

    if (texture.loadFromFile(filepath))
    {
        m_textures.emplace(filepath.string(), texture);
    }
    else
    {
        LOG_ERROR("Failed to texture from " << filepath.string() << "!");
    }
}

const sf::Font &ResourceManager::getFont(const std::filesystem::path &filepath)
{
    std::unordered_map<std::string, sf::Font>::const_iterator it;
    if (it = m_fonts.find(filepath.string()); it == m_fonts.end())
    {
        loadFont(filepath);
        it = m_fonts.find(filepath);
    }
    return it->second;
}

void ResourceManager::loadFont(const std::filesystem::path &filepath)
{
    sf::Font font;

    if (font.loadFromFile(filepath))
    {
        m_fonts.emplace(filepath.string(), font);
    }
    else
    {
        LOG_ERROR("Failed to load font from " << filepath.string() << "!");
    }
}

ResourceManager &ResourceManager::Instance()
{
    static ResourceManager instace;
    return instace;
}

} // namespace gol