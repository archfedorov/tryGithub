#pragma once
namespace mlg {
	class SceneManager;
	class ResourceManager;
	class ManagersInstance {
	public:
		SceneManager* getSceneManager();
		ResourceManager* getResourceManager();

		//mayer's singletone
		static ManagersInstance* getInstance();
	private:
		ManagersInstance();
		~ManagersInstance();
		SceneManager* sceneManager;
		ResourceManager* resourceManager;
	};
}

#define GET_SCENE_MANAGER() mlg::ManagersInstance::getInstance()->getSceneManager()
#define GET_RESOURCE_MANAGER() mlg::ManagersInstance::getInstance()->getResourceManager()
