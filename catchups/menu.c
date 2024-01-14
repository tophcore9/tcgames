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
            open_settings();
            break;
        case 2: // Credits
            system("cls");
            printf("CATHUPS\n"
                   "Version 1.0\n"
                   "Created by Paziura Oleksii");
            getch();
            break;
        case 3: // Exit
            printf("Bye!\n");
            getch();
            exit(EXIT_SUCCESS);
    }
}

int open_settings()
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
            printf("Difficulty");
            break;
        case 1: // Customise characters
            printf("Characters");
            break;
        case 2: // Exit
            return 1;
    }
    getch();
    return 0;
}
