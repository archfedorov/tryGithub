#pragma once
#include "SFMLForward.h"

namespace mlg {
	//class TextureManager;
	//class FontManager;

	class Application {
	private:
		sf::RenderWindow* window;
		//TextureManager* textureManager;
		//FontManager* fontManager;
		

		void processInput();
		void update(const sf::Time&);
		void render();
		void initialize();
	public:
		Application();
		~Application();
		void run();
	};
}