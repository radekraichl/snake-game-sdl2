#define SDL_MAIN_HANDLED

#include <cstdlib>
#include "Config.h"
#include "Graphics.h"
#include "GameScene.h"
#include "Random.h"
#include "Audio.h"

int main()
{
	Random::init();
	Graphics graphics;
	Audio audio;

	try
	{
		graphics.init(GAME_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
		audio.Init();
		GameScene gameScene(&graphics);
		gameScene.run();
	}
	catch (const std::runtime_error& e)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, e.what());
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "A failure occurred", e.what(), nullptr);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
