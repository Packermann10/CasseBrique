#include "casse_brique.h"
#include "balle.h"

void InitBall(ball *Ball){

    Ball->pos.x=SCREEN_WIDTH/2-24;
    Ball->pos.y=SCREEN_HEIGHT/2+200;
    Ball->speed=5;
    Ball->height=24;
    Ball->width=24;
    Ball->up_down=0;
    Ball->left_right=0;


}

//Affichage de la balle
void DrawBall(game *myGame,gameState state,ball *Ball){

        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;


        myGame->g_surface = IMG_Load("./assets/ball.png");//Chargement de l'image bitmap

         if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", SDL_GetError());
            // handle error
        }

        if(myGame->g_surface){

                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){

                    //définition du rectangle source
                    rectangleSource.x=0;//début x
                    rectangleSource.y=0;//début y
                    rectangleSource.w=Ball->width; //largeur
                    rectangleSource.h=Ball->height; //hauteur



                    //Définition du rectangle dest pour dessiner Bitmap
                    rectangleDest.x=Ball->pos.x;//debut x
                    rectangleDest.y=Ball->pos.y;//debut y
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

//Deplacement de la balle en fonction des collisions
void MoveBall(ball *Ball){

    if (Ball->up_down==1){    //si 1 alors la balle descend

        Ball->pos.y+=Ball->speed;

    }
    else if (Ball->up_down==0){   //si 0 la balle monte

        Ball->pos.y-=Ball->speed;

    }

    if (Ball->left_right==1){      //si 1 alors la balle va a droite

        Ball->pos.x+=Ball->speed;
    }
    else if (Ball->left_right==0){  //si 0 elle va à gauche

        Ball->pos.x-=Ball->speed;
    }

}

//gestion des collisions de la balle avec le paddle et les murs
void CollisionBall(ball *Ball, paddle *J1){

    if (Ball->pos.x>=SCREEN_WIDTH-40){ //40px car largeur du side =16px et largeur ball -24px

        Ball->left_right=0;

    }else if (Ball->pos.x<=16){   //ici pas besoin de prendre en compte la largeur de la balle
        Ball->left_right=1;
    }

    //Collision avec la raquette le 24px correspond a la largeur de la raquette et 128 la largeur
    if ((Ball->pos.y+24>=J1->pos.y) && (Ball->pos.x>=J1->pos.x) && (Ball->pos.x+24<=J1->pos.x+128)){

        Ball->up_down=0;

    }else if (Ball->pos.y<=0){

        Ball->up_down=1;
    }

}
