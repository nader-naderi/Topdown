#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class ResourceManager
{
public:
	static ResourceManager& getInstance();
	static void init();

	void load(const std::string& filename, const std::string& id);
	void unload(const std::string& id);

	sf::Texture& getTexture(const std::string& id);
	sf::Font& getFont(const std::string& id);

private:
	ResourceManager() = default;
	ResourceManager(const ResourceManager&) = default;
	ResourceManager& operator=(const ResourceManager&) = delete;
	static ResourceManager* instance;

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> font;
};

