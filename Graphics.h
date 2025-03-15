#pragma once

struct SDL_Window;
struct SDL_Renderer;

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
	bool createWindowAndRenderer(const char* title, int width, int height);
	bool imageInit();
	void cleanup();
};
