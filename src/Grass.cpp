#include "Grass.h"
#include "Config.h"
#include "Random.h"
#include "SpriteSheet.h"

void Grass::start()
{
	sheet = std::make_unique<SpriteSheet>("assets/images/pcb_sprite_sheet.png", 3, 3, renderer);
	sheet->setTileScale(TILE_SCALE);

	// Resize array
	randomIndexArray.resize(WINDOW_HEIGHT / sheet->getScaledTileHeight());
	for (auto& row : randomIndexArray)
	{
		row.resize(WINDOW_WIDTH / sheet->getScaledTileWidth());
	}

	// Fill array
	for (auto& row : randomIndexArray)
	{
		std::ranges::generate(row, [&]()
			{
				return Position(Random::getInt(0, sheet->getColCount() - 1),
					Random::getInt(0, sheet->getRowCount() - 1));
			});
	}
}

void Grass::render()
{
	for (int row = 0; row < randomIndexArray.size(); ++row)
	{
		for (int col = 0; col < randomIndexArray[row].size(); ++col)
		{
			int index_x = randomIndexArray[row][col].x;
			int index_y = randomIndexArray[row][col].y;
			sheet->renderSprite(index_x, index_y, col * sheet->getScaledTileWidth(), row * sheet->getScaledTileHeight());
		}
	}
}
