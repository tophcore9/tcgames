#ifndef MENU_H
#define MENU_H

#include "init.h"
#include "game.h"

#define TRUE 1
#define EXIT 1

/* Selector of elements in specific function */
int item_selector(int option_amount, int *current, int (*action_handler)(int));

/* MAIN MENU */

/* Options */
#define MENU_OPTIONS 4
static const char *menu_options[] = {
        "Start new game",
        "Settings",
        "Credits",
        "Exit"
};

/* Outputting the menu and selecting an item */
void menu_handler();

/* Handling the selected item */
int menu_action_handler(int current);


/* SETTINGS */

/* Options */
#define SETTINGS_OPTIONS 3
static const char *settings_options[] = {
        "Change difficulty",
        "Customise characters",
        "Exit"
};

/* Outputting the settings and selecting an item */
int settings_handler();

/* Handling the selected item */
int settings_action_handler(int current);


/* DIFFICULTY */

/* Options */
#define DIFFICULTIES 4
static const char *difficulty_options[] = {
        "Easy",
        "Medium",
        "Hard",
        "Exit"
};

/* Converting difficulty from enum to string */
const char* difficulty_str();

/* Outputting difficulties and selecting one of them */
int difficulty_handler();

/* Handling the selected item */
int difficulty_action_handler(int current);


/* CHARACTER CUSTOMISATION */

/* Options */
#define CHARACTERS 6
static const char *characters_options[] = {
        "Reset",
        "- Hero character",
        "- Enemy character",
        "- Feed character",
        "- Border character",
        "Exit"
};

/* Outputting the character customisation menu and selecting an item */
int characters_handler();

/* Handling the selected item */
int characters_action_handler(int current);

#endif //MENU_H
