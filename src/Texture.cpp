#include "Texture.h"

// Constructor
Texture::Texture(const std::string& path, SDL_Renderer* renderer) : filePath(path), texture(nullptr)
{
	// Load the image as an SDL_Surface
	surface = IMG_Load(path.c_str());
	if (surface == nullptr)
	{
		SDL_LogError(0, "IMG_Load Error: %s", IMG_GetError());
		SDL_Quit();
		return;
	}

	// Create a texture from the surface
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == nullptr)
	{
		SDL_FreeSurface(surface);  // Free the surface if texture creation fails
		SDL_LogError(0, "SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
		return;
	}

	// Free the surface as it is no longer needed
	SDL_FreeSurface(surface);
}

// Destructor
Texture::~Texture()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		SDL_Log("SDL_DestroyTexture %s", filePath.c_str());
	}
}

// Accessor method for texture
SDL_Texture* Texture::getTexture() const
{
	return texture;
}
