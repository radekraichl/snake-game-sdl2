#pragma once

#include "GraphicObject.h"
#include "SpriteSheet.h"

class Walls : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void render() override;

private:
	std::unique_ptr<SpriteSheet> sheet;
};
