#pragma once
#include "Scene.h"
#include "Button.h"
#include "SFML/Graphics/Sprite.hpp"
namespace mlg {
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();
		bool handleEvent(const sf::Event& aEvent);
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
	private:
		std::vector<sf::Sprite> pipes;
		void init();
		bool checkCollision();
		void createPipe();
		void lose();
		Button backButton;
		sf::Sprite bird;
		float birdVelocity;
		float birdAcc;
		float gapDistance;
		float worldVelocity;
	};
}
