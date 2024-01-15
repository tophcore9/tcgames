#ifndef ENEMY_H
#define ENEMY_H

#include "init.h"

/* Function that gets the coordinates of the main hero */
struct Coord find_hero();

/* Enemy initialisation */
int init_enemy(struct Coord *enemy);

/* Function for catching main hero by the enemy */
void catch(struct Coord *enemy);

/* Enemy movement to the top */
void move_up(struct Coord *enemy, int step);

/* Enemy movement to the bottom */
void move_down(struct Coord *enemy, int step);

/* Enemy movement to the left */
void move_left(struct Coord *enemy, int step);

/* Enemy movement to the right */
void move_right(struct Coord *enemy, int step);

#endif //ENEMY_H
