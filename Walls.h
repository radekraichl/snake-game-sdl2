#pragma once

#include "GameObject.h"
#include "SpriteSheet.h"

class Walls : public GameObject
{
public:
	GameObject::GameObject;

	void start() override;
	void render() override;

private:
	std::unique_ptr<SpriteSheet> sheet;
};

