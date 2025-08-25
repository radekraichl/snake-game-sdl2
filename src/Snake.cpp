#include "Snake.h"
#include "Direction.h"
#include "InputManager.h"
#include "GameScene.h"

Snake::Snake(const std::string name, std::shared_ptr<SDL_Rect> viewport, int startX, int startY) :
	GraphicObject(name, viewport), startX(startX), startY(startY), segmentsToGrow(0)
{
	reset();
}

void Snake::start()
{
	food = scene->findObjectByType<Food>();
	food->onFoodEaten.connect([this]() { handleFoodEaten(); });

	sprites.emplace("head", std::make_unique<Sprite>("assets/images/snake_head.png", renderer, TILE_SIZE));
	sprites.emplace("body", std::make_unique<Sprite>("assets/images/snake_body.png", renderer, TILE_SIZE));
	sprites.emplace("turn", std::make_unique<Sprite>("assets/images/snake_turn.png", renderer, TILE_SIZE));
	sprites.emplace("tail", std::make_unique<Sprite>("assets/images/snake_tail.png", renderer, TILE_SIZE));
}

void Snake::reset()
{
	body.clear();
	isAlive = true;
	timeAccumulator = 0.0f;
	currentDirection = Direction::Right;

	for (int i = 0; i < 4; i++)
	{
		body.push_front(Position(startX + i * TILE_SIZE, startY));
	}
}

void Snake::update(float deltaTime)
{
	timeAccumulator += deltaTime;

	// RESET - R KEY
	if (inputManager->GetLastKeyPressed() == SDLK_r)
	{
		reset();
		inputManager->SetNoneDirection();
	}

	if (timeAccumulator >= moveInterval && isAlive)
	{
		if (inputManager->GetDirection() != Direction::None)
		{
			constrainDirection(inputManager->GetDirection());
		}

		Position newHead = body.front();

		switch (currentDirection)
		{
			case Direction::Up:    newHead.y -= 1 * TILE_SIZE; break;
			case Direction::Down:  newHead.y += 1 * TILE_SIZE; break;
			case Direction::Left:  newHead.x -= 1 * TILE_SIZE; break;
			case Direction::Right: newHead.x += 1 * TILE_SIZE; break;
		}

		body.push_front(newHead);

		// Check if the snake has collided with itself
		for (size_t i = 1; i < body.size(); ++i)
		{
			if (body[i] == body[0])
			{
				isAlive = false;
				body.pop_front();
				return;
			}
		}

		// Check if the snake has collided with the walls
		if (body[0].x < 0 ||
			body[0].y < 0 ||
			body[0].x > BOARD_WIDTH - SNAKE_TILE_SIZE ||
			body[0].y > BOARD_HEIGHT - SNAKE_TILE_SIZE)
		{
			isAlive = false;
			body.pop_front();
			return;
		}

		if (segmentsToGrow == 0)
		{
			body.pop_back();
		}
		else
		{
			--segmentsToGrow;
		}

		timeAccumulator = 0.0f;
	}
}

void Snake::render()
{
	// Render head
	sprites["head"]->renderSprite(body[0].x, body[0].y, static_cast<float>(currentDirection));

	// Render body
	for (size_t i = 1; i < body.size() - 1; ++i)
	{
		if (body[i - 1].x == body[i + 1].x || body[i - 1].y == body[i + 1].y)
		{
			int rotation = getRotationAngle(body[i - 1], body[i], body[i + 1]);
			sprites["body"]->renderSprite(body[i].x, body[i].y, (float)rotation);
		}
		else
		{
			int rotation = getRotationAngle(body[i - 1], body[i], body[i + 1]);
			sprites["turn"]->renderSprite(body[i].x, body[i].y, (float)rotation);
		}
	}

	// Render tail
	int rotation = getTailRotationAngle(body[body.size() - 1], body[body.size() - 2]);
	sprites["tail"]->renderSprite(body[body.size() - 1].x, body[body.size() - 1].y, (float)rotation);
}

// Private methods
void Snake::constrainDirection(Direction newDirection)
{
	if ((currentDirection == Direction::Up && newDirection == Direction::Down) ||
		(currentDirection == Direction::Down && newDirection == Direction::Up) ||
		(currentDirection == Direction::Left && newDirection == Direction::Right) ||
		(currentDirection == Direction::Right && newDirection == Direction::Left))
	{
		return;
	}

	currentDirection = newDirection;
}

void Snake::Grow(int amount)
{
	segmentsToGrow += amount;
}

void Snake::increaseSpeed(float amount)
{
	moveInterval -= amount;
}

void Snake::handleFoodEaten()
{
	Grow(1);
	increaseSpeed(0.004f);
}

// Private getters
int Snake::getRotationAngle(const Position& prev, const Position& current, const Position& next) const
{
	// Direct
	if (prev.y == current.y && current.y == next.y) return 0;
	if (prev.x == current.x && current.x == next.x) return 90;

	// Turns
	int deltaPrevX = prev.x - current.x;
	int deltaPrevY = prev.y - current.y;
	int deltaNextX = next.x - current.x;
	int deltaNextY = next.y - current.y;

	if ((deltaPrevX < 0 && deltaNextY > 0) || (deltaNextX < 0 && deltaPrevY > 0)) return 0;
	if ((deltaPrevX < 0 && deltaNextY < 0) || (deltaNextX < 0 && deltaPrevY < 0)) return 90;
	if ((deltaPrevX > 0 && deltaNextY < 0) || (deltaNextX > 0 && deltaPrevY < 0)) return 180;
	if ((deltaPrevX > 0 && deltaNextY > 0) || (deltaNextX > 0 && deltaPrevY > 0)) return 270;

	return 0;
}

int Snake::getTailRotationAngle(const Position& current, const Position& prev) const
{
	if (current.x < prev.x) return 0;
	if (current.y < prev.y) return 90;
	if (current.x > prev.x) return 180;
	if (current.y > prev.y) return 270;

	return 0;
}

// Getters
std::deque<Position> Snake::getBody() const
{
	return body;
}

Position Snake::getHeadPosition() const
{
	return body[0];
}
