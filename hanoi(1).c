#include "hanoi.h"
#include "constantes.h"

void creerFenetre(SDL_Surface** ecran){

      *ecran=SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
      if(!(*ecran)){
                    fprintf(stderr,"Erreur,m�moire insuffisante : %s \n",SDL_GetError());
                    exit(EXIT_FAILURE);
                   }
      SDL_FillRect(*ecran,NULL,SDL_MapRGB((*ecran)->format,0,0,0));

                SDL_Surface* TRectangles[HAUTEUR_SOL]={NULL};
                SDL_Rect Position;
                int i;
                for(i=0;i<HAUTEUR_SOL;i++){
                                  TRectangles[i]=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_FENETRE,1,32,0,0,0,0);
                                  if(!TRectangles[i]){
                                                      fprintf(stderr,"Erreur,m�moire insufisante : %s\n",SDL_GetError());
                                                      exit(EXIT_FAILURE);
                                                     }
                                  SDL_FillRect(TRectangles[i],NULL,SDL_MapRGB((*ecran)->format,243,54,0));
                                  Position.x=0;
                                  Position.y=700+i;
                                  SDL_BlitSurface(TRectangles[i],NULL,*ecran,&Position);

                                 }
                
                SDL_Flip(*ecran);
                for(i=0;i<HAUTEUR_SOL;i++)
                                  SDL_free(TRectangles[i]);
}


void creer_3_poteaux(SDL_Surface* ecran,PILE* p_P1 ,PILE* p_P2,PILE* p_P3){ // ON A D�JA REPLACER LES CONSTANTES.
 p_P3->sommet=p_P2->sommet=p_P1->sommet=0;
 SDL_Surface *Depart=NULL,*Intermediaire=NULL,*Arrivee=NULL;

 Depart=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_POTEAUX,HAUTEUR_POTEAUX,32,0,0,0,0);
 p_P1->T[p_P1->sommet].x=ABSCISSE_POTEAU1;
 p_P1->T[p_P1->sommet].y=ORDONEE_POTEAUX;
 SDL_FillRect(Depart,NULL,SDL_MapRGB(ecran->format,255,0,0));
 SDL_BlitSurface(Depart,NULL,ecran,p_P1->T);
 p_P1->T[p_P1->sommet].y +=HAUTEUR_POTEAUX;

 Intermediaire=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_POTEAUX,HAUTEUR_POTEAUX,32,0,0,0,0);
 p_P2->T[p_P2->sommet].x=ABSCISSE_POTEAU2;
 p_P2->T[p_P2->sommet].y=ORDONEE_POTEAUX;
 SDL_FillRect(Intermediaire,NULL,SDL_MapRGB(ecran->format,255,0,0));
 SDL_BlitSurface(Intermediaire,NULL,ecran,p_P2->T);
 p_P2->T[p_P2->sommet].y +=HAUTEUR_POTEAUX;

 Arrivee=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_POTEAUX,HAUTEUR_POTEAUX,32,0,0,0,0);
 p_P3->T[p_P3->sommet].x=ABSCISSE_POTEAU3;
 p_P3->T[p_P3->sommet].y=ORDONEE_POTEAUX;
 SDL_FillRect(Arrivee,NULL,SDL_MapRGB(ecran->format,255,0,0));
 SDL_BlitSurface(Arrivee,NULL,ecran,p_P3->T);
 p_P3->T[p_P3->sommet].y +=HAUTEUR_POTEAUX;

 SDL_Flip(ecran);
 SDL_FreeSurface(Depart);
 SDL_FreeSurface(Intermediaire);
 SDL_FreeSurface(Arrivee);
}

void creerDisques(SDL_Surface* ecran,int n,PILE* p_P1){
 SDL_Surface *disque=NULL;
 disque=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_PLUS_GRAND_DISQUE,HAUTEUR_DISQUE,32,0,0,0,0);
 p_P1->T[1].x=p_P1->T[0].x-(LARGEUR_PLUS_GRAND_DISQUE-10)/2;
 p_P1->T[1].y=p_P1->T[0].y-20; 
 p_P1->sommet++;
 SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
 SDL_BlitSurface(disque,NULL,ecran,p_P1->T+p_P1->sommet);

 SDL_Delay(700);
 SDL_Flip(ecran);
 SDL_Delay(700);
 while(p_P1->sommet<n){
                       SDL_Surface *disque=NULL;
                       disque=SDL_CreateRGBSurface(SDL_HWSURFACE,p_P1->T[p_P1->sommet].w-20,HAUTEUR_DISQUE,32,0,0,0,0);
                       p_P1->T[p_P1->sommet+1].x=p_P1->T[p_P1->sommet].x+10;
                       p_P1->T[p_P1->sommet+1].y=p_P1->T[p_P1->sommet].y-20; 
                       p_P1->sommet++;
                       SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
                       SDL_BlitSurface(disque,NULL,ecran,p_P1->T+p_P1->sommet);

                       SDL_Flip(ecran);
                       SDL_FreeSurface(disque);
                       SDL_Delay(700);
                      }
 SDL_FreeSurface(disque);
}

