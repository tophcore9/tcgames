#include "feed.h"

int init_feed(struct Feed *feed)
{
    assert(MAP != NULL);
    do
    {
        feed->x = rand() % ((COLS - 3) - 1 + 1) + 1;
        feed->y = rand() % ((ROWS - 2) - 1 + 1) + 1;
    } while (MAP[feed->y][feed->x] == HERO_CHAR);
}
