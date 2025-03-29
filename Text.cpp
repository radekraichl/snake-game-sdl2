#include <SDL_ttf.h>
#include "Error.h"
#include "Text.h"

Text::Text(const std::string& filePath, int size, SDL_Renderer* const renderer) :
	filePath(filePath), size(size), renderer(renderer), surface(nullptr), texture(nullptr)
{
	Error::assert(font = TTF_OpenFont(filePath.c_str(), size));
	color = { 255, 255, 255, 255 };
}

Text::~Text()
{
	if (font != nullptr)
	{
		TTF_CloseFont(font);
	}
	if (surface != nullptr)
	{
		SDL_FreeSurface(surface);
	}
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}

	SDL_Log("Destroy Text: %s", filePath.c_str());
}

void Text::setText(std::string text)
{
	Error::assert(surface = TTF_RenderText_Solid(font, text.c_str(), color));
	Error::assert(texture = SDL_CreateTextureFromSurface(renderer, surface));
}

void Text::setColor(SDL_Color col)
{
	color = col;
}

void Text::print(int posX, int posY)
{
	SDL_Rect destRect = { posX, posY, surface->w, surface->h };
	SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

int Text::getWidth() const
{
	return surface->w;
}

int Text::getHeight() const
{
	return surface->h;
}
