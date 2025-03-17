#pragma once

#include "GameObject.h"

class GraphicObject : public GameObject
{
public:
	GraphicObject(std::string name, SDL_Renderer* renderer);

protected:
	SDL_Renderer* renderer;
};
