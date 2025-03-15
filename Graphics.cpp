#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"

Graphics::Graphics() : window(nullptr), renderer(nullptr) {}

Graphics::~Graphics()
{
	cleanup();
}

bool Graphics::init(const char* title, int width, int height)
{
	if (!initSDL())
	{
		return false;
	}
	if (!createWindowAndRenderer(title, width, height))
	{
		cleanup();
		return false;
	}
	if (!imageInit())
	{
		cleanup();
		return false;
	}
	return true;
}

bool Graphics::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL_Init Error: %s", SDL_GetError());
		return false;
	}
	SDL_Log("SDL_Init");
	return true;
}

bool Graphics::createWindowAndRenderer(const char* title, int width, int height)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	if (!window)
	{
		SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
		return false;
	}
	SDL_Log("SDL_CreateWindow");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		window = nullptr;
		return false;
	}
	SDL_Log("SDL_CreateRenderer");
	return true;
}

bool Graphics::imageInit()
{
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		SDL_Log("IMG_Init Error: %s", IMG_GetError());
		return false;
	}
	SDL_Log("IMG_Init");
	return true;
}

void Graphics::cleanup()
{
	if (renderer)
	{
		SDL_DestroyRenderer(renderer);
		SDL_Log("SDL_DestroyRenderer");
		renderer = nullptr;
	}
	if (window)
	{
		SDL_DestroyWindow(window);
		SDL_Log("SDL_DestroyWindow");
		window = nullptr;
	}
	SDL_Quit();
	IMG_Quit();
}

SDL_Window* Graphics::getWindow() const
{
	return window;
}

SDL_Renderer* Graphics::getRenderer() const
{
	return renderer;
}
