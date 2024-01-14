#ifndef MENU_H
#define MENU_H

#include "init.h"
#include "game.h"

#define MENU_OPTIONS 4
#define SETTINGS_OPTIONS 3

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

void menu_handler();
int menu_action_handler(int current);
int open_settings();
int settings_action_handler(int current);

#endif //MENU_H
