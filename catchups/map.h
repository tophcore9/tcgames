#ifndef MAP_H
#define MAP_H

#include "current_handle.h"
#include "init.h"

/* Map initialisation */
void init_map();

/* Showing the map */
void show_map(struct CurrentHandle *handle);

/* Motion control */
int movement_handler(struct CurrentHandle *handle, char input);

#endif //MAP_H
