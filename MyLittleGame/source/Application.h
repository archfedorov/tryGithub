#pragma once
#include "SFMLForward.h"

namespace mlg {
	class Application {
	private:
		sf::RenderWindow* window;
		

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