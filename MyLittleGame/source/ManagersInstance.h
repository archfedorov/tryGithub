#pragma once
namespace mlg {
	class SceneManager;
	class ResourceManager;
	class ManagersInstance {
	public:
		//mayer's singletone
		static ManagersInstance* getInstance();
		SceneManager* getSceneManager();
		ResourceManager* getResourceManager();
	private:
		ManagersInstance();
		~ManagersInstance();
		SceneManager* sceneManager;
		ResourceManager* resourceManager;
	};
}

#define GET_SCENE_MANAGER() mlg::ManagersInstance::getInstance()->getSceneManager()
#define GET_RESOURCE_MANAGER() mlg::ManagersInstance::getInstance()->getResourceManager()
