#pragma once

#include "GraphicObject.h"
#include "Text.h"
#include "Food.h"

class ScoreText : public GraphicObject
{
public:
	GraphicObject::GraphicObject;

	void start() override;
	void render() override;
	void update(float deltaTime) override;

private:
	int score;
	std::unique_ptr<Text> scoreText;
	Food* food;

	void printScore(int score);
	void handleFoodEaten();
};
