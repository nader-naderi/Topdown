#include "ResourceManager.hpp"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager& ResourceManager::getInstance()
{
	if (!instance)
	{
		instance = new ResourceManager();
	}
	return *instance;
}

void ResourceManager::init()
{
	getInstance();
}

void ResourceManager::load(const std::string& filename, const std::string& id)
{
	if (filename.find(".png") != std::string::npos ||
		filename.find(".jpg") != std::string::npos)
	{
		textures[id].loadFromFile(filename);
	}
	else if (filename.find(".ttf") != std::string::npos)
	{
		font[id].loadFromFile(filename);
	}
}

void ResourceManager::unload(const std::string& id)
{
	textures.erase(id);
	textures.erase(id);
}

sf::Texture& ResourceManager::getTexture(const std::string& id)
{
	return textures[id];
}

sf::Font& ResourceManager::getFont(const std::string& id)
{
	return font[id];
}
