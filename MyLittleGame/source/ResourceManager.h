#pragma once
#include <map>
#include <string>
namespace sf {
	class Font;
}
namespace mlg {
	class ResourceManager {
	private:
		std::map<std::string, sf::Font*> fonts;
	public:
		ResourceManager();
		~ResourceManager();
		void loadFont(const std::string& aPath, const std::string& aKey);
		sf::Font* getFont(const std::string& aKey = "default");
	};
}