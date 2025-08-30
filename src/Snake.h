#pragma once

#include <map>
#include <deque>
#include "GraphicObject.h"
#include "Sprite.h"
#include "Food.h"
#include "Config.h"
#include "Direction.h"

struct Position;

class Snake : public GraphicObject
{
public:
	Snake(const std::string name, std::shared_ptr<SDL_Rect> viewport, int startX, int startY);

	static const int TILE_SIZE = SNAKE_TILE_SIZE;

	void start() override;
	void update(float deltaTime) override;
	void render() override;
	void reset();

	// Getters
	std::deque<Position> getBody() const;
	Position getHeadPosition() const;

private:
	bool isAlive = true;
	int startX, startY;
	int segmentsToGrow;
	float timeAccumulator = 0.0f;
	float moveInterval = (float)SNAKE_START_MOVE_INTERVAL;
	Direction currentDirection = Direction::Right;
	std::deque<Position> body;
	std::map<std::string, std::unique_ptr<Sprite>> sprites;
	Food* food;
	
	// Private methods
	void Grow(int amount);
	void increaseSpeed(float amount);
	void constrainDirection(Direction newDirection);
	void handleFoodEaten();

	// Private getters
	int getRotationAngle(const Position& prev, const Position& current, const Position& next) const;
	int getTailRotationAngle(const Position& current, const Position& prev) const;
};
