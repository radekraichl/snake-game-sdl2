#include "GameObject.h"

GameObject::GameObject(const std::string& name) : name(name)
{ 
}

std::string GameObject::getName() const
{
	return name;
}
