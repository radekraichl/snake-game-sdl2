#pragma once

#include "Scene.h"

class Graphics;

class GameScene : public Scene
{
public:
	GameScene(Graphics* graphics);
	~GameScene() = default;

	void run() override;
	void addObjects() override;
};
