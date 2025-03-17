#pragma once

constexpr auto SNAKE_MOVE_INTERVAL = 0.15f;

constexpr auto SNAKE_TILE_SIZE = 32;
constexpr auto WALL_TILE_SIZE = 32;
constexpr auto BACKGROUND_TILE_SCALE = 4;

constexpr auto BOARD_WIDTH = 32;
constexpr auto BOARD_HEIGHT = 24;

constexpr auto WINDOW_WIDTH = BOARD_WIDTH * SNAKE_TILE_SIZE;
constexpr auto WINDOW_HEIGHT = BOARD_HEIGHT * SNAKE_TILE_SIZE;