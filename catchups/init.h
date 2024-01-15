#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <assert.h>

#define NULLIFIER 1 /* \0 */
#define ESC 27
#define ENTER 13

#define DEFAULT_COLS 20
#define DEFAULT_ROWS 10
#define DEFAULT_BORDER_CHAR '#'
#define DEFAULT_HERO_CHAR '@'
#define DEFAULT_FEED_CHAR '*'
#define DEFAULT_ENEMY_CHAR '&'

#define HERO_IS_KILLED 1
#define HERO_IS_ALIVE 0

extern int COLS;
extern int ROWS;
extern char **MAP;
extern int SCORE;

extern char BORDER_CHAR;
extern char HERO_CHAR;
extern char FEED_CHAR;
extern char ENEMY_CHAR;

enum Difficulty
{
    Easy,
    Medium,
    Hard
};

struct Coord
{
    int x;
    int y;
};

extern enum Difficulty CURRENT_DIFFICULTY;

#endif //INIT_H
