#include "ResourceManager.h"
#include "SFML/Graphics/Font.hpp"

using namespace mlg;

ResourceManager::ResourceManager() {
	loadFont("resource/fonts/Sansation.ttf", "default");
}
ResourceManager::~ResourceManager() {
}
sf::Texture& ResourceManager::getTexture(const std::string& aPath) {
	auto found = textures.find(aPath);
	if (found == textures.end()) {
		sf::Texture newTexture;
		newTexture.loadFromFile(aPath);
		found = textures.insert(std::make_pair(aPath, newTexture)).first;
	}
	return found->second;
}
void ResourceManager::loadFont(const std::string& aPath, const std::string& aKey) {
	sf::Font newFont;
	if (newFont.loadFromFile(aPath)) {
		auto found = fonts.find(aKey);
		if (found != fonts.end()) {
			fonts.erase(found);
		}
		fonts[aKey] = newFont;
	}
}
sf::Font& ResourceManager::getFont(const std::string& aKey) {
	return fonts[aKey];
}
