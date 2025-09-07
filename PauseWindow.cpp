#include "PauseWindow.h"
#include "Config.h"

void PauseWindow::start()
{
	window = std::make_unique<TiledWindow>("assets/images/ui_window.png", 18, 10, 2.0f, renderer);
	//headingText = std::make_unique<Text>("assets/fonts/ka1.ttf", 32, renderer);
	headingText = std::make_unique<Text>("assets/fonts/04B_30__.ttf", 32, renderer);

	window->setPositionCentered(Position(WINDOW_WIDTH / 2, (WINDOW_HEIGHT + UI_HEIGHT) / 2));
	//headingText->setColor({ 43, 147, 244, 225 });
	headingText->setColor({ 224, 186, 100, 255 });

	headingText->setText("PAUSED");
}

void PauseWindow::render()
{
	if (active)
	{
		window->Render();
		headingText->setPositionCentered(WINDOW_WIDTH / 2.0, (WINDOW_HEIGHT + UI_HEIGHT) / 2.0);
		headingText->print();
	}
}

void PauseWindow::update(float deltaTime)
{
}

void PauseWindow::setActive(bool act)
{
	active = act;
}
