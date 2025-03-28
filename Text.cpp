#include <SDL_ttf.h>
#include "Text.h"

Text::Text(const std::string& filePath, int size, SDL_Renderer* const renderer) :
	filePath(filePath), size(size), renderer(renderer)
{
	font = TTF_OpenFont(filePath.c_str(), size);
	if (!font)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to load font: %s", SDL_GetError());
	}

	color = { 255, 255, 255, 255 };
	setText("");
}

Text::~Text()
{
	if (surface != nullptr)
	{
		SDL_FreeSurface(surface);
	}

	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		SDL_Log("SDL_DestroyTexture %s", filePath.c_str());
	}
}

void Text::setText(std::string text)
{
	surface = TTF_RenderText_Solid(font, text.c_str(), color);  // TODO error assert
	texture = SDL_CreateTextureFromSurface(renderer, surface);  // TODO error assert
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
