#include <SDL.h>
#include "GameObject.h"
#include "InputManager.h"

GameObject::GameObject(const std::string& name) : name(name), scene(nullptr)
{
}

void GameObject::init(SDL_Renderer* renderer, Scene* scene)
{
	this->scene = scene;
}

std::string GameObject::getName() const
{
	return name;
}

Scene* GameObject::getScene() const
{
	return scene;
}
