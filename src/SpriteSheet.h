#pragma once

#include <string>
#include <vector>
#include "Sprite.h"

struct SDL_Renderer;

class SpriteSheet
{
public:
	SpriteSheet(const std::string& filePath, int rows, int cols, SDL_Renderer* renderer);
	~SpriteSheet() = default;

	void renderSprite(int index_x, int index_y, int posX, int posY);
	
	// Setters
	void setTileScale(int scale);
	void setTileSize(int size);

	// Getters
	int getScaledTileWidth() const;
	int getScaledTileHeight() const;
	int getRowCount() const;
	int getColCount() const;

private:
	const int rowCount, colCount;
	const int realTileWidth;
	const int realTileHeight;
	int scaledTileWidth;
	int scaledTileHeight;
	SDL_Renderer* renderer;
	std::unique_ptr<Sprite> sprite;
	std::vector<std::vector<SDL_Rect>> rectangles;
};
