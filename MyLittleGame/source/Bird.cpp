#include "Bird.h"
#include "ManagersInstance.h"
#include "ResourceManager.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Time.hpp"

using namespace mlg;
Bird::Bird() {
	velocity = 0.0f;
	acc = 500.0f;
	width = 40;
	height = 30;

	setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/bluebird-downflap.png"));
	setSize({ width, height });
	setPosition(100.f, 100.f);
}
Bird::~Bird() {
}
void Bird::init() {
}
void Bird::fly() {
	velocity = -300.f;
}
bool Bird::update(const sf::Time& deltaTime) {
	velocity = velocity + acc * deltaTime.asSeconds();
	float birdPos = getPosition().y;
	birdPos += velocity * deltaTime.asSeconds();
	setPosition(getPosition().x, birdPos);
	return false;
}
void Bird::draw(sf::RenderTarget& renderer) {
	renderer.draw(*this);
}