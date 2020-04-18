#include "GameScene.h"
#include "ManagersInstance.h"
#include "SceneManager.h"
#include "SFML/Window/Event.hpp"
#include "Button.h"
#include "SFML/Graphics/RenderTarget.hpp"
using namespace mlg;


bool GameScene::handleEvent(const sf::Event& aEvent) {
	if (aEvent.type == sf::Event::KeyPressed) {
		if (aEvent.key.code == sf::Keyboard::Q) {
			GET_SCENE_MANAGER()->popScene();
		}
	}
	exitButton->handleEvent(aEvent);
	playButton->handleEvent(aEvent);
	return true;
}
void GameScene::draw(sf::RenderTarget& renderer) {
	exitButton->draw(renderer);
	playButton->draw(renderer);
}

GameScene::GameScene() {
	exitButton = new Button();
	exitButton->setSize({ 100, 100 });
	exitButton->setPosition(400, 500);
	exitButton->setLabel("exitToMenu");
	exitButton->setReleaseCallback([]() {
		GET_SCENE_MANAGER()->popScene();
		});
	playButton = new Button();
	playButton->setSize({ 100, 100 });
	playButton->setPosition(400, 300);
	playButton->setLabel("start");
	playButton->setReleaseCallback([]() {
		
		});
}
GameScene::~GameScene() {
	delete exitButton;
	delete playButton;
}