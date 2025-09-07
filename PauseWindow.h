#pragma once

#include "GraphicObject.h"
#include "TiledWindow.h"
#include "Text.h"

class PauseWindow : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void render() override;
	void update(float deltaTime) override;
	void setActive(bool);

private:
	bool active = false;
	std::unique_ptr<TiledWindow> window;
	std::unique_ptr<Text> headingText;
};
