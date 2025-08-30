#pragma once

#include "SpriteSheet.h"
#include "Bounds.h"

class TiledWindow
{
public:
	TiledWindow(const std::string& filePath, int cols, int rows, float scale, SDL_Renderer* renderer);

	void Render();

	// Getters
	Position getPosition() const;

	// Setters
	void setPosition(Position);
	void setPositionCentered(Position);

private:
	int cols, rows, tileWidth, tileHeight, winWidth, winHeight;
	float scale;
	Position position;
	std::unique_ptr<SpriteSheet> spriteSheet;
};

