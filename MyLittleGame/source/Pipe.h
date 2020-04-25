#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "Updateable.h"
#include "Drawable.h"

namespace mlg {
	class Pipe : public sf::RectangleShape, public Updateable, public Drawable
	{
	public:
		Pipe(float height);
		virtual ~Pipe();
		void draw(sf::RenderTarget&) override;
		bool update(const sf::Time& deltaTime) override;
	private:
		float width;
		float height;
	};
	class TopPipe : public Pipe {
	public:
		TopPipe(float height);
		~TopPipe();
	};
	class BottomPipe : public Pipe {
	public:
		BottomPipe(float height);
		~BottomPipe();
	};
}

