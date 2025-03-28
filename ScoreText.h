#pragma once

#include "GraphicObject.h"
#include "Text.h"

class ScoreText : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void render() override;

private:
	std::unique_ptr<Text> score;
};
