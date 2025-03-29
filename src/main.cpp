#define SDL_MAIN_HANDLED

#include <cstdlib>
#include "Config.h"
#include "Graphics.h"
#include "GameScene.h"
#include "Random.h"

int main()
{
	Random::init();
	Graphics graphics;

	try
	{
		graphics.init(GAME_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
		GameScene gameScene(&graphics);
		gameScene.run();
	}
	catch (const std::runtime_error& e)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, e.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
