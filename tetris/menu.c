#include "menu.h"

int current_option = 0;

void ShowMenu()
{
    Color color;
    for (int i = 0; i < MENU_OPTIONS; ++i)
    {
        if (i == current_option)
            color = RAYWHITE;
        else
            color = GRAY;

        DrawText(menu_options[i], GetScreenWidth() / 3 - 60, (i + 1) * 60, 40, color);
    }
    MenuHandler();
}
void MenuHandler()
{
    if (IsKeyPressed(KEY_DOWN))
        if (current_option < MENU_OPTIONS - 1)
            ++current_option;
    if (IsKeyPressed(KEY_UP))
        if (current_option > 0)
            --current_option;
    if (IsKeyPressed(KEY_ENTER))
        MenuOptionsHandler(current_option);
}
void MenuOptionsHandler(int option)
{
    switch (option)
    {
        case 0: /* Start new game */
            game_state = StartNewGame;
            break;
        case 1: /* Options */
            game_state = Options;
            break;
        case 2: /* Exit */
            game_state = Exit;
            break;
    }
}
