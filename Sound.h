#pragma once

#include <string>

class Mix_Chunk;

class Sound
{
public:
	Sound(const std::string& filePath);
	~Sound();

	void Play();

private:
	Mix_Chunk* chunk;
};

