#include "Config.h"
#include "ScoreText.h"

void ScoreText::start()
{
	score = std::make_unique<Text>("assets/fonts/atari-800.ttf", 16, renderer);
	score->setColor(SDL_Color { 224, 186, 100, 255 });
	score->setText("SCORE: 0");
}

void ScoreText::render()
{
	score->print(UI_TILE_SIZE, (UI_HEIGHT / 2) - (score->getHeight() / 2));
}
