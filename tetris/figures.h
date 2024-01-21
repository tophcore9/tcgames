#ifndef TETRIS_FIGURES_H
#define TETRIS_FIGURES_H

#include "env.h"
#include <stdlib.h>
#include <time.h>

struct Figure
{
    Vector3 block1;
    Vector3 block2;
    Vector3 block3;
    Vector3 block4;
};

bool CheckCollisionCubes(Vector3 cube1, Vector3 cube2);
void DrawFigure(struct Figure* figure, Color color);
struct Figure* SpawnL();
struct Figure* SpawnI();
struct Figure* SpawnSquare();
struct Figure* SpawnZ();
struct Figure* SpawnT();
struct Figure* OffsetFigureX(struct Figure* figure, float offsetX);
struct Figure* OffsetFigureY(struct Figure* figure, float offsetY);

Color RandomColor();
struct Figure* RandomFigure();

#endif //TETRIS_FIGURES_H