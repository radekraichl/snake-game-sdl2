#pragma once

#include "Config.h"
#include "SpriteSheet.h"
#include "GameObject.h"

class GameBackground : public GameObject
{
public:
	GameObject::GameObject;

	void start() override;
	void render() override;

private:
	static constexpr int TILE_SCALE = BACKGROUND_TILE_SCALE;

	std::unique_ptr<SpriteSheet> sheet;
	std::vector<std::vector<Position>> randomIndexArray;
};

