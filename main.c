#include "casse_brique.h"

//Option de build dans les linker setting mettre les libSDL2main.a libSDL2.dll.a
//Dans search directory
//Option de build compiler mettre les include
//Option de build linker mettre les lib

//mettre dans build linker -lmingw32


int main(int argc, char *argv[])
{

     game myGame;
     gameState state;
     int key[2];    //utiliser dans le déplacement de la raquette
     paddle J1;
     ball Ball;
     bricks Bricks[13][12];    //tableau pour afficher les briques

    //Pour les 60 fps
    unsigned int frameLimit = SDL_GetTicks() + 16;


    if(init("Chapter 1 setting up SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame)){

                state.g_bRunning=1;


    }else{

            return 1;//something's wrong

    }


   state.right=1;
   state.left=0;

    //initialisation des valeurs du paddle/balle/briques
    InitPaddle(&J1);
    InitBall(&Ball);
    InitBricks(Bricks);
    while(state.g_bRunning){     //(state.g_bRunning && Balle.position.y<=SCREEN_HEIGHT){// Si l'on veut faire perdre le joueur lorsque la balle sort de l'écran

           handleEvents(&state, key);
           MovePaddle(key,&J1);
           DrawPaddle(&myGame,state,&J1);
           DrawSide(&myGame,state);
           CollisionBall(&Ball,&J1);
           MoveBall(&Ball);
           DrawBall(&myGame,state,&Ball);
           CollisionBricks(Bricks,&Ball);
           DrawBricks(&myGame,state,Bricks);


           SDL_RenderPresent(myGame.g_pRenderer); // Affichage
           SDL_RenderClear(myGame.g_pRenderer);


        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;


    }

        destroy(&myGame);

        SDL_Quit();




  return 0;
}