void deplacerUnDisqueVersDroite(SDL_Surface* ecran,PILE* p_gauche,PILE* p_droite){

 if(p_gauche->sommet>0){
     SDL_Surface *disque=NULL,*rempli_ecran=NULL,*rempli_poteau=NULL;
     SDL_Rect Position;
     while(p_gauche->T[p_gauche->sommet].y > SOMMET_MAX_DES_DISQUES){
           rempli_ecran=SDL_CreateRGBSurface(SDL_HWSURFACE,p_gauche->T[p_gauche->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
           SDL_FillRect(rempli_ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
           SDL_BlitSurface(rempli_ecran,NULL,ecran,p_gauche->T + p_gauche->sommet);

           if(p_gauche->T[p_gauche->sommet].y >=280){
                                                     rempli_poteau=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_POTEAUX,HAUTEUR_DISQUE,32,0,0,0,0);
                                                     SDL_FillRect(rempli_poteau,NULL,SDL_MapRGB(ecran->format,255,0,0));
                                                     Position.x=p_gauche->T[0].x;
                                                     Position.y=p_gauche->T[p_gauche->sommet].y;
                                                     SDL_BlitSurface(rempli_poteau,NULL,ecran,&Position);  
                                                    }

           disque=SDL_CreateRGBSurface(SDL_HWSURFACE,p_gauche->T[p_gauche->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
           SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
           p_gauche->T[p_gauche->sommet].y-=VITESSE_PARCOURS_DISC;
           SDL_BlitSurface(disque,NULL,ecran,p_gauche->T + p_gauche->sommet);
           SDL_Flip(ecran);
           
           if(p_gauche->T[p_gauche->sommet].y+VITESSE_PARCOURS_DISC >=280) 
                                                                         SDL_FreeSurface(rempli_poteau);                                                                  
           SDL_FreeSurface(disque);
           SDL_FreeSurface(rempli_ecran);
                                                                       }

 int x_darret=p_droite->T[0].x - (p_gauche->T[p_gauche->sommet].w - 10)/2;
 while(p_gauche->T[p_gauche->sommet].x < x_darret){
                                                   rempli_ecran=SDL_CreateRGBSurface(SDL_HWSURFACE,p_gauche->T[p_gauche->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                   SDL_FillRect(rempli_ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
                                                   SDL_BlitSurface(rempli_ecran,NULL,ecran,p_gauche->T + p_gauche->sommet);

                                                   disque=SDL_CreateRGBSurface(SDL_HWSURFACE,p_gauche->T[p_gauche->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                   SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
                                                   p_gauche->T[p_gauche->sommet].x+=VITESSE_PARCOURS_DISC;
                                                   SDL_BlitSurface(disque,NULL,ecran,p_gauche->T + p_gauche->sommet);
                                                   SDL_Flip(ecran);

                                                   SDL_FreeSurface(disque);
                                                   SDL_FreeSurface(rempli_ecran);
                                                  }

 while(p_gauche->T[p_gauche->sommet].y <= p_droite->T[p_droite->sommet].y-22){

      rempli_ecran=SDL_CreateRGBSurface(SDL_HWSURFACE,p_gauche->T[p_gauche->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
      SDL_FillRect(rempli_ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
      SDL_BlitSurface(rempli_ecran,NULL,ecran,p_gauche->T + p_gauche->sommet);

      if(p_gauche->T[p_gauche->sommet].y >=300){
                                                rempli_poteau=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_POTEAUX,HAUTEUR_DISQUE,32,0,0,0,0);
                                                SDL_FillRect(rempli_poteau,NULL,SDL_MapRGB(ecran->format,255,0,0));
                                                Position.x=p_droite->T[0].x;
                                                Position.y=p_gauche->T[p_gauche->sommet].y;
                                                SDL_BlitSurface(rempli_poteau,NULL,ecran,&Position);                                       
                                               }

      disque=SDL_CreateRGBSurface(SDL_HWSURFACE,p_gauche->T[p_gauche->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
      SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
      p_gauche->T[p_gauche->sommet].y+=VITESSE_PARCOURS_DISC;
      SDL_BlitSurface(disque,NULL,ecran,p_gauche->T + p_gauche->sommet);
      SDL_Flip(ecran);

      if(p_gauche->T[p_gauche->sommet].y-VITESSE_PARCOURS_DISC >=300)
                                                SDL_FreeSurface(rempli_poteau);                                                  
      SDL_FreeSurface(disque);
      SDL_FreeSurface(rempli_ecran);
                                                                             }
     p_droite->sommet++;
     p_droite->T[p_droite->sommet]=p_gauche->T[p_gauche->sommet];
     p_gauche->sommet--;
                       }
}

void deplacerUnDisqueVersGauche(SDL_Surface* ecran,PILE* p_droite,PILE* p_gauche){

  if(p_droite->sommet>0){
                        SDL_Surface *disque=NULL,*rempli_ecran=NULL,*rempli_poteau=NULL;
     SDL_Rect Position;
     while(p_droite->T[p_droite->sommet].y > SOMMET_MAX_DES_DISQUES){
                                                  rempli_ecran=SDL_CreateRGBSurface(SDL_HWSURFACE,p_droite->T[p_droite->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                  SDL_FillRect(rempli_ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
                                                  SDL_BlitSurface(rempli_ecran,NULL,ecran,p_droite->T + p_droite->sommet);

                                                  if(p_droite->T[p_droite->sommet].y >=280){
                                                                                           rempli_poteau=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_POTEAUX,HAUTEUR_DISQUE,32,0,0,0,0);
                                                                                           SDL_FillRect(rempli_poteau,NULL,SDL_MapRGB(ecran->format,255,0,0));
                                                                                           Position.x=p_droite->T[0].x;
                                                                                           Position.y=p_droite->T[p_droite->sommet].y;
                                                                                           SDL_BlitSurface(rempli_poteau,NULL,ecran,&Position);
                                                                                           }

                                                  disque=SDL_CreateRGBSurface(SDL_HWSURFACE,p_droite->T[p_droite->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                  SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
                                                  p_droite->T[p_droite->sommet].y-=VITESSE_PARCOURS_DISC;
                                                  SDL_BlitSurface(disque,NULL,ecran,p_droite->T + p_droite->sommet);
                                                  SDL_Flip(ecran);
                                                   
                                                  if(p_droite->T[p_droite->sommet].y+VITESSE_PARCOURS_DISC>=280)
                                                                                                                SDL_FreeSurface(rempli_poteau);
                                                  SDL_FreeSurface(disque);
                                                  SDL_FreeSurface(rempli_ecran);
                                                 
                                                  }

 int x_darret=p_gauche->T[0].x - (p_droite->T[p_droite->sommet].w - 10)/2;
 while( x_darret < p_droite->T[p_droite->sommet].x){
                                                    rempli_ecran=SDL_CreateRGBSurface(SDL_HWSURFACE,p_droite->T[p_droite->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                    SDL_FillRect(rempli_ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
                                                    SDL_BlitSurface(rempli_ecran,NULL,ecran,p_droite->T + p_droite->sommet);

                                                    disque=SDL_CreateRGBSurface(SDL_HWSURFACE,p_droite->T[p_droite->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                    SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
                                                    p_droite->T[p_droite->sommet].x-=VITESSE_PARCOURS_DISC;
                                                    SDL_BlitSurface(disque,NULL,ecran,p_droite->T + p_droite->sommet);
                                                    SDL_Flip(ecran);

                                                    SDL_FreeSurface(disque);
                                                    SDL_FreeSurface(rempli_ecran);
                                                  }
 while(p_droite->T[p_droite->sommet].y <= p_gauche->T[p_gauche->sommet].y-22){
                                                                              rempli_ecran=SDL_CreateRGBSurface(SDL_HWSURFACE,p_droite->T[p_droite->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                                              SDL_FillRect(rempli_ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
                                                                              SDL_BlitSurface(rempli_ecran,NULL,ecran,p_droite->T + p_droite->sommet);

                                                                              if(p_droite->T[p_droite->sommet].y >=300){
                                                                                                                        rempli_poteau=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_POTEAUX,HAUTEUR_DISQUE,32,0,0,0,0);
                                                                                                                        SDL_FillRect(rempli_poteau,NULL,SDL_MapRGB(ecran->format,255,0,0));
                                                                                                                        Position.x=p_gauche->T[0].x;
                                                                                                                        Position.y=p_droite->T[p_droite->sommet].y;
                                                                                                                  SDL_BlitSurface(rempli_poteau,NULL,ecran,&Position);
                                                                                                                       }

                                                                              disque=SDL_CreateRGBSurface(SDL_HWSURFACE,p_droite->T[p_droite->sommet].w,HAUTEUR_DISQUE,32,0,0,0,0);
                                                                              SDL_FillRect(disque,NULL,SDL_MapRGB(ecran->format,0,255,0));
                                                                              p_droite->T[p_droite->sommet].y+=VITESSE_PARCOURS_DISC;
                                                                              SDL_BlitSurface(disque,NULL,ecran,p_droite->T + p_droite->sommet);
                                                                              SDL_Flip(ecran);
                                                                              
                                                                              if(p_droite->T[p_droite->sommet].y-VITESSE_PARCOURS_DISC >=300)
                                                                                                                         SDL_FreeSurface(rempli_poteau);
                                                                              SDL_FreeSurface(disque);
                                                                              SDL_FreeSurface(rempli_ecran);
                                                                              
                                                                             }
     p_gauche->sommet++;
     p_gauche->T[p_gauche->sommet]=p_droite->T[p_droite->sommet];
     p_droite->sommet--;
                       }
}

void hanoi(SDL_Surface* ecran,int n,PILE* depart,PILE* intermediaire,PILE* arrivee){
 if(n>0){
         hanoi(ecran,n-1,depart,arrivee,intermediaire);

         if(depart->T[0].x < arrivee->T[0].x)
                                             deplacerUnDisqueVersDroite(ecran,depart,arrivee);
         else
             deplacerUnDisqueVersGauche(ecran,depart,arrivee);

         hanoi(ecran,n-1,intermediaire,depart,arrivee);
 }
}
