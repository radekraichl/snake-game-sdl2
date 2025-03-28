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

	if (!graphics.init("Snake", WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		return EXIT_FAILURE;
	}

	GameScene gameScene(&graphics);
	gameScene.run();

	return EXIT_SUCCESS;
}
