#include "game.h"

int run_game()
{
    srand(time(NULL));

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
    getch();

    return 0;
}

