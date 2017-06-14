#include "casse_brique.h"
#include "bricks.h"


//initialisation des briques une par une
void InitBricks(bricks Bricks[12][12]){

    int i;
    int j;

    for (i=0;i<12;i++){
        for (j=0;j<12;j++){

            Bricks[i][j].height=24;//on met en place les futures dimensions de briques
            Bricks[i][j].width=64;
            Bricks[i][j].pos.x=16+i*Bricks[i][j].width; //32 car on prend en compte la largeur des deux side 16+16
            Bricks[i][j].pos.y=j*Bricks[i][j].height;
            Bricks[i][j].destroy=0;

        }
    }


}

//affichage des briques, si une brique est détruite elle ne s'affiche plus
void DrawBricks(game *myGame,gameState state, bricks Bricks[12][12]){


        int i;
        int j;
        int color;

        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;

        myGame->g_surface = IMG_Load("./assets/bricks.png");//Chargement de l'image bitmap

         if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", SDL_GetError());
            // handle error
        }

        if(myGame->g_surface){

                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){

                    for (i=0;i<12;i++){
                        for (j=0;j<12;j++){
                            if (Bricks[i][j].destroy==0){
                            color=rand()%4; //ici problème de couleur car le random fait une boucle et je n'ai pas su où le mettre
                            if (color==0){

                            //defintion rectangle source
                            rectangleSource.x=64; //ici on a la couleur jaune
                            rectangleSource.y=0;
                            rectangleSource.w=Bricks[i][j].width;
                            rectangleSource.h=Bricks[i][j].height;

                            } else if (color==1){
                            //defintion rectangle source
                            rectangleSource.x=0; //ici on a la couleur rouge
                            rectangleSource.y=0;
                            rectangleSource.w=Bricks[i][j].width;
                            rectangleSource.h=Bricks[i][j].height;

                            } else if (color==2){
                            //defintion rectangle source
                            rectangleSource.x=0; //ici on a la couleur verte
                            rectangleSource.y=24;
                            rectangleSource.w=Bricks[i][j].width;
                            rectangleSource.h=Bricks[i][j].height;

                            } else if (color==3){
                            //defintion rectangle source
                            rectangleSource.x=64; //ici on a la couleur bleue
                            rectangleSource.y=24;
                            rectangleSource.w=Bricks[i][j].width;
                            rectangleSource.h=Bricks[i][j].height;
                            }

                            //Définition du rectangle dest pour dessiner Bitmap
                            rectangleDest.x=Bricks[i][j].pos.x;//debut x
                            rectangleDest.y=Bricks[i][j].pos.y;//debut y
                            rectangleDest.w=rectangleSource.w; //Largeur
                            rectangleDest.h=rectangleSource.h; //Hauteur

                            SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest);

                            }
                        }
                    }

                }

                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }

    destroyTexture(myGame);


}

//gestion des collisions briques/balle
void CollisionBricks(bricks Bricks[12][12], ball *Ball){
    int i;
    int j;

    for (i=0;i<12;i++){
        for (j=0;j<12;j++){
            //si la balle touche un des cotés d'une brique
            if ((Ball->pos.x+Ball->width>=Bricks[i][j].pos.x)&&(Ball->pos.x<=Bricks[i][j].pos.x+Bricks[i][j].width)&&
            (Ball->pos.y+Ball->height>=Bricks[i][j].pos.y)&&(Ball->pos.y<=Bricks[i][j].pos.y+Bricks[i][j].height) && Bricks[i][j].destroy==0){

                    if (Ball->pos.x + Ball->width>=Bricks[i][j].pos.x && Ball->pos.x + Ball->width<=Bricks[i][j].pos.x+5){

                        Ball->left_right=0;

                    } else if (Ball->pos.x<=Bricks[i][j].pos.x+Bricks[i][j].width && Ball->pos.x>=Bricks[i][j].pos.x+Bricks[i][j].width-5){

                        Ball->left_right=1;

                    } else if (Ball->pos.y+Ball->height>=Bricks[i][j].pos.y && Ball->pos.y<=Bricks[i][j].pos.y+5){

                        Ball->up_down=0;

                    } else if (Ball->pos.y <= Bricks[i][j].pos.y+Bricks[i][j].height && Ball->pos.y >= Bricks[i][j].pos.y+Bricks[i][j].height-5){

                        Ball->up_down=1;
                    }

                Bricks[i][j].destroy=1; //la brique se détruit

            }

        }
    }

}

