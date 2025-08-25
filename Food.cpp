#include "Config.h"
#include "Random.h"
#include "Food.h"
#include "Snake.h"

void Food::start()
{
	eatSound = std::make_unique<Sound>("assets/sounds/eat.wav");
	snake = scene->findObjectByType<Snake>();

	for (size_t i = 0; i < 30; i++)
	{
		addFood();
	}
}

void Food::update(float deltaTime)
{
	if (snake)
	{
		auto headPos = snake->getHeadPosition();

		for (auto it = foodSprites.begin(); it != foodSprites.end();)
		{
			auto foodPos = (*it)->getPosition();

			if (headPos == foodPos)
			{
				it = foodSprites.erase(it); // Erases the object and returns a valid iterator
				if (onFoodEaten)
				{
					onFoodEaten.emit();
					eatSound->Play();
				}
			}
			else
			{
				++it;
			}
		}
	}
}

void Food::render()
{
	for (auto& foodSprite : foodSprites)
	{
		foodSprite->renderSprite();
	}
}

void Food::addFood()
{
	int tileX, tileY;
	bool valid = false;

	while (!valid)
	{
		tileX = Random::getInt(0, BOARD_HORIZONTAL_TILES);
		tileY = Random::getInt(0, BOARD_VERTICAL_TILES);

		Position newPos{ tileX * BOARD_TILE_SIZE, tileY * BOARD_TILE_SIZE };
		valid = true;

		// Check against snake body
		for (const auto& bodyPart : snake->getBody())
		{
			if (bodyPart.x == newPos.x && bodyPart.y == newPos.y)
			{
				valid = false;
				break;
			}
		}

		// Check against existing food
		if (valid)
		{
			for (const auto& food : foodSprites)
			{
				if (food->getPosition().x == newPos.x && food->getPosition().y == newPos.y)
				{
					valid = false;
					break;
				}
			}
		}
	}

	auto foodSprite = std::make_unique<Sprite>("assets/images/chip.png", renderer, 32);
	foodSprite->setPosition(tileX * BOARD_TILE_SIZE, tileY * BOARD_TILE_SIZE);
	foodSprites.emplace_back(std::move(foodSprite));
}
