#include <string>
#include <stdexcept>
#include <SDL_ttf.h>
#include "Error.h"

void Error::assert(bool condition)
{
	if (!condition)
	{
		std::string sdlError = SDL_GetError();
		throw std::runtime_error(sdlError);
	}
}
