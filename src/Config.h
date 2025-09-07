#pragma once

// Game area
constexpr auto BOARD_HORIZONTAL_TILES = 32;
constexpr auto BOARD_VERTICAL_TILES = 24;
constexpr auto BOARD_TILE_SIZE = 32;
constexpr auto BOARD_WIDTH = BOARD_HORIZONTAL_TILES * 32;
constexpr auto BOARD_HEIGHT = BOARD_VERTICAL_TILES * 32;

// Walls
constexpr auto WALL_TILE_SIZE = BOARD_TILE_SIZE;

// Game window
constexpr auto GAME_WINDOW_WIDTH = BOARD_WIDTH + 2 * WALL_TILE_SIZE;
constexpr auto GAME_WINDOW_HEIGHT = BOARD_HEIGHT + 2 * WALL_TILE_SIZE;

// UI
constexpr auto UI_HEIGHT = 96;
constexpr auto UI_SCORE_BAR_TILE_SIZE = BOARD_TILE_SIZE;

// Window
constexpr auto WINDOW_WIDTH = GAME_WINDOW_WIDTH;
constexpr auto WINDOW_HEIGHT = GAME_WINDOW_HEIGHT + UI_HEIGHT;

// Snake
constexpr auto SNAKE_START_MOVE_INTERVAL = 0.24;
constexpr auto SNAKE_TILE_SIZE = BOARD_TILE_SIZE;

// Game background
constexpr auto BACKGROUND_TILE_SIZE = BOARD_TILE_SIZE * 2;

// Strings
constexpr auto GAME_NAME = "Snake Game";