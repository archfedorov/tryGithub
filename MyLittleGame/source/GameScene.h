#pragma once
#include "Scene.h"
#include "Button.h"
#include "SFML/Graphics/Sprite.hpp"
#include <queue>
#include "World.h"

namespace mlg {
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();
		bool handleEvent(const sf::Event& aEvent);
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
		void restart();
	private:
		World* world;
		void init();
		Button backButton;
	};
}
