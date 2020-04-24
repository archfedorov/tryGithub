#pragma once
#include "Scene.h"
#include "Button.h"
#include "SFML/Graphics/Sprite.hpp"
#include <queue>

namespace mlg {
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();
		bool handleEvent(const sf::Event& aEvent);
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
	private:
		std::vector<sf::RectangleShape> pipes;
		void init();
		bool checkCollision();
		void createPipe();
		
		void lose();
		bool isLost;

		Button backButton;
		sf::RectangleShape bird;
		sf::RectangleShape earth;
		sf::RectangleShape sky;

		std::queue<double> scorePoints;
		sf::Text scoreText;
		unsigned int score;
		void updateScoreText();

		void initConstants();

		float earthHeight;
		float earthWidth;
		float skyHeight;
		float skyWidth;


		float pipeVerticalGap;
		float pipeHorizontalGap;
		float pipeWidth;

		float birdVelocity;
		float birdAcc;
		float birdWidth;
		float birdHeight;
		
		double distance = 0.0f;
		float worldVelocity;
	};
}
