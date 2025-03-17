#include "Sprite.h"

// Constructor
Sprite::Sprite(const std::string& filePath, SDL_Renderer* renderer, int tileSize)
	: scale(1), rotation(0), realTextureWidth(0), realTextureHeight(0), renderer(renderer)
{
	sprite = std::make_unique<Texture>(filePath, renderer);
	texture = sprite->getTexture();

	int tempWidth, tempHeight;
	SDL_QueryTexture(texture, nullptr, nullptr, &tempWidth, &tempHeight);
	*const_cast<int*>(&realTextureWidth) = tempWidth;
	*const_cast<int*>(&realTextureHeight) = tempHeight;

	srcRect = { 0, 0, realTextureWidth, realTextureHeight };

	tileSize > 0 ? setScale(tileSize / realTextureWidth) : setScale(1);
}

void Sprite::renderSprite()
{
	updateTransform(position.x, position.y, rotation);
	SDL_RenderCopyEx(renderer, getTexture(), &srcRect, &destRect, rotation, nullptr, SDL_FLIP_NONE);
}

void Sprite::renderSprite(SDL_Rect destRect)
{
	SDL_RenderCopyEx(renderer, getTexture(), &srcRect, &destRect, rotation, nullptr, SDL_FLIP_NONE);
}

void Sprite::renderSprite(int posX, int posY)
{
	updateTransform(posX, posY, rotation);
	SDL_RenderCopyEx(renderer, getTexture(), &srcRect, &destRect, rotation, nullptr, SDL_FLIP_NONE);
}

void Sprite::renderSprite(int posX, int posY, float rot)
{
	updateTransform(posX, posY, rot);
	SDL_RenderCopyEx(renderer, getTexture(), &srcRect, &destRect, rotation, nullptr, SDL_FLIP_NONE);
}

// Setters
void Sprite::setScale(int scale)
{
	this->scale = scale;
	scaledWidth = realTextureWidth * scale;
	scaledHeight = realTextureHeight * scale;
}

void Sprite::setTileSize(int size)
{
	setScale(size / realTextureWidth);
}

void Sprite::setRotation(float rot)
{
	rotation = rot;
}

void Sprite::setSrcRect(SDL_Rect rect)
{
	srcRect = rect;
}

// Private methods
void Sprite::updateTransform(int posX, int posY, float rot)
{
	position.x = posX;
	position.y = posY;
	rotation = rot;
	destRect = { position.x, position.y, scaledWidth, scaledHeight };
}

// Getters
SDL_Texture* Sprite::getTexture() const
{
	return texture;
}

int Sprite::getScaledWidth() const
{
	return scaledWidth;
}

int Sprite::getScaledHeight() const
{
	return scaledHeight;
}

int Sprite::getRealWidth() const
{
	return realTextureWidth;
}

int Sprite::getRealHeight() const
{
	return realTextureHeight;
}

int Sprite::getScale() const
{
	return scale;
}
