#ifndef MENU_H
#define MENU_H

#include "init.h"
#include "game.h"

#define MENU_OPTIONS 4
#define SETTINGS_OPTIONS 3
#define DIFFICULTIES 4
#define CHARACTERS 5

static const char *menu_options[] = {
        "Start new game",
        "Settings",
        "Credits",
        "Exit"
};

/// TODO: Make a saving module
static const char *settings_options[] = {
        "Change difficulty",
        "Customise characters",
        "Exit"
};

static const char *difficulty_options[] = {
        "Easy",
        "Medium",
        "Hard",
        "Exit"
};

static const char *characters_options[] = {
        "Reset",
        "- Hero character",
        "- Feed character",
        "- Border character",
        "Exit"
};

// Main menu
void menu_handler();
int menu_action_handler(int current);

// Settings
int settings_handler();
int settings_action_handler(int current);

// Difficulty
const char* difficulty_str();
int difficulty_handler();
int difficulty_action_handler(int current);

int characters_handler();
int characters_action_handler(int current);

#endif //MENU_H
