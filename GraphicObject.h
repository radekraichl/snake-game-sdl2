#pragma once

#include <SDL.h>
#include <memory>
#include "Scene.h"

class InputManager;

class GraphicObject : public GameObject
{
public:
	// Constructors
	GraphicObject() = delete;
	GraphicObject(std::string name, std::shared_ptr<SDL_Rect> viewport = nullptr);

	// Methods
	void init(SDL_Renderer* renderer, Scene* scene, InputManager* inputManager) override;

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
