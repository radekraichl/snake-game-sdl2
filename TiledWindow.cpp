#include "TiledWindow.h"

TiledWindow::TiledWindow(const std::string& filePath, int cols, int rows, float scale, SDL_Renderer* renderer) :
	cols(cols), rows(rows), scale(scale), position(Position(0, 0))
{
	spriteSheet = std::make_unique<SpriteSheet>(filePath, 3, 3, renderer);
	spriteSheet->setTileScale(scale);
	tileWidth = spriteSheet->getScaledTileWidth();
	tileHeight = spriteSheet->getScaledTileHeight();
	winWidth = tileWidth * cols;
	winHeight = tileHeight * rows;
}

void TiledWindow::Render()
{
	// Upper left
	spriteSheet->renderSprite(0, 0, position.x, position.y);
	// Upper right
	spriteSheet->renderSprite(2, 0, position.x + winWidth - tileWidth, position.y);
	// Bottom left
	spriteSheet->renderSprite(0, 2, position.x, position.y + winHeight - tileHeight);
	// Bottom right
	spriteSheet->renderSprite(2, 2, position.x + winWidth - tileWidth, position.y + winHeight - tileHeight);

	// Fill left/right edges
	for (int y = tileHeight; y < winHeight - tileHeight; y += tileHeight)
	{
		// Left edge (sprite 0,1)
		spriteSheet->renderSprite(0, 1, position.x, position.y + y);
		// Right edge (sprite 2,1)
		spriteSheet->renderSprite(2, 1, position.x + winWidth - tileWidth, position.y + y);
	}

	// Fill top/bottom edges
	for (int x = tileWidth; x < winWidth - tileWidth; x += tileWidth)
	{
		// Top edge (sprite 1,0)
		spriteSheet->renderSprite(1, 0, position.x + x, position.y);
		// Bottom edge (sprite 1,2)
		spriteSheet->renderSprite(1, 2, position.x + x, position.y + winHeight - tileWidth);
	}

	// Fill center (sprite 1,1)
	for (int y = tileHeight; y < winHeight - tileHeight; y += tileHeight)
	{
		for (int x = tileWidth; x < winWidth - tileWidth; x += tileWidth)
		{
			spriteSheet->renderSprite(1, 1, position.x + x, position.y + y);
		}
	}
}

// Getters
Position TiledWindow::getPosition() const
{
	return position;
}

// Setters
void TiledWindow::setPosition(Position pos)
{
	position = pos;
}

void TiledWindow::setPositionCentered(Position centerPos)
{
	position.x = centerPos.x - winWidth / 2;
	position.y = centerPos.y - winHeight / 2;
}