#pragma once
#include <vector>
#include "SFMLForward.h"
#include <string>

namespace mlg {
	class Scene;

	class SceneManager {
	public:
		SceneManager();
		~SceneManager();

		void update(const sf::Time &);
		void draw(sf::RenderTarget &);
		void handleEvent(const sf::Event &);

		bool isEmpty();
		void pushScene(Scene*);
		void popScene();
		void clearScenes();
		Scene* getScene(const std::string& name);
	private:
		enum class eSceneActionType {
			POP = 0,
			PUSH,
			CLEAR
		};
		struct SceneAction {
			Scene* scene;
			eSceneActionType type;
			SceneAction(eSceneActionType type, Scene* scene = nullptr) : type(type), scene(scene) {};
		};
		std::vector<SceneAction> actionQueue;
		std::vector<Scene*> scenes;

		void applyActions();
	};
}
