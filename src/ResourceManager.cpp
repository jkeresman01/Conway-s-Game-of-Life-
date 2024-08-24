#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace gol
{

const sf::Texture &ResourceManager::getTexture(const std::filesystem::path &filepath)
{
    TexturesUnorderedMapT::iterator it = m_textures.find(filepath.string());

    if (it == m_textures.end())
    {
        loadTexture(filepath);
        it = m_textures.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadTexture(const std::filesystem::path &filepath)
{
    sf::Texture texture;

    bool isTextureLoadedSuccessfully = texture.loadFromFile(filepath);

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from " << filepath.string() << "!");
        return;
    }
    
    m_textures.emplace(filepath.string(), texture);
}

const sf::Font &ResourceManager::getFont(const std::filesystem::path &filepath)
{
    FontsUnorderedMapT::iterator it = m_fonts.find(filepath.string());

    if (it == m_fonts.end())
    {
        loadFont(filepath);
        it = m_fonts.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadFont(const std::filesystem::path &filepath)
{
    sf::Font font;

    bool isFontLoadedSuccesfully = font.loadFromFile(filepath);

    if (!isFontLoadedSuccesfully)
    {
        LOG_ERROR("Failed to load font from " << filepath.string() << "!");
        return;
    }

    m_fonts.emplace(filepath.string(), font);
}

ResourceManager &ResourceManager::Instance()
{
    static ResourceManager instace;
    return instace;
}

} // namespace gol
