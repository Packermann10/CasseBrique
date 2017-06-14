#include "casse_brique.h"
#include "raquette.h"

//Initialisation de la raquette
void InitPaddle(paddle *J1){

    J1->pos.x=SCREEN_WIDTH/2-64;
    J1->pos.y=SCREEN_HEIGHT-32;

    J1->speed=7;

    J1->height=32;
    J1->width=128;
}

//Permet l'affichage du sprite de la raquette
void DrawPaddle(game *myGame,gameState state, paddle *J1){

        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;


        myGame->g_surface = IMG_Load("./assets/paddle.png");//Chargement de l'image bitmap

         if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", SDL_GetError());
            // handle error
        }

        if(myGame->g_surface){

                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){

                    //Définition du rectangle Source
                    rectangleSource.x=0; //début x
                    rectangleSource.y=0; //début y
                    rectangleSource.w=J1->width; //largeur
                    rectangleSource.h=J1->height; //hauteur

                    //Défintion du rectangle Dest pour dessiner le Bitmap
                    rectangleDest.x=J1->pos.x;//debut x
                    rectangleDest.y=J1->pos.y;//debut y
                    rectangleDest.w=rectangleSource.w; //Largeur
                    rectangleDest.h=rectangleSource.h; //Hauteur

                    SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest);
                }
                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }

        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }
    destroyTexture(myGame);
}

//Gère les déplacements de la raquette, key=1 veut dire que la touche est pressée

void MovePaddle(int key[2],paddle *J1){

    if ((key[0]==1) && (CollisionPaddle(J1)!=left)){

        J1->pos.x-=J1->speed;

    }
    else if ((key[1]==1) && (CollisionPaddle(J1)!=right)){
        J1->pos.x+=J1->speed;
    }

}


//But : gère les collision de la raquette avec les bords

int CollisionPaddle(paddle *J1){

    if (J1->pos.x>=SCREEN_WIDTH-144){

        return right;

    }else if (J1->pos.x<=16){

        return left;
    }

    return 0;

}
