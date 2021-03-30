
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
#include <SDL/SDL_mixer.h>
void initialiser (Objet *map  ) 
{
  SDL_WM_SetCaption("scrolling", NULL);

  map->img=IMG_Load("map.png") ;
  map->pos.x=0 ;
  map->pos.y=0 ;
  
  

}

void setup (SDL_Surface *screen, Objet *map )
{
  SDL_BlitSurface(map->img,NULL,screen, &(map->pos));
  




  SDL_Flip(screen) ;
}



void scrolling_droit (SDL_Surface *screen , Objet *map)
{
 if (map->pos.x<=6118)
   map->pos.x+=20 ;

   SDL_BlitSurface(map->img,&(map->pos),screen, NULL);
}

void scrolling_gauche (SDL_Surface*screen , Objet *map)
{
 if (map->pos.x>=0)
   map->pos.x-=20 ;
 SDL_BlitSurface(map->img,&(map->pos),screen, NULL);  
}

void evenement (SDL_Surface *screen ,Objet *map,int *running )
{
 SDL_Event event;



 SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                *running = 0;
            break;
            case SDL_KEYDOWN:

               switch(event.key.keysym.sym)

                  {

                     case SDLK_RIGHT: // Flèche droite
            	
                          scrolling_droit (screen ,map) ;

                          SDL_Flip(screen);
                          

                     break;

                     case SDLK_LEFT: // Flèche gauche
                          scrolling_gauche (screen ,map) ;

                          SDL_Flip(screen);
                          

                     break;
              

                  }

            break;    
        }

}


void free_memory (Objet *map,Mix_Music *musique)
{


 SDL_FreeSurface (map->img) ;
 Mix_FreeMusic(musique); //Libération de la musique
   Mix_CloseAudio(); //Fermeture de l'API

 SDL_Quit () ;

}
