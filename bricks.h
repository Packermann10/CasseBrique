#ifndef BRICKS_H_INCLUDED
#define BRICKS_H_INCLUDED
#include "balle.h"

void InitBricks(bricks Bricks[12][12]);
void CollisionBricks(bricks Bricks[12][12], ball *Ball);
void DrawBricks(game *myGame,gameState state, bricks Bricks[12][12]);

#endif
