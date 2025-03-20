#pragma once

#include <map>
#include <deque>
#include "GraphicObject.h"
#include "Sprite.h"
#include "Config.h"

struct Position;

class Snake : public GraphicObject
{
public:
	Snake(const std::string name, SDL_Renderer* renderer, std::shared_ptr<SDL_Rect> viewport, int startX, int startY);

	static const int TILE_SIZE = SNAKE_TILE_SIZE;

	void start() override;
	void update(float deltaTime, InputManager& inputManager) override;
	void render() override;

private:
	bool isAlive = true;
	int startX, startY;
	float timeAccumulator = 0.0f;
	float moveInterval = SNAKE_MOVE_INTERVAL;
	std::deque<Position> body;
	std::map<std::string, std::unique_ptr<Sprite>> sprites;
	Direction currentDirection = Direction::Right;

	void constrainDirection(Direction newDirection);

	int getRotationAngle(const Position& prev, const Position& current, const Position& next) const;
	int getTailRotationAngle(const Position& current, const Position& prev) const;
};
