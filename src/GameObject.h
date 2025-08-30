#pragma once

#include <string>

struct SDL_Renderer;
class InputManager;
class Scene;

class GameObject
{
public:
	GameObject() = delete;
	GameObject(const std::string& name);
	virtual ~GameObject() = default;

	virtual void init(SDL_Renderer* renderer, Scene* scene, InputManager* inputManager);

	virtual void start() {};
	virtual void update(float deltaTime) {};

	// Getters
	std::string getName() const;
	Scene* getScene() const;

private:
	const std::string name;

protected:
	Scene* scene;
	InputManager* inputManager;
};
