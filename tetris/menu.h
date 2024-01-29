#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include "raylib.h"

#define MENU_OPTIONS 3

static enum Options
{
    StartNewGame,
    GameOver,
    Menu,
    Options,
    Exit
} game_state;

static const char* menu_options[MENU_OPTIONS] =
{
    "Start new game",
    "Options",
    "Exit"
};
extern int current_option;

void ShowMenu();
void MenuHandler();
void MenuOptionsHandler(int option);

#endif //TETRIS_MENU_H
