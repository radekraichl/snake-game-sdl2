#pragma once

#include <vector>
#include <memory>
#include "Snake.h"
#include "GameObject.h"
#include <span>

class Graphics;
struct SDL_Renderer;

class GameScene
{
public:
	GameScene(Graphics* graphics);
	~GameScene() = default;

	void run();
	void addObject(std::unique_ptr<GameObject> obj);

private:
	bool running;
	InputManager inputManager;
	SDL_Renderer* renderer;
	std::vector<std::unique_ptr<GameObject>> gameObjects;
	std::vector<GraphicObject*> graphicObjects;

	// Private methods
	std::vector<GraphicObject* const> getRenderableObjects() const;
};
