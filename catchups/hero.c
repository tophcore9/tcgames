#include "hero.h"

int init_hero(struct Hero *hero)
{
    hero->x = rand() % ((COLS - 2 - NULLIFIER) - 1 + 1) + 1;
    hero->y = rand() % ((ROWS - 1 - NULLIFIER) - 1 + 1) + 1;
}
