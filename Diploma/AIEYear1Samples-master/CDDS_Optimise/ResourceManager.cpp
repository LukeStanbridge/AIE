#include "ResourceManager.h"

ResourceManager::~ResourceManager()
{
    
}

Texture2D ResourceManager::loadTexture(const char* path)
{
    string key(path);
    auto iter = m_textures.find(key);
    if (iter != m_textures.end())
    {
        // already loaded the texture
        return iter->second;
    }
    else
    {
        // load and store in hash table
        Texture2D tex = LoadTexture(path);
        m_textures[key] = tex;
        return tex;
    }
}


