#include "game.h"

int run_game()
{
    srand(time(NULL));

    struct Hero hero = {-1, -1};
    struct Enemy enemy = {-1, -1};
    struct Feed feed = {-1, -1};
    struct CurrentHandle handle = {&hero, &enemy, &feed};

    init_map();
    init_hero(handle.hero);
    init_feed(handle.feed);
    init_enemy(handle.enemy);

    do
    {
        system("cls");
        show_map(&handle);
        if (movement_handler(&handle) != 0)
            break;
    }
    while (hero.input != ESC);

    system("cls");
    printf("Game was ended!\nYour final score: %d", SCORE);
    getch();

    return 0;
}
