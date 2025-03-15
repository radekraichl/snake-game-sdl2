#pragma once

#include <map>
#include <deque>
#include "GameObject.h"
#include "Sprite.h"
#include "Config.h"

struct Position;

class Snake : public GameObject
{
public:
	static const int TILE_SIZE = SNAKE_TILE_SIZE;
	Snake(const std::string& name, int x, int y, SDL_Renderer* renderer);

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
