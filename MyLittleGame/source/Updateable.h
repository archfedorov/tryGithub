#pragma once
namespace sf {
	class Time;
}
namespace mlg {
	class Updateable {
	public:
		virtual ~Updateable() = default;
		virtual bool update(const sf::Time& deltaTime) { return false; };
	};
}
