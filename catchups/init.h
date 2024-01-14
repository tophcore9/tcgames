#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <assert.h>

#define NULLIFIER 1
#define ESC 27
#define ENTER 13

extern int COLS;
extern int ROWS;
extern char **MAP;
extern int SCORE;

extern char BORDER;
extern char HERO_CHAR;
extern char FEED_CHAR;

enum Difficulty
{
    Easy,
    Medium,
    Hard
};

extern enum Difficulty CURRENT_DIFFICULTY;

#endif //INIT_H
