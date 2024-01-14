#include "game.h"

int run()
{
    srand(time(NULL));
    show_menu();

    struct Hero hero = {-1, -1};
    struct Feed feed = {-1, -1};
    struct CurrentHandle handle = {&hero, &feed};

    init_map();
    init_hero(handle.hero);
    init_feed(handle.feed);

    do
    {
        system("cls");
        show_map(&handle);
        movement_handler(&handle);
    }
    while (hero.input != ESC);

    system("cls");
    printf("Game was ended!\nYour final score: %d", SCORE);
    return 0;
}

int show_menu()
{
    char input;
    int current = 0;
    const char *options[] = {
        "Start new game",
        "Options",
        "Credits",
        "Exit"
    };

    do
    {
        system("cls");
        puts("=====Welcome!=====");
        for (int i = 0; i < 4; ++i)
        {
            if (i == current)
            {
                printf("[%s]\n", options[i]);
                continue;
            }

            printf("%s\n", options[i]);
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
                if (current + 1 < 4)
                    ++current;
                break;
            case ENTER:
                if (current == 0)
                    printf("First\n");
                else if (current == 1)
                    printf("Second\n");
                else if (current == 2)
                    printf("Third\n");
                else if (current == 3)
                {
                    printf("Bye!\n");
                    getch();
                    exit(EXIT_SUCCESS);
                }

                getch();
                break;
        }
    }
    while (input != ENTER);

    return 0;
}
