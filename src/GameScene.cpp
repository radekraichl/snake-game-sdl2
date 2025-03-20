#include <vector>
#include <memory>
#include "GameBackground.h"
#include "InputManager.h"
#include "SpriteSheet.h"
#include "GameScene.h"
#include "Graphics.h"
#include "Snake.h"
#include "Walls.h"

// Constructor
GameScene::GameScene(Graphics* graphics) : running(true), renderer(graphics->getRenderer())
{
	auto boardViewport = std::make_shared<SDL_Rect>(SDL_Rect { 0, UI_HEIGHT, BOARD_WIDTH, BOARD_HEIGHT });

	addObject(std::make_unique<GameBackground>("game_background", renderer, boardViewport));
	addObject(std::make_unique<Walls>("walls", renderer, boardViewport));
	addObject(std::make_unique<Snake>("snake", renderer, boardViewport, 1 * Snake::TILE_SIZE, 16 * Snake::TILE_SIZE));

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
		}

		for (GraphicObject* obj : graphicObjects)
		{
			if (obj->hasViewportRect())
			{
				obj->renderInViewport();
			}
			else
			{
				obj->render();
			}
		}

		if (inputManager.GetLastKeyPressed() == SDLK_ESCAPE)
		{
			break;
		}

		SDL_RenderPresent(renderer);
	}
}

void GameScene::addObject(std::unique_ptr<GameObject> object)
{
	// Add the object to the gameObjects vector
	gameObjects.emplace_back(std::move(object));

	// If the object is of type GraphicObject, add it also to the renderable graphicObjects list
	if (auto graphicObj = dynamic_cast<GraphicObject*>(gameObjects.back().get()))
	{
		graphicObjects.push_back(graphicObj);
	}
}
