#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
#include <SDL/SDL_mixer.h>

int main()
{SDL_Init(SDL_INIT_VIDEO);
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024);
 Mix_Music *musique; //Création du pointeur de type Mix_Music
   

  
SDL_Surface *screen = NULL ;



Objet map,wood,boat ;
int running=1 ;

 screen= SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);


 

  
  initialiser (&map) ;
musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
Mix_PlayMusic(musique, -1);
setup (screen,&map) ;


  SDL_EnableKeyRepeat(10, 10);
  while(running){
      evenement (screen ,&map,&running  ) ;
     }
    free_memory (&map,musique) ;

    

    return EXIT_SUCCESS;
}
