#pragma once

// Snake
constexpr auto SNAKE_MOVE_INTERVAL = 0.15f;
constexpr auto SNAKE_TILE_SIZE = 32;

// Game background
constexpr auto BACKGROUND_TILE_SIZE = 64;

// Walls
constexpr auto WALL_TILE_SIZE = 32;

// UI
constexpr auto UI_HEIGHT = 96;

// Board
constexpr auto BOARD_HORIZONTAL_TILES = 32;
constexpr auto BOARD_VERTICAL_TILES = 24;

constexpr auto BOARD_WIDTH = BOARD_HORIZONTAL_TILES * SNAKE_TILE_SIZE;
constexpr auto BOARD_HEIGHT = BOARD_VERTICAL_TILES * SNAKE_TILE_SIZE;

// Window
constexpr auto WINDOW_WIDTH = BOARD_HORIZONTAL_TILES * SNAKE_TILE_SIZE;
constexpr auto WINDOW_HEIGHT = BOARD_VERTICAL_TILES * SNAKE_TILE_SIZE + UI_HEIGHT;
