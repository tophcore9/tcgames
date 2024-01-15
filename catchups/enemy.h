#ifndef ENEMY_H
#define ENEMY_H

#include "init.h"

struct Enemy
{
    int x;
    int y;
};

int find_hero();
int init_enemy(struct Enemy *enemy);

#endif //ENEMY_H
