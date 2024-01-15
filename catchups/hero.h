#ifndef HERO_H
#define HERO_H

#include "init.h"

/* Hero initialisation */
void init_hero(struct Coord *hero);

/* Hero movement to the top */
void move_hero_up(struct Coord *hero);

/* Hero movement to the bottom */
void move_hero_down(struct Coord *hero);

/* Hero movement to the left */
void move_hero_left(struct Coord *hero);

/* Hero movement to the right */
void move_hero_right(struct Coord *hero);

#endif //HERO_H
