#include "InputManager.h"
#include "Direction.h"
#include "GameScene.h"
#include <iostream>

void InputManager::Update()
{
	lastKeyPressed = SDLK_UNKNOWN;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			quitRequested = true;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			lastKeyPressed = event.key.keysym.sym;
			direction = GetDirectionFromKey(lastKeyPressed);
		}
	}
}

Direction InputManager::GetDirectionFromKey(SDL_Keycode key) const
{
	switch (key)
	{
		case SDLK_w:    return Direction::Up;
		case SDLK_s:    return Direction::Down;
		case SDLK_a:    return Direction::Left;
		case SDLK_d:    return Direction::Right;
		case SDLK_UP:   return Direction::Up;
		case SDLK_DOWN: return Direction::Down;
		case SDLK_LEFT: return Direction::Left;
		case SDLK_RIGHT:return Direction::Right;
		default:        return direction;
	}
}

Direction InputManager::GetDirection() const
{
	return direction;
}

void InputManager::SetNoneDirection()
{
	direction = Direction::None;
}

SDL_Keycode InputManager::GetLastKeyPressed() const
{
	return lastKeyPressed;
}

bool InputManager::WasQuitRequested() const
{
	return quitRequested;
}
