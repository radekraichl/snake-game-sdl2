#pragma once

// Board
constexpr auto BOARD_HORIZONTAL_TILES = 32;
constexpr auto BOARD_VERTICAL_TILES = 24;
constexpr auto BOARD_TILE_SIZE = 32;
constexpr auto BOARD_WIDTH = BOARD_HORIZONTAL_TILES * 32;
constexpr auto BOARD_HEIGHT = BOARD_VERTICAL_TILES * 32;

// UI
constexpr auto UI_HEIGHT = 96;
constexpr auto UI_TILE_SIZE = BOARD_TILE_SIZE;

// Window
constexpr auto WINDOW_WIDTH = BOARD_WIDTH;
constexpr auto WINDOW_HEIGHT = BOARD_HEIGHT + UI_HEIGHT;

// Snake
constexpr auto SNAKE_MOVE_INTERVAL = 0.15f;
constexpr auto SNAKE_TILE_SIZE = BOARD_TILE_SIZE;

// Game background
constexpr auto BACKGROUND_TILE_SIZE = BOARD_TILE_SIZE * 2;

// Walls
constexpr auto WALL_TILE_SIZE = BOARD_TILE_SIZE;

// Strings
constexpr auto GAME_NAME = "Snake Game";