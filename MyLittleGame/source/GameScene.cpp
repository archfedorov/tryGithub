#define _CRT_SECURE_NO_WARNINGS
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
#include "LoseScene.h"
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
		if (world) {
			world->tap();
		}
	}
	return true;
}
void GameScene::draw(sf::RenderTarget& renderer) {
	if (world) {
		world->draw(renderer);
	}
	backButton.draw(renderer);
}
GameScene::GameScene() {
	setName("GAME");
	world = nullptr;

	backButton.setSize({ 100, 50 });
	backButton.setPosition(0, 0);
	backButton.setLabel("back");
	backButton.setReleaseCallback([]() {
		GET_SCENE_MANAGER()->clearScenes();
		auto nextScene = new MainMenuScene();
		GET_SCENE_MANAGER()->pushScene(nextScene);
		});
	init();
}
GameScene::~GameScene() {
	delete world;
}

void GameScene::init() {

	if (world) {
		delete world;
	}
	world = new World();
}

bool GameScene::update(const sf::Time& deltaTime) {
	if (world) {
		world->update(deltaTime);
	}
	return false;
}

void GameScene::restart() {
	init();
}