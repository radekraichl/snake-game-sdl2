#pragma once

#include <string>
#include <memory>
#include "Texture.h"
#include "Position.h"

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class Sprite
{
public:
	Sprite(const std::string& filePath, SDL_Renderer* renderer, int tileSize = 0);
	~Sprite() {};

	void renderSprite();
	void renderSprite(SDL_Rect destRect);
	void renderSprite(int posX, int posY);
	void renderSprite(int posX, int posY, float rot);

	SDL_Texture* getTexture() const;
	int getScaledWidth() const;
	int getScaledHeight() const;
	int getScale() const;

	void setScale(int scale);
	void setRotation(float rot);
	void setSrcRect(SDL_Rect rect);

private:
	std::unique_ptr<Texture> sprite;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

	Position position;

	int scale;
	float rotation;
	const int realTextureWidth;
	const int realTextureHeight;
	int scaledWidth;
	int scaledHeight;

	void updateTransform(int posX, int posY, float rot);
};
