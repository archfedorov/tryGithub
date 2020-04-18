#include "GameScene.h"

#include "MainMenuScene.h"
#include "ManagersInstance.h"
#include "SceneManager.h"
#include "SFML/Window/Event.hpp"
#include "Button.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "ResourceManager.h"
#include "Constants.h"

using namespace mlg;


bool GameScene::handleEvent(const sf::Event& aEvent) {
	if (backButton.handleEvent(aEvent)) {
		return true;
	}

	if (aEvent.type == sf::Event::KeyPressed) {
		if (aEvent.key.code == sf::Keyboard::Q) {
			GET_SCENE_MANAGER()->clearScenes();
			auto nextScene = new MainMenuScene();
			GET_SCENE_MANAGER()->pushScene(nextScene);
			return true;
		}
	}
	if (aEvent.type == sf::Event::EventType::MouseButtonPressed) {
		birdVelocity = -300.f;
	}
	return true;
}
void GameScene::draw(sf::RenderTarget& renderer) {
	for (auto& pipe : pipes) {
		renderer.draw(pipe);
	}
	renderer.draw(bird);
	backButton.draw(renderer);
}

GameScene::GameScene() {
	init();
}
GameScene::~GameScene() {
}
void GameScene::init() {
	backButton.setSize({ 100, 50 });
	backButton.setPosition(0, 0);
	backButton.setLabel("back");
	backButton.setReleaseCallback([]() {
		GET_SCENE_MANAGER()->clearScenes();
		auto nextScene = new MainMenuScene();
		GET_SCENE_MANAGER()->pushScene(nextScene);
		});
	bird.setTexture(GET_RESOURCE_MANAGER()->getTexture("resource/images/bluebird-downflap.png"));
	bird.setPosition(100, 100);
	birdVelocity = 0.0f;
	birdAcc = 500.0f;
	gapDistance = 100.0;
	worldVelocity = -50.f;
	createPipe();
}
void GameScene::createPipe() {
	sf::Sprite pipe;
	pipe.setTexture(GET_RESOURCE_MANAGER()->getTexture("resource/images/pipe-green.png"));
	pipe.setPosition(Constants::getFloat("WINDOW_WIDTH"), Constants::getFloat("WINDOW_HEIGHT") - pipe.getGlobalBounds().height);
	pipes.push_back(pipe);

	sf::Sprite pipeReverse;
	pipe.setTexture(GET_RESOURCE_MANAGER()->getTexture("resource/images/pipe-green-reverse.png"));
	pipe.setPosition(Constants::getFloat("WINDOW_WIDTH"), 0);
	pipes.push_back(pipe);

}
bool GameScene::update(const sf::Time& deltaTime) {
	birdVelocity = birdVelocity + birdAcc * deltaTime.asSeconds();
	float birdPos = bird.getPosition().y;
	birdPos += birdVelocity * deltaTime.asSeconds();
	bird.setPosition(bird.getPosition().x, birdPos);

	for (auto& pipe : pipes) {
		pipe.setPosition(pipe.getPosition().x + worldVelocity * deltaTime.asSeconds(), pipe.getPosition().y);
	}
	if (checkCollision()) {
		lose();
	}
	if (Constants::getFloat("WINDOW_WIDTH") - pipes.back().getPosition().x > gapDistance) {
		createPipe();
	}
	return false;
}
bool GameScene::checkCollision() {
	for (auto& pipe : pipes) {
		if (bird.getGlobalBounds().intersects(pipe.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}
void GameScene::lose() {
	GET_SCENE_MANAGER()->clearScenes();
	auto nextScene = new MainMenuScene();
	GET_SCENE_MANAGER()->pushScene(nextScene);
}