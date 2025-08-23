#pragma once

#include <vector>
#include "sprite.h"
#include "GraphicObject.h"

class InputManager;
class Snake;

class Food : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void update(float deltaTime, InputManager& inputManager) override;
	void render() override;

private:
	Snake* snake;
	std::vector<std::unique_ptr<Sprite>> foodSprites;

	// Private methods
	void addFood();
};
