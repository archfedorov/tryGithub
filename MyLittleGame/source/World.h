#pragma once
#include "Scene.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include <queue>

namespace mlg {
	class World : public Updateable, public Drawable/*, public EventHandler*/ {
	public:
		World();
		~World();
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
		void tap();
	private:
		std::vector<sf::RectangleShape> pipes;
		void init();
		bool checkCollision();
		void createPipe();
		
		void lose();
		bool isLost;

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
		
		double distance;
		float worldVelocity;
	};
}
