#ifndef CURRENT_HANDLE_H
#define CURRENT_HANDLE_H

#include "hero.h"
#include "feed.h"
#include "enemy.h"

struct CurrentHandle
{
    struct Hero *hero;
    struct Enemy *enemy;
    struct Feed *feed;
};

#endif //CURRENT_HANDLE_H
