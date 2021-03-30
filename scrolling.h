#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define w 1360
#define h 560

#define mapw 7478 
#define maph 613

typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ; 

}Objet;



void initialiser (Objet *map  )  ;
void setup (SDL_Surface *screen, Objet *map ) ;
void scrolling_droit (SDL_Surface *screen , Objet *map) ;
void scrolling_gauche (SDL_Surface*screen , Objet *map) ;
void evenement (SDL_Surface *screen ,Objet *boat ,int *running) ;
void free_memory (Objet *map, Mix_Music *musique) ;
