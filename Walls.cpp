#include "Walls.h"
#include "Config.h"

void Walls::start()
{
	sheet = std::make_unique<SpriteSheet>("assets/images/walls_sprite_sheet.png", 3, 3, renderer);
	sheet->setTileSize(WALL_TILE_SIZE);
}

void Walls::render()
{
	int tileWidth = sheet->getScaledTileWidth();
	int tileHeight = sheet->getScaledTileHeight();

	for (size_t i = 0; i < WINDOW_WIDTH / sheet->getScaledTileWidth(); i++)
	{
		sheet->renderSprite(1, 0, i * tileWidth, 0);
		sheet->renderSprite(1, 2, i * tileWidth, WINDOW_HEIGHT - tileHeight);
	}

	for (size_t i = 0; i < WINDOW_HEIGHT / sheet->getScaledTileHeight(); i++)
	{
		sheet->renderSprite(0, 1, 0, i * tileHeight);
		sheet->renderSprite(2, 1, WINDOW_WIDTH - tileWidth, i * tileHeight);
	}

	// Left top
	sheet->renderSprite(0, 0, 0, 0);
	// Right top
	sheet->renderSprite(2, 0, WINDOW_WIDTH - tileWidth, 0);
	// Left down
	sheet->renderSprite(0, 2, 0, WINDOW_HEIGHT - tileHeight);
	// Right down
	sheet->renderSprite(2, 2, WINDOW_WIDTH - tileWidth, WINDOW_HEIGHT - tileHeight);
}
