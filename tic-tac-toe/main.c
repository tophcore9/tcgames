#include <stdio.h>

void print_map(char map[3][3]);
void reset_map(char map[3][3]);
int  set_field(char map[3][3], int x, int y, char value);
char check_map_state(char map[3][3]);

int main()
{
    // Map initialization
    char map[3][3];
    reset_map(map);

    // Outputting map
    print_map(map);


    return 0;
}

// Outputting map
void print_map(char map[3][3])
{
    int counter = 0;
    printf("    Game\t\t   Scheme\n");
    printf("+---+---+---+\t\t+---+---+---+\n");
    for (int i = 0; i < 3; ++i)
    {
        printf("| %c | %c | %c |", map[i][0], map[i][1], map[i][2]);

        printf("\t\t| %d | %d | %d |\n", counter + 1, counter + 2, counter + 3);
        counter += 3;

        printf("+---+---+---+\t\t+---+---+---+\n");
    }
}

// Resetting map
void reset_map(char map[3][3])
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            map[i][j] = ' ';
}

// Setting field in the map
int set_field(char map[3][3], int x, int y, char value)
{
    if (x < 3 && x >= 0 && y < 3 && y >= 0)
    {
        map[y][x] = value;
        return 0;
    }

    return 1;
}

// Checking if someone win
// X - X won
// O - O won
// D - Draw
char check_map_state(char map[3][3])
{
    _Bool is_full = 1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (map[i][j] == ' ')
                is_full = 0;
        }
    }
    
    if (is_full == 1) return 'D';
}
