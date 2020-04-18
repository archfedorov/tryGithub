#pragma once
#include "Scene.h"
#include "Button.h"

namespace mlg {
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();
		bool handleEvent(const sf::Event& aEvent);
		void draw(sf::RenderTarget&) override;
	private:
		Button* exitButton;
		Button* playButton;
	};
}
