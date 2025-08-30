#pragma once

#include "Scene.h"



#include "TiledWindow.h"

class Graphics;

class GameScene : public Scene
{
public:
	GameScene(Graphics* graphics);
	~GameScene() = default;

	void run() override;
	void addObjects() override;



	std::unique_ptr<TiledWindow> window = nullptr;
};
