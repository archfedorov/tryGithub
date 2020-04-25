#pragma once
#include "Scene.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

#include "Bird.h"
#include "PipeManager.h"

#include <queue>

namespace mlg {
	class World : public Updateable, public Drawable/*, public EventHandler*/ {
	public:
		World();
		~World();
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
		void tap();
		float getVelocity();

	private:
		void init();
		bool checkCollision();
		
		void lose();
		bool isLost;

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

		Bird bird;
		PipeManager pipeManager;

		double distance;
		float velocity;
	};
}
