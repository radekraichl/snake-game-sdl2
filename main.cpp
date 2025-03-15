#define SDL_MAIN_HANDLED

#include <cstdlib>
#include "Config.h"
#include "Graphics.h"
#include "GameScene.h"
#include "Random.h"

int main()
{
	Graphics graphics;

	if (!graphics.init("Snake", WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		return EXIT_FAILURE;
	}

	Random::init();

	GameScene gameScene(&graphics);
	gameScene.run();

	return EXIT_SUCCESS;
}
