#pragma once

#include "GameObject.h"
#include "SpriteSheet.h"

class Grass : public GameObject
{
public:
	GameObject::GameObject;

	void start() override;
	void render() override;

private:
	static constexpr int TILE_SCALE = 4;

	std::unique_ptr<SpriteSheet> sheet;
	std::vector<std::vector<Position>> randomIndexArray;
};

