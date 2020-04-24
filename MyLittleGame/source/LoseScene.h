#pragma once
#include "Scene.h"
#include "Button.h"

namespace mlg {
	class LoseScene : public Scene {
	public:
		LoseScene();
		~LoseScene();
		bool handleEvent(const sf::Event& aEvent);
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time&) override;
	private:
		Button* restartButton;
		Button* mainMenuButton;
	};
}
