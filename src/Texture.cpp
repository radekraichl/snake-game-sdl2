#include "Error.h"
#include "Texture.h"

// Constructor
Texture::Texture(const std::string& path, SDL_Renderer* renderer) :
	filePath(path), texture(nullptr)
{
	// Load the image as an SDL_Surface
	surface = IMG_Load(path.c_str());
	Error::assert(surface);

	// Create a texture from the surface
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	// Free the surface as it is no longer needed
	SDL_FreeSurface(surface);
	surface = nullptr;
	
	// Check if the texture was created successfully
	Error::assert(texture);
}

// Destructor
Texture::~Texture()
{
	if (surface)
	{
		SDL_FreeSurface(surface);
	}
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}

	SDL_Log("Destroy Texture: %s", filePath.c_str());
}

// Accessor method for texture
SDL_Texture* Texture::getTexture() const
{
	return texture;
}
