#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Application.h"

#include "ManagersInstance.h"
#include "SceneManager.h"

#include "MainMenuScene.h"

using namespace mlg;

static const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application() {
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "My Little Game", sf::Style::Close);
	initialize();
}
Application::~Application() {
	delete window;
}
void Application::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window->isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);

			if (GET_SCENE_MANAGER()->isEmpty()) {
				window->close();
			}
		}
		render();
	}
}
void Application::processInput() {
	sf::Event currentEvent;
	while (window->pollEvent(currentEvent))
	{
		GET_SCENE_MANAGER()->handleEvent(currentEvent);
		if (currentEvent.type == sf::Event::Closed) {
			window->close();
		}
	}
}
void Application::update(const sf::Time& dt) {
	GET_SCENE_MANAGER()->update(dt);
}
void Application::render() {
	window->clear();

	GET_SCENE_MANAGER()->draw(*window);

	window->setView(window->getDefaultView());

	window->display();
}
void Application::initialize() {
	GET_SCENE_MANAGER()->pushScene(new MainMenuScene());
}