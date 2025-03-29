#pragma once

#include <memory>
#include "GameObject.h"
#include "Graphics.h"

class GraphicObject : public GameObject
{
public:
	// Construcors
	GraphicObject() = delete;
	GraphicObject(std::string name, SDL_Renderer* renderer, std::shared_ptr<SDL_Rect> viewport = nullptr);

	virtual void render() = 0;

	void renderInViewport() 
	{
		setViewportForRendering();
		render();
		setDefaultViewportForRendering();
	}

	bool hasViewportRect() const;

	// Setters
	void setViewportRect(int x, int y, int w, int h);

protected:
	SDL_Renderer* const renderer;

private:
	std::unique_ptr<SDL_Rect> viewportRect = nullptr;
	
	// Private methods
	void setViewportForRendering();
	void setDefaultViewportForRendering() const;
};
