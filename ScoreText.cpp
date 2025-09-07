#include "Config.h"
#include "ScoreText.h"

void ScoreText::start()
{
	if (Food* food = scene->findObjectByType<Food>())
	{
		food->onFoodEaten.connect([this]() { handleFoodEaten(); });
	}

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
	scoreText->print((float)UI_TILE_SIZE, (UI_HEIGHT / 2.0f) - (scoreText->getHeight() / 2.0f));
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