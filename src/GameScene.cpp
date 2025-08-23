#include <vector>
#include <memory>
#include "GameScene.h"
#include "Scene.h"
#include "GuiBackground.h"
#include "ScoreText.h"
#include "GameBackground.h"
#include "Walls.h"
#include "Food.h"
#include "Snake.h"

// Constructor
GameScene::GameScene(Graphics* graphics) : Scene(graphics)
{
	Init();
}

void GameScene::addObjects()
{
	auto gameWindow = std::make_shared<SDL_Rect>(SDL_Rect{ 0, UI_HEIGHT, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT });
	auto gameArea = std::make_shared<SDL_Rect>(SDL_Rect{ WALL_TILE_SIZE, UI_HEIGHT + WALL_TILE_SIZE, BOARD_WIDTH, BOARD_HEIGHT });

	addObject(std::make_unique<GuiBackground>("gui_background"));
	addObject(std::make_unique<ScoreText>("score_text"));
	addObject(std::make_unique<GameBackground>("game_background", gameArea));
	addObject(std::make_unique<Walls>("walls", gameWindow));
	addObject(std::make_unique<Food>("food", gameArea));
	addObject(std::make_unique<Snake>("snake", gameArea, 2 * Snake::TILE_SIZE, (BOARD_VERTICAL_TILES / 2) * Snake::TILE_SIZE));
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
			obj->update(deltaTime);
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

