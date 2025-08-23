#pragma once

#include <SDL.h>
#include <memory>
#include "Scene.h"

class GraphicObject : public GameObject
{
public:
	// Construcors
	GraphicObject() = delete;
	GraphicObject(std::string name, std::shared_ptr<SDL_Rect> viewport = nullptr);
	void init(SDL_Renderer* renderer, Scene* scene) override;

	virtual void render() {};

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
	SDL_Renderer* renderer;

private:
	std::unique_ptr<SDL_Rect> viewportRect = nullptr;
	
	// Private methods
	void setViewportForRendering();
	void setDefaultViewportForRendering() const;
};
