#include "GraphicObject.h"

GraphicObject::GraphicObject(std::string name, SDL_Renderer* renderer, std::shared_ptr<SDL_Rect> viewport) :
	GameObject(name), renderer(renderer)
{
	if (viewport)
	{
		viewportRect = std::make_unique<SDL_Rect>(*viewport);
	}
}

bool GraphicObject::hasViewportRect() const
{
	return viewportRect != nullptr;
}

// Setters
void GraphicObject::setViewportRect(int x, int y, int w, int h)
{
	if (viewportRect)
	{
		*viewportRect = SDL_Rect { x, y, w, h };
	}
	else
	{
		viewportRect = std::make_unique<SDL_Rect>(SDL_Rect { x, y, w, h });
	}
}

// Private methods
void GraphicObject::setViewportForRendering()
{
	if (viewportRect != nullptr)
	{
		SDL_RenderSetViewport(renderer, viewportRect.get());
	}
}

void GraphicObject::setDefaultViewportForRendering() const
{
	SDL_RenderSetViewport(renderer, nullptr);
}
