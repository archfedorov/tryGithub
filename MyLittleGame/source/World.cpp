#define _CRT_SECURE_NO_WARNINGS
#include "World.h"

#include "MainMenuScene.h"
#include "ManagersInstance.h"
#include "SceneManager.h"
#include "SFML/Window/Event.hpp"
#include "Button.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "ResourceManager.h"
#include "Constants.h"
#include "LoseScene.h"
#include "Bird.h"

using namespace mlg;

void World::draw(sf::RenderTarget& renderer) {
	renderer.draw(sky);
	pipeManager.draw(renderer);
	bird.draw(renderer);
	renderer.draw(earth);
	renderer.draw(scoreText);
}
World::World() {
	initConstants();
	init();
}
World::~World() {
}
void World::updateScoreText() {
	char buff[255] = "";
	sprintf(buff, "Score: %10d", score);
	scoreText.setString(buff);
}

void World::init() {
	initConstants();
	scoreText.setFont(GET_RESOURCE_MANAGER()->getFont());
	scoreText.setPosition(100, 100);
	score = 0u;
	updateScoreText();
	
	earth.setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/base.png"));
	earth.setSize({ earthWidth, earthHeight });
	earth.setPosition({ 0.f, Constants::getFloat("WINDOW_HEIGHT") - earthHeight });

	sky.setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/background-day.png"));
	sky.setSize({ skyWidth, skyHeight });
	sky.setPosition({ 0.f, 0.f });

	pipeManager.setVelocity(velocity);
	distance = 0.;
}
void World::tap() {
	bird.fly();
}
float World::getVelocity() {
	return velocity;
}
bool World::update(const sf::Time& deltaTime) {
	bird.update(deltaTime);

	distance += velocity * deltaTime.asSeconds();
	if (!scorePoints.empty() && distance >= scorePoints.front()) {
		score++;
		scorePoints.pop();
		updateScoreText();
	}
	pipeManager.update(deltaTime);
	if (checkCollision()) {
		lose();
	}
	return false;
}
bool World::checkCollision() {
	for (auto& pipe : pipeManager.getPipes()) {
		if (bird.getGlobalBounds().intersects(pipe.getGlobalBounds())) {
			return true;
		}
	}
	if (bird.getGlobalBounds().intersects(earth.getGlobalBounds())) {
		return true;
	}
	return false;
}
void World::lose() {
	if (!isLost) {
		GET_SCENE_MANAGER()->pushScene(new LoseScene());
		isLost = true;
	}
}
void World::initConstants() {
	velocity = 150.f;
	earthWidth = Constants::getFloat("WINDOW_WIDTH");
	earthHeight = 112.f;
	skyWidth = Constants::getFloat("WINDOW_WIDTH");
	skyHeight = Constants::getFloat("WINDOW_HEIGHT") - earthHeight;
}