#include "game.h"

/* Running the game */
int run_game()
{
    srand(time(NULL));

    /* Base initialisation */
    struct Coord hero = {-1, -1};
    struct Coord enemy = {-1, -1};
    struct Coord feed = {-1, -1};
    struct CurrentHandle handle = {&hero, &enemy, &feed};

    init_map();
    init_hero(handle.hero);
    init_feed(handle.feed);
    init_enemy(handle.enemy);

    char input;
    do
    {
        system("cls");
        show_map(&handle);
        input = getch();
        if (movement_handler(&handle, input) != HERO_IS_ALIVE)
            break;
    } while (input != ESC);

    system("cls");
    printf("Game was ended!\nYour final score: %d", SCORE);
    getch();

    return 0;
}
