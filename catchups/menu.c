#include "menu.h"

/* Outputting the menu and selecting an item */
void menu_handler()
{
    int current = 0;

    while (TRUE)
    {
        system("cls");
        puts("=====Welcome!=====");

        /* Outputting the main menu */
        for (int i = 0; i < MENU_OPTIONS; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", menu_options[i]);
                continue;
            }

            printf("%s\n", menu_options[i]);
        }

        /* Select menu item */
        item_selector(MENU_OPTIONS, &current, menu_action_handler);
    }
}

/* Handling the selected item */
int menu_action_handler(int current)
{
    switch (current)
    {
        case 0: /* Start a new game */
            SCORE = 0;
            run_game();
            break;
        case 1: /* Settings */
            settings_handler();
            break;
        case 2: /* Credits */
            system("cls");
            printf("CATHUPS\n"
                   "Version 2.0\n"
                   "Created by Oleksii Paziura");
            getch();
            break;
        case 3: /* Exit */
            printf("Bye!\n");
            getch();
            exit(EXIT_SUCCESS);
    }
    return 0;
}

/* Outputting the settings and selecting an item */
int settings_handler()
{
    int current = 0;

    while (TRUE)
    {
        system("cls");
        puts("=====Settings=====");

        /* Outputting settings */
        for (int i = 0; i < SETTINGS_OPTIONS; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", settings_options[i]);
                continue;
            }

            printf("%s\n", settings_options[i]);
        }

        /* Select menu item */
        if (item_selector(SETTINGS_OPTIONS, &current, settings_action_handler) == EXIT)
            return 0;
    }
}

/* Handling the selected item */
int settings_action_handler(int current)
{
    switch (current)
    {
        case 0: // Change difficulty
            difficulty_handler();
            break;
        case 1: // Customise characters
            characters_handler();
            break;
        case 2: // Exit
            return EXIT;
    }

    return 0;
}

/* Converting difficulty from enum to string */
const char* difficulty_str()
{
    switch (CURRENT_DIFFICULTY)
    {
        case Easy:
            return "Easy";
        case Medium:
            return "Medium";
        case Hard:
            return "Hard";
    }
}

/* Outputting difficulties and selecting one of them */
int difficulty_handler()
{
    int current = 0;

    while (TRUE)
    {
        system("cls");
        printf("========Select difficulty========\n"
               "Current difficulty is %s\n", difficulty_str());

        /* Outputting difficulties */
        for (int i = 0; i < DIFFICULTIES; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", difficulty_options[i]);
                continue;
            }

            printf("%s\n", difficulty_options[i]);
        }

        /* Select menu item */
        if (item_selector(DIFFICULTIES, &current, difficulty_action_handler) == EXIT)
            return 0;
    }
}

/* Handling the selected item */
int difficulty_action_handler(int current)
{
    switch (current)
    {
        case 0: /* Easy */
            CURRENT_DIFFICULTY = Easy;
            COLS = DEFAULT_COLS;
            ROWS = DEFAULT_ROWS;
            break;
        case 1: /* Medium */
            CURRENT_DIFFICULTY = Medium;
            COLS = DEFAULT_COLS * 2;
            ROWS = DEFAULT_ROWS * 2;
            break;
        case 2: /* Hard */
            CURRENT_DIFFICULTY = Hard;
            COLS = DEFAULT_COLS * 2.5;
            ROWS = DEFAULT_ROWS * 2.5;
            break;
    }
    return EXIT;
}

/* Outputting the character customisation menu and selecting an item */
int characters_handler()
{
    int current = 0;

    while (TRUE)
    {
        system("cls");
        puts("===Customise characters===");

        /* Outputting characters */
        for (int i = 0; i < CHARACTERS; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", characters_options[i]);
                continue;
            }

            printf("%s\n", characters_options[i]);
        }

        /* Select menu item */
        if (item_selector(CHARACTERS, &current, characters_action_handler) == EXIT)
            return 0;
    }
}

/* Handling the selected item */
int characters_action_handler(int current)
{
    switch (current)
    {
        case 0: /* Reset */
            BORDER_CHAR = DEFAULT_BORDER_CHAR;
            HERO_CHAR = DEFAULT_HERO_CHAR;
            FEED_CHAR = DEFAULT_FEED_CHAR;
            ENEMY_CHAR = DEFAULT_ENEMY_CHAR;
            break;
        case 1: /* Hero character */
            printf("Current hero's character: %c\n"
                   "Enter your own character: ", HERO_CHAR);
            HERO_CHAR = getchar();
            fflush(stdin);
            break;
        case 2: /* Enemy character */
            printf("Current enemy's character: %c\n"
                   "Enter your own character: ", ENEMY_CHAR);
            ENEMY_CHAR = getchar();
            fflush(stdin);
            break;
        case 3: /* Feed character */
            printf("Current feed's character: %c\n"
                   "Enter your own character: ", FEED_CHAR);
            FEED_CHAR = getchar();
            fflush(stdin);
            break;
        case 4: /* Border character */
            printf("Current border's character: %c\n"
                   "Enter your own character: ", BORDER_CHAR);
            BORDER_CHAR = getchar();
            fflush(stdin);
            break;
    }

    return EXIT;
}

/* Selector of elements in specific function */
int item_selector(int option_amount, int *current, int (*action_handler)(int))
{
    char input;
    switch (input = getch())
    {
        case 'w':
        case 'W':
            if (*current - 1 >= 0)
                --(*current);
            break;
        case 's':
        case 'S':
            if (*current + 1 < option_amount)
                ++(*current);
            break;
        case ENTER:
            if (action_handler(*current) == EXIT)
            {
                *current = 0;
                return EXIT;
            }
    }

    return 0;
}
