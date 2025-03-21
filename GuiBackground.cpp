#include "GuiBackground.h"

void GuiBackground::start()
{
	spriteSheet = std::make_unique<SpriteSheet>("assets/images/ui_display.png", 3, 3, renderer);
	spriteSheet->setTileSize(TILE_SIZE);
}

void GuiBackground::render()
{
	int tileWidth = spriteSheet->getScaledTileWidth();
	int tileHeight = spriteSheet->getScaledTileHeight();

	// Rows
	for (int i = 1; i < (WINDOW_WIDTH / tileWidth) - 1; i++)
	{
		spriteSheet->renderSprite(1, 0, i * tileWidth, 0);
		spriteSheet->renderSprite(1, 1, i * tileWidth, tileHeight);
		spriteSheet->renderSprite(1, 2, i * tileWidth, UI_HEIGHT - tileHeight);
	}

	// Upper left
	spriteSheet->renderSprite(0, 0, 0, 0);
	// Middle left
	spriteSheet->renderSprite(0, 1, 0, TILE_SIZE);
	// Bottom left
	spriteSheet->renderSprite(0, 2, 0, UI_HEIGHT - TILE_SIZE);
	// Upper right
	spriteSheet->renderSprite(2, 0, WINDOW_WIDTH - TILE_SIZE, 0);
	// Middle right
	spriteSheet->renderSprite(2, 1, WINDOW_WIDTH - TILE_SIZE, TILE_SIZE);
	// Bottom right
	spriteSheet->renderSprite(2, 2, WINDOW_WIDTH - TILE_SIZE, UI_HEIGHT - TILE_SIZE);
}
