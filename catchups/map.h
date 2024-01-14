#ifndef MAP_H
#define MAP_H

#include "current_handle.h"
#include "init.h"

int init_map();
void show_map(struct CurrentHandle *handle);
void movement_handler(struct CurrentHandle *handle);

#endif //MAP_H
