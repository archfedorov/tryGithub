#include "Pipe.h"
#include "ManagersInstance.h"
#include "ResourceManager.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Time.hpp"

using namespace mlg;
Pipe::Pipe(float height) {
	width = 50.f;
	this->height = height;
	setSize({ width, height });
}
Pipe::~Pipe() {
}
bool Pipe::update(const sf::Time& deltaTime) {
	return false;
}
void Pipe::draw(sf::RenderTarget& renderer) {
	renderer.draw(*this);
}

TopPipe::TopPipe(float height): Pipe(height) {
	setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/pipe-green-reverse.png"));
}
TopPipe::~TopPipe() {
}
BottomPipe::BottomPipe(float height) : Pipe(height) {
	setTexture(&GET_RESOURCE_MANAGER()->getTexture("resource/images/pipe-green.png"));
}
BottomPipe::~BottomPipe() {
}