#pragma once

#include <SDL_image.h>
#include <string>

class Texture
{
public:
	Texture(const std::string& path, SDL_Renderer* renderer);
	~Texture();

	SDL_Texture* getTexture() const;

private:
	SDL_Surface* surface;
	SDL_Texture* texture;
	std::string filePath;
};
