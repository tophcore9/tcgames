#include "init.h"

int COLS = DEFAULT_COLS;
int ROWS = DEFAULT_ROWS;
char **MAP = NULL;
int SCORE = 0;

char BORDER_CHAR = '#';
char HERO_CHAR = '@';
char FEED_CHAR = '^';

enum Difficulty CURRENT_DIFFICULTY = Easy;
