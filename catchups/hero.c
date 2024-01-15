#include "hero.h"

/* Hero initialisation */
void init_hero(struct Coord *hero)
{
    /* Range from (COLS - 3) to 1 */
    hero->x = rand() % ((COLS - 2 - NULLIFIER) - 1 + 1) + 1;

    /* Range from (COLS - 2) to 1 */
    hero->y = rand() % ((ROWS - 1 - NULLIFIER) - 1 + 1) + 1;
}

/* Hero movement to the top */
void move_hero_up(struct Coord *hero)
{
    if (MAP[hero->y - 1][hero->x] != BORDER_CHAR)
        MAP[hero->y--][hero->x] = ' ';
}

/* Hero movement to the bottom */
void move_hero_down(struct Coord *hero)
{
    if (MAP[hero->y + 1][hero->x] != BORDER_CHAR)
        MAP[hero->y++][hero->x] = ' ';
}

/* Hero movement to the left */
void move_hero_left(struct Coord *hero)
{
    if (MAP[hero->y][hero->x - 1] != BORDER_CHAR)
        MAP[hero->y][hero->x--] = ' ';
}

/* Hero movement to the right */
void move_hero_right(struct Coord *hero)
{
    if (MAP[hero->y][hero->x + 1] != BORDER_CHAR)
        MAP[hero->y][hero->x++] = ' ';
}