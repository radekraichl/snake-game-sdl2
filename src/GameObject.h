#pragma once
#include <string>
#include "InputManager.h"

class GameObject
{
public:
	GameObject() = delete;
	GameObject(const std::string& name, SDL_Renderer* renderer);
	virtual ~GameObject() = default;

	virtual void start() {};
	virtual void update(float deltaTime, InputManager& inputManager) {};
	virtual void render() {};

	std::string getName() const;

protected:
	SDL_Renderer* renderer;

private:
	const std::string name;
};
