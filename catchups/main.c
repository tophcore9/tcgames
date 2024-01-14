#include "game.h"

/// TODO: Make interactive menu and dynamic settings for practice
int main()
{
    if (run() != EXIT_SUCCESS)
        puts("It seems that your program ended incorrect :(");

    getch();
    return 0;
}
