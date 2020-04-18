#include "ResourceManager.h"
#include "SFML/Graphics/Font.hpp"

using namespace mlg;

ResourceManager::ResourceManager() {
	loadFont("resource/fonts/Sansation.ttf", "default");
}
ResourceManager::~ResourceManager() {
	for (auto& fontIterator : fonts) {
		delete fontIterator.second;
	}
}
void ResourceManager::loadFont(const std::string& aPath, const std::string& aKey) {
	auto newFont = new sf::Font();
	if (newFont->loadFromFile(aPath)) {
		auto found = fonts.find(aKey);
		if (found != fonts.end()) {
			delete found->second;
		}
		fonts[aKey] = newFont;
	}
	else {
		delete newFont;
	}
}
sf::Font* ResourceManager::getFont(const std::string& aKey) {
	return fonts[aKey];
}
