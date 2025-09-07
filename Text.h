#pragma once

#include <string>
#include "Position.h"
#include "Bounds.h"

struct TTF_Font;

class Text
{
public:
	Text(const std::string& filePath, int size, SDL_Renderer* const renderer);
	~Text();
	
	// Methods
	void print();
	void print(float posX, float posY);

	// Getters
	int getWidth() const;
	int getHeight() const;

	// Setters
	void setText(std::string text);
	void setColor(SDL_Color color);
	void setPositionCentered(float x, float y);

private:
	int size;
	Bounds bounds;
	Position position;
	std::string text;
	std::string filePath;
	SDL_Color color;
	TTF_Font* font;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Renderer* const renderer;
};
