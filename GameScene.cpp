#include "Grass.h"
#include "Snake.h"
#include "Graphics.h"
#include "GameScene.h"
#include "SpriteSheet.h"
#include "InputManager.h"

// Constructor
GameScene::GameScene(Graphics* graphics) : running(true), renderer(graphics->getRenderer())
{
	addObject(std::make_unique<Grass>("Grass", renderer));
	addObject(std::make_unique<Snake>("Snake", 1 * Snake::TILE_SIZE, 16 * Snake::TILE_SIZE, renderer));

	for (auto& obj : gameObjects)
	{
		obj->start();
	}
}

void GameScene::run()
{
	Uint32 lastTime = SDL_GetTicks();

	while (!inputManager.WasQuitRequested())
	{
		Uint32 currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;
		SDL_RenderClear(renderer);
		inputManager.Update();

		for (auto& obj : gameObjects)
		{
			obj->update(deltaTime, inputManager);
			obj->render();
		}

		if (inputManager.GetLastKeyPressed() == SDLK_ESCAPE)
		{
			break;
		}

		SDL_RenderPresent(renderer);
	}
}

void GameScene::addObject(std::unique_ptr<GameObject> obj)
{
	gameObjects.push_back(std::move(obj));
}
