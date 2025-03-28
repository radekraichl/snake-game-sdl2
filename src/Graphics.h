#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool init(const char* title, int width, int height);

	SDL_Window* getWindow() const;
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool initSDL();
	bool initImage();
	bool initTTF();
	bool createWindowAndRenderer(const char* title, int width, int height);
	void cleanup();
};
