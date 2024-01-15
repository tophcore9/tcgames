#include "enemy.h"

struct Coord find_hero()
{
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            if (MAP[i][j] == HERO_CHAR)
            {
                struct Coord hero_coord = {j, i};
                return hero_coord;
            }
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

void find_and_kill(struct Enemy *enemy)
{
    struct Coord hero = find_hero();

    int step = rand() % (2 - 1 + 1) + 1;

    if (enemy->y == hero.y)
    {
        if (enemy->x - hero.x > 0)
            move_left(enemy, step);
        else
            move_right(enemy, step);
    }
    else if (enemy->x == hero.x)
    {
        if (enemy->y - hero.y > 0)
            move_up(enemy, step);
        else
            move_down(enemy, step);
    }
    else if (enemy->x > hero.x && enemy->y > hero.y) // Left top
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_down(enemy, step);
        else
            move_up(enemy, step);
    }
    else if (enemy->x < hero.x && enemy->y > hero.y) // Right top
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_up(enemy, step);
        else
            move_down(enemy, step);
    }
    else if (enemy->x > hero.x && enemy->y < hero.y) // Left bottom
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_right(enemy, step);
        else
            move_left(enemy, step);
    }
    else if (enemy->x < hero.x && enemy->y < hero.y) // Right top
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_right(enemy, step);
        else
            move_left(enemy, step);
    }
}

void move_up(struct Enemy *enemy, int step)
{
    if (MAP[enemy->y - step][enemy->x] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y -= step][enemy->x] = ' ';
}
void move_down(struct Enemy *enemy, int step)
{
    if (MAP[enemy->y + step][enemy->x] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y += step][enemy->x] = ' ';
}
void move_left(struct Enemy *enemy, int step)
{
    if (MAP[enemy->y][enemy->x - step] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y][enemy->x -= step] = ' ';
}
void move_right(struct Enemy *enemy, int step)
{
    if (MAP[enemy->y][enemy->x + step] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y][enemy->x += step] = ' ';
}
