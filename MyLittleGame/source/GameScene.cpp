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
		if (aEvent.key.code == sf::Keyboard::W) {
			createPipe();
		}
	}
	if (aEvent.type == sf::Event::EventType::MouseButtonPressed) {
		birdVelocity = -300.f;
	}
	return true;
}
void GameScene::draw(sf::RenderTarget& renderer) {
	renderer.draw(sky);
	for (auto& pipe : pipes) {
		renderer.draw(pipe);
	}
	renderer.draw(bird);
	renderer.draw(earth);
	renderer.draw(scoreText);
	backButton.draw(renderer);
}
GameScene::GameScene() {
	initConstants();
	init();
}
GameScene::~GameScene() {
}
void GameScene::updateScoreText() {
	char buff[255] = "";
	sprintf(buff, "Score: %10d", score);
	scoreText.setString(buff);
}

void GameScene::init() {
	initConstants();
	scoreText.setFont(GET_RESOURCE_MANAGER()->getFont());
	scoreText.setPosition(100, 100);
	score = 0u;
	updateScoreText();

	backButton.setSize({ 100, 50 });
	backButton.setPosition(0, 0);
	backButton.setLabel("back");
	backButton.setReleaseCallback([]() {
		GET_SCENE_MANAGER()->clearScenes();
		auto nextScene = new MainMenuScene();
		GET_SCENE_MANAGER()->pushScene(nextScene);
		});
	bird.setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/bluebird-downflap.png"));
	bird.setSize({ birdWidth, birdHeight });
	bird.setPosition(100.f, 100.f);
	
	earth.setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/base.png"));
	earth.setSize({ earthWidth, earthHeight });
	earth.setPosition({ 0.f, Constants::getFloat("WINDOW_HEIGHT") - earthHeight });

	sky.setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/background-day.png"));
	sky.setSize({ skyWidth, skyHeight });
	sky.setPosition({ 0.f, 0.f });

	distance = 0.0f;
	
	createPipe();
}
void GameScene::createPipe() {

//	Constants::getFloat("WINDOW_HEIGHT") == size1 + size2 + gap;
	float r = static_cast<float>(rand()) / RAND_MAX;
	float topHeight = std::floorf(100.f + r * 200.f);
	sf::RectangleShape topPipe;
	topPipe.setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/pipe-green-reverse.png"));
	topPipe.setSize({ pipeWidth, topHeight });
	topPipe.setPosition(Constants::getFloat("WINDOW_WIDTH"), 0);
	pipes.push_back(topPipe);

	float bottomHeight = Constants::getFloat("WINDOW_HEIGHT") - pipeVerticalGap - topHeight;
	sf::RectangleShape bottomPipe;
	bottomPipe.setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/pipe-green.png"));
	bottomPipe.setSize({ pipeWidth, bottomHeight });
	bottomPipe.setPosition(Constants::getFloat("WINDOW_WIDTH"), Constants::getFloat("WINDOW_HEIGHT") - bottomHeight);
	pipes.push_back(bottomPipe);

	scorePoints.push(distance + static_cast<double>(Constants::getFloat("WINDOW_WIDTH")) - bird.getPosition().x + pipeWidth);
}
bool GameScene::update(const sf::Time& deltaTime) {
	birdVelocity = birdVelocity + birdAcc * deltaTime.asSeconds();
	float birdPos = bird.getPosition().y;
	birdPos += birdVelocity * deltaTime.asSeconds();
	distance += worldVelocity * deltaTime.asSeconds();
	if (!scorePoints.empty() && distance >= scorePoints.front()) {
		score++;
		scorePoints.pop();
		updateScoreText();
	}
	bird.setPosition(bird.getPosition().x, birdPos);

	for (auto it = pipes.begin(); it != pipes.end(); ) {
		auto& pipe = *it;
		pipe.setPosition(pipe.getPosition().x - worldVelocity * deltaTime.asSeconds(), pipe.getPosition().y);
		if (pipe.getPosition().x + pipeWidth < 0) {
			it = pipes.erase(it);
		}
		else {
			it++;
		}
	}
	if (checkCollision()) {
		lose();
	}
	if (Constants::getFloat("WINDOW_WIDTH") - pipes.back().getPosition().x > pipeHorizontalGap) {
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
	if (bird.getGlobalBounds().intersects(earth.getGlobalBounds())) {
		return true;
	}
	return false;
}
void GameScene::lose() {
	if (!isLost) {
		GET_SCENE_MANAGER()->pushScene(new LoseScene());
		isLost = true;
	}
}
void GameScene::initConstants() {
	birdVelocity = 0.0f;
	birdAcc = 500.0f;
	birdWidth = 40;
	birdHeight = 30;
	pipeVerticalGap = 150.0;
	pipeHorizontalGap = 200.0;
	worldVelocity = 150.f;
	pipeWidth = 50.f;
	earthWidth = Constants::getFloat("WINDOW_WIDTH");
	earthHeight = 112.f;
	skyWidth = Constants::getFloat("WINDOW_WIDTH");
	skyHeight = Constants::getFloat("WINDOW_HEIGHT") - earthHeight;
}