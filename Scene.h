#pragma once

#include <vector>
#include <memory>
#include "InputManager.h"
#include "GameObject.h"
#include "GraphicObject.h"

class SDL_Renderer;
class Graphics;
class GameObject;
class GraphicObject;

class Scene
{
public:
	Scene(Graphics* graphics);
	void Init();
	void InitObjects();
	virtual void run() = 0;
	virtual void addObjects() = 0;

	template<typename T>
	T* findObjectByType()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "T must derive from GameObject");

		for (auto& obj : gameObjects)
		{
			if (T* casted = dynamic_cast<T*>(obj.get()))
			{
				return casted; // returns the first object of type T
			}
		}
		return nullptr; // no object found
	}

protected:
	Graphics* graphics;
	SDL_Renderer* renderer;
	InputManager inputManager;
	bool running;
	std::vector<std::unique_ptr<GameObject>> gameObjects;
	std::vector<GraphicObject*> graphicObjects;

	void addObject(std::unique_ptr<GameObject> obj);
};
