#include "GraphicObject.h"
#include "Error.h"

GraphicObject::GraphicObject(std::string name, std::shared_ptr<SDL_Rect> viewport) : 
	GameObject(name), renderer(nullptr)
{
	if (viewport)
	{
		viewportRect = std::make_unique<SDL_Rect>(*viewport);
	}
}

void GraphicObject::init(SDL_Renderer* renderer, Scene* scene, InputManager* inputManager)
{
	this->renderer = renderer;
	this->scene = scene;
	this->inputManager = inputManager;
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
		*viewportRect = SDL_Rect{ x, y, w, h };
	}
	else
	{
		viewportRect = std::make_unique<SDL_Rect>(SDL_Rect{ x, y, w, h });
	}
}

// Private methods
void GraphicObject::setViewportForRendering()
{
	Error::assert(SDL_RenderSetViewport(renderer, viewportRect.get()) == 0);
}

void GraphicObject::setDefaultViewportForRendering() const
{
	Error::assert(SDL_RenderSetViewport(renderer, nullptr) == 0);
}
