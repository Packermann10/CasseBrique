#ifndef BALLE_H_INCLUDED
#define BALLE_H_INCLUDED
#include "raquette.h"

void InitBall(ball *Ball);
void DrawBall(game *myGame,gameState state,ball *Ball);
void CollisionBall(ball *Ball, paddle *J1);
void MoveBall(ball *Ball);

#endif
