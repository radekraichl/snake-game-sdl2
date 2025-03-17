#pragma once

#include <vector>
#include <memory>
#include "Config.h"
#include "SpriteSheet.h"
#include "GraphicObject.h"

class GameBackground : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void render() override;

private:
	static constexpr int TILE_SCALE = BACKGROUND_TILE_SCALE;

	std::unique_ptr<SpriteSheet> sheet;
	std::vector<std::vector<Position>> randomIndexArray;
};
