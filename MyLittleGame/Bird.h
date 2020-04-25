#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "Updateable.h"
#include "Drawable.h"

namespace mlg {
	class Bird : public sf::RectangleShape, public Updateable, public Drawable
	{
	public:
		Bird();
		~Bird();
		void fly();
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
	private:
		void init();
		float velocity;
		float acc;
		float width;
		float height;
	};
}

