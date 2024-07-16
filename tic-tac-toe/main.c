#include <stdio.h>

void print_map(_Bool map[3][3]);
void reset_map(_Bool map[3][3]);
int set_field(_Bool map[3][3], int x, int y, _Bool value);

int main()
{
    // Map initialization
    _Bool map[3][3] = {0};
    set_field(map, 0, 0, 1);
    set_field(map, 0, 2, 1);
    set_field(map, 1, 1, 1);
    set_field(map, 2, 1, 1);
    reset_map(map);

    // Outputting map
    print_map(map);


    return 0;
}

// Outputting map
void print_map(_Bool map[3][3])
{
    printf("| ");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            printf("%d | ", map[i][j]);

        if (i < 2)
            printf("\n| ");
        else
            printf("\n");
    }
}

// Resetting map
void reset_map(_Bool map[3][3])
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            map[i][j] = 0;
}

// Setting field in the map
int set_field(_Bool map[3][3], int x, int y, _Bool value)
{
    if (x < 3 && x >= 0 && y < 3 && y >= 0)
    {
        map[y][x] = value;
        return 0;
    }

    return 1;
}
