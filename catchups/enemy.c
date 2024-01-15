#include "enemy.h"

int find_hero()
{
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            if (MAP[i][j] == HERO_CHAR)
            {
                /* To exit from the cycle */
                j = COLS;
                i = ROWS;
            }

    return 0;
}

int init_enemy(struct Enemy *enemy)
{
    assert(MAP != NULL);
    do
    {
        enemy->x = rand() % ((COLS - 3) - 1 + 1) + 1;
        enemy->y = rand() % ((ROWS - 2) - 1 + 1) + 1;
    } while (MAP[enemy->y][enemy->x] == HERO_CHAR &&
             MAP[enemy->y][enemy->x] == FEED_CHAR);
}
