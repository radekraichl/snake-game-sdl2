#pragma once

#include <string>
#include "InputManager.h"

class GameObject
{
public:
	GameObject() = delete;
	GameObject(const std::string& name);
	virtual ~GameObject() = default;

	virtual void start() {};
	virtual void update(float deltaTime, InputManager& inputManager) {};

	std::string getName() const;

private:
	const std::string name;
};
