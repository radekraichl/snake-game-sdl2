#pragma once

#include <SDL_image.h>
#include <string>

class Texture
{
private:
	SDL_Surface* surface;
	SDL_Texture* texture;

	std::string filePath;
public:
	Texture(const std::string& path, SDL_Renderer* renderer);
	~Texture();

	SDL_Texture* getTexture() const;
};
