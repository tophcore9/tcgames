#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void print_map(char map[9]);
void reset_map(char map[9]);
int  set_field(char map[9], char current_player, int index);
char check_map_state(char map[9]);
void change_player(char *player);
void clear_console();

int main()
{
    // Game initialization
    char current_player, game_state;
    char map[9];
    reset_map(map);

    while (1)
    {
        printf("Who will be first? (X/Y): ");
        scanf("%c", &current_player);

        current_player = toupper(current_player);

        if (current_player == 'X' || current_player == 'Y')
            break;
    }

    clear_console();

    while (game_state = (check_map_state(map) == 'N'))
    {
        clear_console();
        printf("\t\t\b%c turn\n", current_player);

        // Outputting map
        print_map(map);

        int index = -1;
        while (1)
        {
            printf("Enter a field: ");
            scanf("%d", &index);

            if (set_field(map, current_player, index) == 0)
                break;
        }
        
        change_player(&current_player);
    }

    clear_console();
    print_map(map);
    change_player(&current_player);
    printf("Player '%c' Won!\n", current_player);


    return 0;
}

// Outputting map
void print_map(char map[9])
{
    printf("    Game\t\t   Scheme\n");
    printf("+---+---+---+\t\t+---+---+---+\n");
    for (int i = 0; i < 9;)
    {
        printf("| %c | %c | %c |", map[i], map[i+1], map[i+2]);

        printf("\t\t| %d | %d | %d |\n", i + 1, i + 2, i + 3);
        i += 3;

        printf("+---+---+---+\t\t+---+---+---+\n");
    }
}

// Resetting map
void reset_map(char map[9])
{
    for (int i = 0; i < 9; ++i)
        map[i] = ' ';
}

// Setting field in the map
int set_field(char map[9], char current_player, int index)
{
    --index;
    if (index < 9 && index >= 0 && map[index] == ' ')
    {
        map[index] = current_player;
        return 0;
    }

    return 1;
}

// Checking if someone win
// X - X won
// O - O won
// D - Draw
// N - Game is not over
char check_map_state(char map[9])
{
    _Bool is_full = 1;
    for (int i = 0; i < 9; ++i)
    {
        if (map[i] == ' ')
        {
            is_full = 0;
            break;
        }
    }

    if      (map[0] != ' ' && map[0] == map[1] && map[1] == map[2]) return map[0];
    else if (map[3] != ' ' && map[3] == map[4] && map[4] == map[5]) return map[3];
    else if (map[6] != ' ' && map[6] == map[7] && map[7] == map[8]) return map[6];
    else if (map[0] != ' ' && map[0] == map[3] && map[3] == map[6]) return map[0];
    else if (map[1] != ' ' && map[1] == map[4] && map[4] == map[7]) return map[1];
    else if (map[2] != ' ' && map[2] == map[4] && map[4] == map[6]) return map[2];
    else if (map[0] != ' ' && map[0] == map[4] && map[4] == map[8]) return map[0];
    else if (map[2] != ' ' && map[2] == map[4] && map[4] == map[8]) return map[2];
    
    if (is_full == 1) return 'D';

    return 'N';
}

void change_player(char *player)
{
    if (*player == 'X')
        *player = 'Y';
    else if (*player == 'Y')
        *player = 'X';
}

void clear_console()
{
    system("clear");
}
