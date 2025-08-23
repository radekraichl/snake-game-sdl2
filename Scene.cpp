#include "Graphics.h"
#include "Scene.h"
#include "GameObject.h"
#include "GraphicObject.h"

Scene::Scene(Graphics* graphics) : graphics(graphics), renderer(graphics->getRenderer()), running(true)
{
}

void Scene::Init()
{
	addObjects();
	InitObjects();
}

void Scene::InitObjects()
{
	for (auto& obj : gameObjects)
	{
		obj->init(renderer, this);
	}

	for (auto& obj : gameObjects)
	{
		obj->start();
	}
}

void Scene::addObject(std::unique_ptr<GameObject> object)
{
	// Add the object to the gameObjects vector
	gameObjects.emplace_back(std::move(object));

	// If the object is of type GraphicObject, add it also to the renderable graphicObjects list
	if (auto graphicObj = dynamic_cast<GraphicObject*>(gameObjects.back().get()))
	{
		graphicObjects.push_back(graphicObj);
	}
}
