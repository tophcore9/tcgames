#include "enemy.h"

/* Enemy initialisation */
int init_enemy(struct Coord *enemy)
{
    assert(MAP != NULL);
    do
    {
        enemy->x = rand() % ((COLS - 3) - 1 + 1) + 1;
        enemy->y = rand() % ((ROWS - 2) - 1 + 1) + 1;
    } while (MAP[enemy->y][enemy->x] == HERO_CHAR &&
             MAP[enemy->y][enemy->x] == FEED_CHAR);
}

/* Function that gets the coordinates of the main hero */
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

/* Function for catching main hero by the enemy */
void catch(struct Coord *enemy)
{
    struct Coord hero = find_hero();

    /* Range from 1 to 2 */
    int step = rand() % (2 - 1 + 1) + 1;

    /* Y logic */
    if (enemy->y == hero.y)
    {
        if (enemy->x - hero.x > 0)
            move_left(enemy, step);
        else
            move_right(enemy, step);
    }
    /* X logic */
    else if (enemy->x == hero.x)
    {
        if (enemy->y - hero.y > 0)
            move_up(enemy, step);
        else
            move_down(enemy, step);
    }
    /* Left top logic */
    else if (enemy->x > hero.x && enemy->y > hero.y)
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_down(enemy, step);
        else
            move_up(enemy, step);
    }
    /* Right top logic */
    else if (enemy->x < hero.x && enemy->y > hero.y)
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_up(enemy, step);
        else
            move_down(enemy, step);
    }
    /* Left bottom logic */
    else if (enemy->x > hero.x && enemy->y < hero.y)
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_right(enemy, step);
        else
            move_left(enemy, step);
    }
    /* Right bottom logic */
    else if (enemy->x < hero.x && enemy->y < hero.y)
    {
        if (enemy->x - hero.x < enemy->y - enemy->y)
            move_right(enemy, step);
        else
            move_left(enemy, step);
    }
}

/* Enemy movement to the top */
void move_up(struct Coord *enemy, int step)
{
    if (MAP[enemy->y - step][enemy->x] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y -= step][enemy->x] = ' ';
}
/* Enemy movement to the bottom */
void move_down(struct Coord *enemy, int step)
{
    if (MAP[enemy->y + step][enemy->x] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y += step][enemy->x] = ' ';
}
/* Enemy movement to the left */
void move_left(struct Coord *enemy, int step)
{
    if (MAP[enemy->y][enemy->x - step] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y][enemy->x -= step] = ' ';
}
/* Enemy movement to the right */
void move_right(struct Coord *enemy, int step)
{
    if (MAP[enemy->y][enemy->x + step] == BORDER_CHAR)
        step = 1;
    MAP[enemy->y][enemy->x += step] = ' ';
}
