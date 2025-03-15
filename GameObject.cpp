#include "GameObject.h"

GameObject::GameObject(const std::string& name, SDL_Renderer* renderer) : name(name), renderer(renderer)
{
}

std::string GameObject::getName() const
{
	return name;
}
