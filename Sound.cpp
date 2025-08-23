#include <SDL_mixer.h>
#include "Sound.h"
#include "Error.h"

Sound::Sound(const std::string& filePath) : chunk(nullptr)
{
	chunk = Mix_LoadWAV(filePath.c_str());
	Error::assert(chunk != nullptr);
}

Sound::~Sound()
{
	if (chunk)
	{
		Mix_FreeChunk(chunk);
	}
}

void Sound::Play()
{
	if (chunk)
	{
		Mix_PlayChannel(-1, chunk, 0);
	}
}
