#include "feed.h"

// Feed initialisation
void init_feed(struct Coord *feed)
{
    do
    {
        /* Range from (COLS - 3) to 1 */
        feed->x = rand() % ((COLS - 3) - 1 + 1) + 1;

        /* Range from (COLS - 2) to 1 */
        feed->y = rand() % ((ROWS - 2) - 1 + 1) + 1;

        /* Repeat it if the feed collides with the hero */
    } while (MAP[feed->y][feed->x] == HERO_CHAR);
}
