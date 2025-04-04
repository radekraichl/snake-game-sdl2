#pragma once

#include <vector>
#include <memory>
#include "GameObject.h"
#include "InputManager.h"

class Graphics;
class GraphicObject;
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
};
