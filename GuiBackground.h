#pragma once

#include "Config.h"
#include "GraphicObject.h"
#include "SpriteSheet.h"

class GuiBackground : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void render() override;

	static constexpr int TILE_SIZE = UI_SCORE_BAR_TILE_SIZE;	

private:
	std::unique_ptr<SpriteSheet> spriteSheet;
};

