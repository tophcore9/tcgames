#include "feed.h"
#include <stdio.h>

void init_feed(struct Feed *feed)
{
    if (MAP != NULL)
    {
        do
        {
            feed->x = rand() % ((COLS - 3) - 1 + 1) + 1;
            feed->y = rand() % ((ROWS - 2) - 1 + 1) + 1;
        } while (MAP[feed->y][feed->x] == HERO_CHAR);
    }
    else printf("WTFFFFF");
}
