#include "menu.h"

void menu_handler()
{
    char input;
    int current = 0;

    while (1)
    {
        system("cls");
        puts("=====Welcome!=====");
        for (int i = 0; i < MENU_OPTIONS; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", menu_options[i]);
                continue;
            }

            printf("%s\n", menu_options[i]);
        }

        switch (input = getch())
        {
            case 'w':
            case 'W':
                if (current - 1 >= 0)
                    --current;
                break;
            case 's':
            case 'S':
                if (current + 1 < MENU_OPTIONS)
                    ++current;
                break;
            case ENTER:
                menu_action_handler(current);
                current = 0;
                break;
        }
    }
}

int menu_action_handler(int current)
{
    switch (current)
    {
        case 0: // Start new game
            SCORE = 0;
            run_game();
            break;
        case 1: // Settings
            settings_handler();
            break;
        case 2: // Credits
            system("cls");
            printf("CATHUPS\n"
                   "Version 1.0\n"
                   "Created by Oleksii Paziura");
            getch();
            break;
        case 3: // Exit
            printf("Bye!\n");
            getch();
            exit(EXIT_SUCCESS);
    }
}

int settings_handler()
{
    char input;
    int current = 0;

    while (1)
    {
        system("cls");
        puts("=====Settings=====");
        for (int i = 0; i < SETTINGS_OPTIONS; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", settings_options[i]);
                continue;
            }

            printf("%s\n", settings_options[i]);
        }

        switch (input = getch())
        {
            case 'w':
            case 'W':
                if (current - 1 >= 0)
                    --current;
                break;
            case 's':
            case 'S':
                if (current + 1 < SETTINGS_OPTIONS)
                    ++current;
                break;
            case ENTER:
                if (settings_action_handler(current) == 1)
                    return 0;
                break;
        }
    }
}

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
            return 1;
    }
    return 0;
}

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

int difficulty_handler()
{
    char input;
    int current = 0;

    while (1)
    {
        system("cls");
        printf("========Select difficulty========\n"
               "Current difficulty is %s\n", difficulty_str());

        for (int i = 0; i < DIFFICULTIES; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", difficulty_options[i]);
                continue;
            }

            printf("%s\n", difficulty_options[i]);
        }

        switch (input = getch())
        {
            case 'w':
            case 'W':
                if (current - 1 >= 0)
                    --current;
                break;
            case 's':
            case 'S':
                if (current + 1 < DIFFICULTIES)
                    ++current;
                break;
            case ENTER:
                difficulty_action_handler(current);
                return 0;
        }
    }
}

int difficulty_action_handler(int current)
{
    switch (current)
    {
        case 0: // Easy
            CURRENT_DIFFICULTY = Easy;
            COLS = DEFAULT_COLS;
            ROWS = DEFAULT_ROWS;
            break;
        case 1: // Medium
            CURRENT_DIFFICULTY = Medium;
            COLS = DEFAULT_COLS * 2;
            ROWS = DEFAULT_ROWS * 2;
            break;
        case 2: // Hard
            CURRENT_DIFFICULTY = Hard;
            COLS = DEFAULT_COLS * 2.5;
            ROWS = DEFAULT_ROWS * 2.5;
            break;
    }
    return 0;
}

int characters_handler()
{
    char input;
    int current = 0;

    while (1)
    {
        system("cls");
        puts("========Customise characters========");

        for (int i = 0; i < CHARACTERS; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", characters_options[i]);
                continue;
            }

            printf("%s\n", characters_options[i]);
        }

        switch (input = getch())
        {
            case 'w':
            case 'W':
                if (current - 1 >= 0)
                    --current;
                break;
            case 's':
            case 'S':
                if (current + 1 < CHARACTERS)
                    ++current;
                break;
            case ENTER:
                characters_action_handler(current);
                return 0;
        }
    }
}

int characters_action_handler(int current)
{
    switch (current)
    {
        case 0: // Reset
            BORDER_CHAR = DEFAULT_BORDER_CHAR;
            HERO_CHAR = DEFAULT_HERO_CHAR;
            FEED_CHAR = DEFAULT_FEED_CHAR;
            ENEMY_CHAR = DEFAULT_ENEMY_CHAR;
            break;
        case 1: // Hero character
            printf("Current hero's character: %c\n"
                   "Enter your own character: ", HERO_CHAR);
            HERO_CHAR = getchar();
            fflush(stdin);
            break;
        case 2: // Enemy character
            printf("Current enemy's character: %c\n"
                   "Enter your own character: ", ENEMY_CHAR);
            ENEMY_CHAR = getchar();
            fflush(stdin);
            break;
        case 3: // Feed character
            printf("Current feed's character: %c\n"
                   "Enter your own character: ", FEED_CHAR);
            FEED_CHAR = getchar();
            fflush(stdin);
            break;
        case 4: // Border character
            printf("Current border's character: %c\n"
                   "Enter your own character: ", BORDER_CHAR);
            BORDER_CHAR = getchar();
            fflush(stdin);
            break;
    }
    return 0;
}
