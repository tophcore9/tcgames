#include "map.h"

/* Map initialisation */
void init_map()
{
    MAP = (char**)calloc(ROWS, sizeof(char*));
    for (int i = 0; i < ROWS; ++i)
        MAP[i] = (char*) calloc(COLS, sizeof(char));
}

/* Showing the map */
void show_map(struct CurrentHandle *handle)
{
    for (int i = 0; i < ROWS; ++i)
    {
        /* The first and last row are filled with BORDER_CHAR */
        if (i == 0 || i == ROWS - NULLIFIER)
        {
            for (int k = 0; k < COLS - NULLIFIER; ++k)
                MAP[i][k] = BORDER_CHAR;
            continue;
        }

        for (int j = 0; j < COLS - NULLIFIER; ++j)
        {
            if (j == 0 || j == COLS - NULLIFIER - 1)
            {
                MAP[i][j] = BORDER_CHAR;
                continue;
            }

            MAP[i][j] = ' ';
        }
    }

    /* Placement of the handle items */
    MAP[handle->hero->y][handle->hero->x] = HERO_CHAR;
    MAP[handle->feed->y][handle->feed->x] = FEED_CHAR;
    MAP[handle->enemy->y][handle->enemy->x] = ENEMY_CHAR;

    /* Map outputting */
    for (int i = 0; i < ROWS; ++i)
        puts(MAP[i]);

    printf("Your score: %d\n", SCORE);
    puts("Press esc to exit.");
}

/* Motion control */
int movement_handler(struct CurrentHandle *handle, char input)
{
    catch(handle->enemy);
    switch (input)
    {
        case 'w':
        case 'W':
            move_hero_up(handle->hero);
            break;
        case 's':
        case 'S':
            move_hero_down(handle->hero);
            break;
        case 'a':
        case 'A':
            move_hero_left(handle->hero);
            break;
        case 'd':
        case 'D':
            move_hero_right(handle->hero);
            break;
    }

    /* If the enemy is on the same grid with the hero */
    if (handle->enemy->x == handle->hero->x && handle->enemy->y == handle->hero->y)
    {
        system("cls");
        puts("=========Game Over=========\n"
             "You was killed by the enemy!\n"
             "Try again.\n");
        getch();
        return HERO_IS_KILLED;
    }

    /* If the hero ate the feed */
    if (handle->hero->x == handle->feed->x && handle->hero->y == handle->feed->y)
    {
        /* Respawn the feed and score updating */
        init_feed(handle->feed);
        ++SCORE;
    }

    return HERO_IS_ALIVE;
}
