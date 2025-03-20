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

	for (int i = 0; i < BOARD_WIDTH / sheet->getScaledTileWidth(); i++)
	{
		sheet->renderSprite(1, 0, i * tileWidth, 0);
		sheet->renderSprite(1, 2, i * tileWidth, BOARD_HEIGHT - tileHeight);
	}

	for (int i = 0; i < BOARD_HEIGHT / sheet->getScaledTileHeight(); i++)
	{
		sheet->renderSprite(0, 1, 0, i * tileHeight);
		sheet->renderSprite(2, 1, BOARD_WIDTH - tileWidth, i * tileHeight);
	}

	// Left top
	sheet->renderSprite(0, 0, 0, 0);
	// Right top
	sheet->renderSprite(2, 0, BOARD_WIDTH - tileWidth, 0);
	// Left down
	sheet->renderSprite(0, 2, 0, BOARD_HEIGHT - tileHeight);
	// Right down
	sheet->renderSprite(2, 2, BOARD_WIDTH - tileWidth, BOARD_HEIGHT - tileHeight);
}
