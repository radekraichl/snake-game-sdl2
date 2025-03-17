#include "GraphicObject.h"

GraphicObject::GraphicObject(std::string name, SDL_Renderer* renderer) : GameObject(name), renderer(renderer)
{
}
