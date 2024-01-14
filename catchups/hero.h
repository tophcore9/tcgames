#ifndef HERO_H
#define HERO_H

#include "init.h"

struct Hero
{
    int x;
    int y;
    char input;
};

int init_hero(struct Hero *hero);

#endif //HERO_H
