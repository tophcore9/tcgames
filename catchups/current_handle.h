#ifndef CURRENT_HANDLE_H
#define CURRENT_HANDLE_H

#include "hero.h"
#include "feed.h"
#include "enemy.h"

struct CurrentHandle
{
    struct Coord *hero;
    struct Coord *enemy;
    struct Coord *feed;
};

#endif //CURRENT_HANDLE_H
