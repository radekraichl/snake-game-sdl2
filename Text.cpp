#include <SDL_ttf.h>
#include "Error.h"
#include "Text.h"

Text::Text(const std::string& filePath, int size, SDL_Renderer* const renderer) :
	filePath(filePath), size(size), renderer(renderer), surface(nullptr), texture(nullptr)
{
	Error::assert(font = TTF_OpenFont(filePath.c_str(), size));
	position = Position(0, 0);
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

	bounds.x = static_cast<float>(position.x);
	bounds.y = static_cast<float>(position.y);

	bounds.width = static_cast<float>(surface->w);
	bounds.height = static_cast<float>(surface->h);
}

void Text::setColor(SDL_Color col)
{
	color = col;
}

void Text::setPositionCentered(float x, float y)
{
	// Center the text based on its bounds
	position = Position
	(
		static_cast<int>(x - bounds.width / 2.0f),
		static_cast<int>(y - bounds.height / 2.0f)
	);

	// Update bounds position as well
	bounds.x = static_cast<float>(position.x);
	bounds.y = static_cast<float>(position.y);
}

void Text::print()
{
	print(static_cast<float>(position.x), static_cast<float>(position.y));
}

void Text::print(float posX, float posY)
{
	SDL_FRect destRect = { posX, posY, static_cast<float>(surface->w), static_cast<float>(surface->h) };
	SDL_RenderCopyF(renderer, texture, nullptr, &destRect);
}

int Text::getWidth() const
{
	return surface->w;
}

int Text::getHeight() const
{
	return surface->h;
}
