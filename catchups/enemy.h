#ifndef ENEMY_H
#define ENEMY_H

#include "init.h"

struct Enemy
{
    int x;
    int y;
};

struct Coord find_hero();
int init_enemy(struct Enemy *enemy);
void find_and_kill(struct Enemy *enemy);
void move_up(struct Enemy *enemy, int step);
void move_down(struct Enemy *enemy, int step);
void move_left(struct Enemy *enemy, int step);
void move_right(struct Enemy *enemy, int step);

#endif //ENEMY_H
