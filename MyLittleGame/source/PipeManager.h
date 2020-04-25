#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "Updateable.h"
#include "Drawable.h"
#include "Pipe.h"
namespace mlg {
	class PipeManager : public Updateable, public Drawable
	{
	public:
		PipeManager();
		~PipeManager();
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
		std::vector<Pipe>& getPipes();
		void createPipe();
		void setVelocity(float);
	private:
		float velocity;
		float pipeVerticalGap;
		float pipeHorizontalGap;
		std::vector<Pipe> pipes;
	};
}

