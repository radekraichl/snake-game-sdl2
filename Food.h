#pragma once

#include <vector>
#include <functional>
#include "sprite.h"
#include "Sound.h"
#include "GraphicObject.h"
#include "Signal.h"

class InputManager;
class Snake;

class Food : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void update(float deltaTime) override;
	void render() override;

	// Callback
	Signal<void> onFoodEaten;

private:
	Snake* snake;
	std::unique_ptr<Sound> eatSound;
	std::vector<std::unique_ptr<Sprite>> foodSprites;

	// Private methods
	void addFood();
};
