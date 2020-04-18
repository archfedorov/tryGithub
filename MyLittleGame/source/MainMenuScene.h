#pragma once
#include "Scene.h"
#include "Button.h"

namespace mlg {
	class MainMenuScene : public Scene {
	public:
		MainMenuScene();
		~MainMenuScene();
		bool handleEvent(const sf::Event& aEvent);
		void draw(sf::RenderTarget&) override;
	private:
		Button* exitButton;
		Button* playButton;
	};
}
