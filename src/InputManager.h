#pragma once

#include <SDL.h>
#include "Direction.h"

class InputManager
{
public:
	InputManager() = default;

	void Update();
	bool WasQuitRequested() const;

	SDL_Keycode GetLastKeyPressed() const;
	Direction GetDirection() const;

	void SetNoneDirection();

private:
	bool quitRequested = false;
	SDL_Keycode lastKeyPressed = SDLK_UNKNOWN;
	Direction direction = Direction::None;

	Direction GetDirectionFromKey(SDL_Keycode key) const;
};
