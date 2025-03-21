#include "Walls.h"
#include "Config.h"

void Walls::start()
{
	spriteSheet = std::make_unique<SpriteSheet>("assets/images/walls_sprite_sheet.png", 3, 3, renderer);
	spriteSheet->setTileSize(WALL_TILE_SIZE);
}

void Walls::render()
{
	int tileWidth = spriteSheet->getScaledTileWidth();
	int tileHeight = spriteSheet->getScaledTileHeight();

	for (int i = 0; i < BOARD_WIDTH / tileWidth; i++)
	{
		spriteSheet->renderSprite(1, 0, i * tileWidth, 0);
		spriteSheet->renderSprite(1, 2, i * tileWidth, BOARD_HEIGHT - tileHeight);
	}

	for (int i = 0; i < BOARD_HEIGHT / tileHeight; i++)
	{
		spriteSheet->renderSprite(0, 1, 0, i * tileHeight);
		spriteSheet->renderSprite(2, 1, BOARD_WIDTH - tileWidth, i * tileHeight);
	}

	// Left top
	spriteSheet->renderSprite(0, 0, 0, 0);
	// Right top
	spriteSheet->renderSprite(2, 0, BOARD_WIDTH - tileWidth, 0);
	// Left down
	spriteSheet->renderSprite(0, 2, 0, BOARD_HEIGHT - tileHeight);
	// Right down
	spriteSheet->renderSprite(2, 2, BOARD_WIDTH - tileWidth, BOARD_HEIGHT - tileHeight);
}
