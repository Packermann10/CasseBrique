#ifndef RAQUETTES_H_INCLUDED
#define RAQUETTES_H_INCLUDED

void DrawPaddle(game *myGame,gameState state, paddle *J1);
void MovePaddle(int key[2],paddle *J1);
void InitPaddle(paddle *J1);
int CollisionPaddle(paddle *J1);

#endif
