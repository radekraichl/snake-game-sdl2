#include "Config.h"
#include "ScoreText.h"
#include <format>

void ScoreText::start()
{
	food = scene->findObjectByType<Food>();
	food->onFoodEaten = [this]() { handleFoodEaten(); };

	score = 0;
	scoreText = std::make_unique<Text>("assets/fonts/atari-800.ttf", 18, renderer);
	scoreText->setColor({ 224, 186, 100, 255 });
	printScore(0);
}

void ScoreText::update(float deltaTime)
{
}

void ScoreText::render()
{
	scoreText->print(UI_TILE_SIZE, (UI_HEIGHT / 2) - (scoreText->getHeight() / 2));
}

void ScoreText::printScore(int score)
{
	scoreText->setText("SCORE: " + std::to_string(score));
}

void ScoreText::handleFoodEaten()
{
	score += 150;
	printScore(score);
}