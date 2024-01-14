#ifndef CURRENT_HANDLE_H
#define CURRENT_HANDLE_H

#include "hero.h"
#include "feed.h"

struct CurrentHandle
{
    struct Hero *hero;
    struct Feed *feed;
};

#endif //CURRENT_HANDLE_H
