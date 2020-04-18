#pragma once
#include "Updateable.h"
#include "Drawable.h"
#include "EventHandler.h"

namespace mlg {
	class Scene: public Updateable, public Drawable, public EventHandler {
	public:
		virtual ~Scene() = default;
		
		virtual void onPush() {};
		virtual void onPop() {};
	private:

	};
}
