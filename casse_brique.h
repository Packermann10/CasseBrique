#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <time.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


typedef struct game{


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_texture;
     SDL_Surface *g_surface;


}game;

typedef struct gameState{

    int g_bRunning;
    int left;
    int right;


}gameState;


typedef struct coordonnees{

    double x;
    double y;



}coordonnees;

typedef struct paddle{

    coordonnees pos; //coordonnees raquette
    double speed; //vitesse raquette
    double height;//hauteur raquette
    double width; //largeur raquette

}paddle;

typedef struct ball{

    coordonnees pos;
    double speed; //détermine vitesse de la balle
    double height; //hauteur img
    double width; //largeur img
    int up_down; //rebond ball haut/bas
    int left_right; //rebond balle droite/gauche

}ball;

typedef struct bricks{

    coordonnees pos;//pos x/y
    double height; //hauteur img
    double width; //largeur img
    int destroy;//booléen pour déterminer si un brique doit être détruite ou non

}bricks;

enum collision{

    up,down,left,right  //deplacement raquette
};

//PROTOTYPES
int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame);
void cutBitmapTexture(game *myGame,gameState state);
void delay(unsigned int frameLimit);
void destroyTexture(game *myGame);
void destroy(game *myGame);
void handleEvents(gameState *state, int key[2]);
void DrawSide(game *myGame,gameState state);


