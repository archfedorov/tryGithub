#pragma once
#include <map>
#include <string>
namespace sf {
	class Font;
	class Texture;
}
namespace mlg {
	class ResourceManager {
	private:
		std::map<std::string, sf::Font> fonts;
		std::map<std::string, sf::Texture> textures;
	public:
		ResourceManager();
		~ResourceManager();
		void loadFont(const std::string& aPath, const std::string& aKey);
		sf::Font& getFont(const std::string& aKey = "default");
		sf::Texture& getTexture(const std::string& aPath);
	};
}