#include "PipeManager.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Time.hpp"
#include "Constants.h"
#include "json.hpp"
#include <fstream>

using namespace mlg;

PipeManager::PipeManager() {
	std::ifstream dataFile;
	dataFile.open("resource/properties/gameProperties.json");
	nlohmann::json jsonData;
	dataFile >> jsonData;
	pipeVerticalGap = jsonData["pipe_manager"]["pipe_vertical_gap"].get<float>();
	pipeHorizontalGap = jsonData["pipe_manager"]["pipe_horizontal_gap"].get<float>();

	createPipe();
}
PipeManager::~PipeManager() {
}
bool PipeManager::update(const sf::Time& deltaTime) {
	for (auto it = pipes.begin(); it != pipes.end(); ) {
		auto& pipe = *it;
		pipe.setPosition(pipe.getPosition().x - velocity * deltaTime.asSeconds(), pipe.getPosition().y);
		if (pipe.getPosition().x + pipe.getSize().x < 0) {
			it = pipes.erase(it);
		}
		else {
			it++;
		}
	}
	if (Constants::getFloat("WINDOW_WIDTH") - pipes.back().getPosition().x > pipeHorizontalGap) {
		createPipe();
	}
	return false;
}
void PipeManager::draw(sf::RenderTarget& renderer) {
	for (auto& pipe : pipes) {
		pipe.draw(renderer);
	}
}
std::vector<Pipe>& PipeManager::getPipes() {
	return pipes;
}
void PipeManager::createPipe() {
	float r = static_cast<float>(rand()) / RAND_MAX;
	float topHeight = floorf(100.f + r * 200.f);
	TopPipe topPipe(topHeight);
	topPipe.setPosition(Constants::getFloat("WINDOW_WIDTH"), 0);
	pipes.push_back(topPipe);

	float bottomHeight = Constants::getFloat("WINDOW_HEIGHT") - pipeVerticalGap - topHeight;
	BottomPipe bottomPipe(bottomHeight);
	bottomPipe.setPosition(Constants::getFloat("WINDOW_WIDTH"), Constants::getFloat("WINDOW_HEIGHT") - bottomHeight);
	pipes.push_back(bottomPipe);
}
void PipeManager::setVelocity(float vel) {
	velocity = vel;
}