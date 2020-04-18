#pragma once
#include "SFMLForward.h"
namespace mlg {
	class EventHandler {
	public:
		virtual ~EventHandler() = default;
		virtual bool handleEvent(const sf::Event&) { return false; };
	};
}
