#include "MainMenuScene.h"
#include "ManagersInstance.h"
#include "SceneManager.h"
#include "SFML/Window/Event.hpp"
#include "Button.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "GameScene.h"

using namespace mlg;


bool MainMenuScene::handleEvent(const sf::Event& aEvent) {
	if (aEvent.type == sf::Event::KeyPressed) {
		if (aEvent.key.code == sf::Keyboard::Q) {
			GET_SCENE_MANAGER()->popScene();
		}
	}
	exitButton->handleEvent(aEvent);
	playButton->handleEvent(aEvent);
	return true;
}
void MainMenuScene::draw(sf::RenderTarget& renderer) {
	exitButton->draw(renderer);
	playButton->draw(renderer);
}

MainMenuScene::MainMenuScene() {
	exitButton = new Button();
	exitButton->setSize({ 100, 100 });
	exitButton->setPosition(400, 500);
	exitButton->setLabel("exit");
	exitButton->setReleaseCallback([]() {
		GET_SCENE_MANAGER()->popScene();
	});

	playButton = new Button();
	playButton->setSize({ 100, 100 });
	playButton->setPosition(400, 300);
	playButton->setLabel("play");
	playButton->setReleaseCallback([]() {
		GET_SCENE_MANAGER()->clearScenes();
		auto nextScene = new GameScene();
		GET_SCENE_MANAGER()->pushScene(nextScene);
	});
	sf::Texture texture;// = getContext().textures->get(Textures::TitleScreen);
	texture.loadFromFile("Media/Textures/man_run.png", sf::IntRect(0, 0, 100, 100));
	spr = sf::Sprite(texture);
	spr.setPosition(400, 400);
//	runningMan.setRepeating(true);
}
MainMenuScene::~MainMenuScene() {
	delete exitButton;
	delete playButton;
}