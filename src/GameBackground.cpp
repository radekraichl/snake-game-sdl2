#include <vector>
#include <memory>
#include "GameBackground.h"
#include "SpriteSheet.h"
#include "Config.h"
#include "Random.h"

void GameBackground::start()
{
	spriteSheet = std::make_unique<SpriteSheet>("assets/images/pcb_sprite_sheet.png", 3, 3, renderer);
	spriteSheet->setTileSize(TILE_SIZE);

	// Resize array
	randomIndexArray.resize(BOARD_HEIGHT / spriteSheet->getScaledTileHeight());
	for (auto& row : randomIndexArray)
	{
		row.resize(BOARD_WIDTH / spriteSheet->getScaledTileWidth());
	}

	// Fill array
	for (auto& row : randomIndexArray)
	{
		std::generate(row.begin(), row.end(), [&]()
			{
				return Position(Random::getInt(0, spriteSheet->getColCount() - 1),
					Random::getInt(0, spriteSheet->getRowCount() - 1));
			});
	}
}

void GameBackground::render()
{
	for (int row = 0; row < randomIndexArray.size(); ++row)
	{
		for (int col = 0; col < randomIndexArray[row].size(); ++col)
		{
			int index_x = (int)randomIndexArray[row][col].x;
			int index_y = (int)randomIndexArray[row][col].y;
			spriteSheet->renderSprite(index_x, index_y, col * spriteSheet->getScaledTileWidth(), row * spriteSheet->getScaledTileHeight());
		}
	}
}
