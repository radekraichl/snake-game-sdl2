#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const std::string& filePath, int cols, int rows, SDL_Renderer* renderer) :
	rowCount(rows), colCount(cols), realTileWidth(0), realTileHeight(0), renderer(renderer)
{
	sprite = std::make_unique<Sprite>(filePath, renderer);

	// Setting constants
	int tempWidth = sprite->getRealWidth() / cols;
	int tempHeight = sprite->getRealHeight() / rows;
	*const_cast<int*>(&realTileWidth) = tempWidth;
	*const_cast<int*>(&realTileHeight) = tempHeight;

	// Filling an array of rectangles
	rectangles.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		rectangles[i].resize(cols);
		for (int j = 0; j < cols; ++j)
		{
			int x = j * realTileWidth;
			int y = i * realTileHeight;
			rectangles[i][j] = SDL_Rect { x, y, realTileWidth, realTileHeight };
		}
	}
	
	setTileScale(1);
}

void SpriteSheet::renderSprite(int index_x, int index_y, int posX, int posY)
{
	sprite->setSrcRect(rectangles[index_y][index_x]);
	sprite->renderSprite({ posX, posY, scaledTileWidth, scaledTileHeight });
}

// Setters
void SpriteSheet::setTileScale(int scale)
{
	scaledTileWidth = realTileWidth * scale;
	scaledTileHeight = realTileHeight * scale;
}

void SpriteSheet::setTileSize(int size)
{
	scaledTileWidth = size;
	scaledTileHeight = size;
}

// Getters
int SpriteSheet::getScaledTileWidth() const
{
	return scaledTileWidth;
}

int SpriteSheet::getScaledTileHeight() const
{
	return scaledTileHeight;
}

int SpriteSheet::getRowCount() const
{
	return rowCount;
}

int SpriteSheet::getColCount() const
{
	return colCount;
}
