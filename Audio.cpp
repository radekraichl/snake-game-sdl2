#include <SDL.h>
#include <SDL_mixer.h>
#include "Audio.h"
#include "Error.h"

void Audio::Init()
{
	Error::assert(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == 0);
	SDL_Log("MIX_Init");
}