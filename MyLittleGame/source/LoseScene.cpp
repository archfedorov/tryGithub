#include "LoseScene.h"
#include "ManagersInstance.h"
#include "SceneManager.h"
#include "SFML/Window/Event.hpp"
#include "Button.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "MainMenuScene.h"
#include "GameScene.h"

using namespace mlg;


bool LoseScene::handleEvent(const sf::Event& aEvent) {
	if (aEvent.type == sf::Event::KeyPressed) {
		if (aEvent.key.code == sf::Keyboard::Q) {
			GET_SCENE_MANAGER()->popScene();
		}
	}
	restartButton->handleEvent(aEvent);
	mainMenuButton->handleEvent(aEvent);
	return true;
}
void LoseScene::draw(sf::RenderTarget& renderer) {
	restartButton->draw(renderer);
	mainMenuButton->draw(renderer);
}
bool LoseScene::update(const sf::Time&) {
	return true;
}

LoseScene::LoseScene() {
	restartButton = new Button();
	restartButton->setSize({ 100, 100 });
	restartButton->setPosition(400, 500);
	restartButton->setLabel("restart");
	restartButton->setReleaseCallback([]() {
		GET_SCENE_MANAGER()->clearScenes();
		auto nextScene = new GameScene();
		GET_SCENE_MANAGER()->pushScene(nextScene);
	});

	mainMenuButton = new Button();
	mainMenuButton->setSize({ 100, 100 });
	mainMenuButton->setPosition(400, 300);
	mainMenuButton->setLabel("mainMenu");
	mainMenuButton->setReleaseCallback([]() {
		GET_SCENE_MANAGER()->clearScenes();
		auto nextScene = new MainMenuScene();
		GET_SCENE_MANAGER()->pushScene(nextScene);
	});
}
LoseScene::~LoseScene() {
	delete restartButton;
	delete mainMenuButton;
}