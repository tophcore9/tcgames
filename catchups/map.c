#include "map.h"

int init_map()
{
    MAP = (char**)calloc(ROWS, sizeof(char*));
    for (int i = 0; i < ROWS; ++i)
        MAP[i] = (char*) calloc(COLS, sizeof(char));

    return 0;
}
void show_map(struct CurrentHandle *handle)
{
    for (int i = 0; i < ROWS; ++i)
    {
        // If we are at the first or last row we fill it by #
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

    MAP[handle->hero->y][handle->hero->x] = HERO_CHAR;
    MAP[handle->feed->y][handle->feed->x] = FEED_CHAR;
    MAP[handle->enemy->y][handle->enemy->x] = ENEMY_CHAR;
    for (int i = 0; i < ROWS; ++i)
        puts(MAP[i]);
    printf("Your score: %d\n", SCORE);
    puts("Press esc to exit.");
}

int movement_handler(struct CurrentHandle *handle)
{
    switch (handle->hero->input = getch())
    {
        case 'w':
        case 'W':
            if (MAP[handle->hero->y - 1][handle->hero->x] != BORDER_CHAR)
                MAP[handle->hero->y--][handle->hero->x] = ' ';
            find_hero();
            if (MAP[handle->enemy->y - 1][handle->enemy->x] != BORDER_CHAR)
                MAP[handle->enemy->y--][handle->enemy->x] = ' ';
            break;
        case 's':
        case 'S':
            if (MAP[handle->hero->y + 1][handle->hero->x] != BORDER_CHAR)
                MAP[handle->hero->y++][handle->hero->x] = ' ';
            find_hero();
            if (MAP[handle->enemy->y + 1][handle->enemy->x] != BORDER_CHAR)
                MAP[handle->enemy->y++][handle->enemy->x] = ' ';
            break;
        case 'a':
        case 'A':
            if (MAP[handle->hero->y][handle->hero->x - 1] != BORDER_CHAR)
                MAP[handle->hero->y][handle->hero->x--] = ' ';
            find_hero();
            if (MAP[handle->enemy->y][handle->enemy->x - 1] != BORDER_CHAR)
                MAP[handle->enemy->y][handle->enemy->x--] = ' ';
            break;
        case 'd':
        case 'D':
            if (MAP[handle->hero->y][handle->hero->x + 1] != BORDER_CHAR)
                MAP[handle->hero->y][handle->hero->x++] = ' ';
            find_hero();
            if (MAP[handle->enemy->y][handle->enemy->x + 1] != BORDER_CHAR)
                MAP[handle->enemy->y][handle->enemy->x++] = ' ';
            break;
    }
    if (handle->hero->x == handle->feed->x && handle->hero->y == handle->feed->y)
    {
        init_feed(handle->feed);
        ++SCORE;
    }
    if (handle->enemy->x == handle->hero->x && handle->enemy->y == handle->hero->y)
    {
        system("cls");
        puts("=========Game Over=========\n"
             "You was killed by the enemy!\n"
             "Try again.\n");
        getch();
        return 1; // Return if the hero is killed
    }

    return 0; // Return if the hero is alive
}
