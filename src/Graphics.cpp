#include "Graphics.h"
#include "Error.h"

Graphics::Graphics() : window(nullptr), renderer(nullptr) {}

Graphics::~Graphics()
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
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void Graphics::init(const char* title, int width, int height)
{
	Error::assert(SDL_Init(SDL_INIT_VIDEO) == 0);
	SDL_Log("SDL_Init");

	Error::assert((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG));
	SDL_Log("IMG_Init");

	Error::assert(TTF_Init() == 0);
	SDL_Log("TTF_Init");

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	Error::assert(window);
	SDL_Log("SDL_CreateWindow");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Error::assert(renderer);
	SDL_Log("SDL_CreateRenderer");
}

SDL_Window* Graphics::getWindow() const
{
	return window;
}

SDL_Renderer* Graphics::getRenderer() const
{
	return renderer;
}
