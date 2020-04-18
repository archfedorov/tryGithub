#pragma once
namespace sf {
	class RenderTarget;
}
namespace mlg {
	class Drawable {
	public:
		virtual ~Drawable() = default;
		virtual void draw(sf::RenderTarget&) = 0;
	};
}
