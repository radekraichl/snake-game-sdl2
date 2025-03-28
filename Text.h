#pragma once
#include "Texture.h"

class Text
{
public:
	Text(const std::string& filePath, int size, SDL_Renderer* const renderer);
	~Text();

	// Setters
	void setText(std::string text);
	void setColor(SDL_Color color);
	void print(int posX, int posY);

	// Getters
	int getWidth() const;
	int getHeight() const;
private:
	int size;
	std::string text;
	std::string filePath;
	SDL_Color color;
	TTF_Font* font;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;
};
