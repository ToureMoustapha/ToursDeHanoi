#ifndef HANOI_H_INCLUDED
#define HANOI_H_INCLUDED

#include "constantes.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct pile{
        SDL_Rect T[TAILLE_T+1];
        int sommet;
        }PILE;

void creerFenetre(SDL_Surface**);
void creer_3_poteaux(SDL_Surface*,PILE*,PILE*,PILE*);
void creerDisques(SDL_Surface*,int,PILE*);
void deplacerUnDisqueVersDroite(SDL_Surface*,PILE*,PILE*);
void deplacerUnDisqueVersDroite(SDL_Surface*,PILE*,PILE*);
void hanoi(SDL_Surface*,int,PILE*,PILE*,PILE*);

void pause();

#endif // HANOI_H_INCLUDED
