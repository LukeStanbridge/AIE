#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>
using namespace std;


class ResourceManager
{
public:
	~ResourceManager();
	Texture2D loadTexture(const char* path);

	static ResourceManager& instance()
	{
		static ResourceManager* instance = new ResourceManager();
		return *instance;
	}

private:
	unordered_map<string, Texture2D> m_textures;
};

