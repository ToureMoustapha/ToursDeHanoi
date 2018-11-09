#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "constantes.h"
#include "hanoi.h"
#include "hanoi.c"

int main(int argc,char* argv[]){ 
 
 if(SDL_Init(SDL_INIT_VIDEO)<0){
                                fprintf(stderr,"Erreur de chargement du mode video : %s",SDL_GetError());
                                exit(EXIT_FAILURE);
                               }
 else
     if(TTF_Init()==-1){
                        fprintf(stderr,"Erreur de chargement du mode video : %s",SDL_GetError());
                        exit(EXIT_FAILURE);
                       }

 SDL_Surface *ecran=NULL,*fond=NULL,*fond1=NULL,*fond2=NULL,*fond3__2_1=NULL,*fond3__2_2=NULL,*fond3__2_3=NULL,*fond3__2_4=NULL,*fond3__2_5=NULL,*fond3__2_6=NULL;
 SDL_Surface *fond3__2_8=NULL,*fond3__2_7=NULL,*fond3__2_9=NULL,*fond3__2_10=NULL,*fond3__2_11=NULL,*fond3__2_12=NULL,*fond3__2_13=NULL,*fond3__2_14=NULL;
 SDL_Surface *fond3__2_15=NULL;


 PILE P1,P2,P3;

 int continuer1=1, continuer2=1,continuer1_1=1,continuer1_2=1,i=1,j=1,n; 

 SDL_Event event1,event2; 

 SDL_Rect positionFond;
 
 ecran=SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
 SDL_WM_SetCaption("LES TOURS DE HANOIS !",NULL);     

 positionFond.x=0;
 positionFond.y=0;

 fond=IMG_Load("fond.png");
 fond1=IMG_Load("fond1.png");
 fond2=IMG_Load("fond2.png");

 fond3__2_1=IMG_Load("fond3__2_1.png");
 fond3__2_2=IMG_Load("fond3__2_2.png");
 fond3__2_3=IMG_Load("fond3__2_3.png");
 fond3__2_4=IMG_Load("fond3__2_4.png");
 fond3__2_5=IMG_Load("fond3__2_5.png");
 fond3__2_6=IMG_Load("fond3__2_6.png");
 fond3__2_7=IMG_Load("fond3__2_7.png");
 fond3__2_8=IMG_Load("fond3__2_8.png");
 fond3__2_9=IMG_Load("fond3__2_9.png");
 fond3__2_10=IMG_Load("fond3__2_10.png");
 fond3__2_11=IMG_Load("fond3__2_11.png");
 fond3__2_12=IMG_Load("fond3__2_12.png");
 fond3__2_13=IMG_Load("fond3__2_13.png");
 fond3__2_14=IMG_Load("fond3__2_14.png");
 fond3__2_15=IMG_Load("fond3__2_15.png");


 while(continuer1){
      switch(i)
      {
       case 1 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_BlitSurface(fond1,NULL,ecran,&positionFond);
                SDL_Flip(ecran);                   
                break;     
       case 2 : SDL_BlitSurface(fond,NULL,ecran,&positionFond); 
                SDL_BlitSurface(fond2,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                break;
      } 

      continuer2=1;

      while(continuer2){//
           SDL_WaitEvent(&event1);
           switch(event1.type)
           {
            case SDL_QUIT : continuer1=continuer2=0;
                            break;
            case SDL_KEYDOWN : switch(event1.key.keysym.sym)
                               {
                                case SDLK_ESCAPE : continuer1=continuer2=0;
                                                   break;
                                case SDLK_DOWN : switch(i)
                                                 { 
                                                  case 1 : i=2;continuer2=0;  
                                                           break;
                                                  case 2 : i=1;continuer2=0;
                                                           break;
                                                 }
                                                 break;
                                case SDLK_UP : switch(i)
                                               {
                                                case 1 : i=2;continuer2=0;
                                                         break;
                                                case 2 : i=1;continuer2=0;
                                                         break;
                                               }
                                               break;
                                case SDLK_RETURN : switch(i)
                                                   {
                                                    case 1 : continuer1_1=1;
                                                             while(continuer1_1){
                                                                 switch(j)
                                                                 {
                                                                  case 1 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_1,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 2 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_2,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 3 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_3,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 4 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_4,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 5 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_5,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 6 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_6,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 7 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_7,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 8 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_8,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 9 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                           SDL_BlitSurface(fond3__2_9,NULL,ecran,&positionFond);
                                                                           SDL_Flip(ecran);                   
                                                                           break;
                                                                  case 10 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                            SDL_BlitSurface(fond3__2_10,NULL,ecran,&positionFond);
                                                                            SDL_Flip(ecran);                    
                                                                            break;
                                                                  case 11 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                            SDL_BlitSurface(fond3__2_11,NULL,ecran,&positionFond);
                                                                            SDL_Flip(ecran);                   
                                                                            break;
                                                                  case 12 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                            SDL_BlitSurface(fond3__2_12,NULL,ecran,&positionFond);
                                                                            SDL_Flip(ecran);                   
                                                                            break;
                                                                  case 13 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                            SDL_BlitSurface(fond3__2_13,NULL,ecran,&positionFond);
                                                                            SDL_Flip(ecran);                   
                                                                            break;
                                                                  case 14 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                            SDL_BlitSurface(fond3__2_14,NULL,ecran,&positionFond);
                                                                            SDL_Flip(ecran);                   
                                                                            break;
                                                                  case 15 : SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                                                                            SDL_BlitSurface(fond3__2_15,NULL,ecran,&positionFond);
                                                                            SDL_Flip(ecran);                   
                                                                            break;
                                                                 }

                                                                 continuer1_2=1;

                                                                 while(continuer1_2){//
                                                                      SDL_WaitEvent(&event2); 
                                                                      switch(event2.type)
                                                                      {//
                                                                      case SDL_KEYDOWN : switch(event2.key.keysym.sym)
                                                                                         {
                                                                                          case SDLK_ESCAPE : continuer1_1=continuer1_2=0,i=1;
                                                                                                             break;
                                                                                          case SDLK_RETURN : switch(j)
                                                                                                             {
                                                                                                              case 1 : n=1;
                                                                                                                       break;
                                                                                                              case 2 : n=2;
                                                                                                                       break;
                                                                                                              case 3 : n=3;
                                                                                                                       break;
                                                                                                              case 4 : n=4;
                                                                                                                       break;
                                                                                                              case 5 : n=5;
                                                                                                                       break;
                                                                                                              case 6 : n=6;
                                                                                                                       break;
                                                                                                              case 7 : n=7;
                                                                                                                       break;
                                                                                                              case 8 : n=8;
                                                                                                                       break;
                                                                                                              case 9 : n=9;
                                                                                                                       break;
                                                                                                              case 10 : n=10;
                                                                                                                        break;
                                                                                                              case 11 : n=11;
                                                                                                                        break;
                                                                                                              case 12 : n=12;
                                                                                                                        break;
                                                                                                              case 13 : n=13;
                                                                                                                        break;
                                                                                                              case 14 : n=14;
                                                                                                                        break;
                                                                                                              case 15 : n=15;
                                                                                                                        break;
                                                                                                              }
                                                                                                              creerFenetre(&ecran);
                                                                                                              creer_3_poteaux(ecran,&P1,&P2,&P3);
                                                                                                              creerDisques(ecran,n,&P1);
                                                                                                              hanoi(ecran,n,&P1,&P2,&P3);
                                                                                                              SDL_Delay(500);
                                                                                                              continuer1_1=continuer1_2=0;
                                                                                                              continuer2=0;continuer1=i=1;
                                                                                                              break;
                                                                                          case SDLK_RIGHT : switch(j)
                                                                                                           {
                                                                                                            case 1 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 2 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 3 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 4 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 5 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 6 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 7 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 8 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 9 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 10 : j++;continuer1_2=0;
                                                                                                                      break;
                                                                                                            case 11 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 12 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 13 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 14 : j++;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 15 : j=1;continuer1_2=0;
                                                                                                                     break;
                                                                                                            }
                                                                                                            break;
                                                                                          case SDLK_LEFT : switch(j)
                                                                                                           {
                                                                                                            case 1 : j=15;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 2 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 3 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 4 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 5 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 6 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 7 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 8 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 9 : j--;continuer1_2=0;
                                                                                                                     break;
                                                                                                            case 10 : j--;continuer1_2=0;
                                                                                                                      break;
                                                                                                            case 11 : j--;continuer1_2=0;
                                                                                                                      break;
                                                                                                            case 12 : j--;continuer1_2=0;
                                                                                                                      break;
                                                                                                            case 13 : j--;continuer1_2=0;
                                                                                                                      break;
                                                                                                            case 14 : j--;continuer1_2=0;
                                                                                                                      break;
                                                                                                            case 15 : j--;continuer1_2=0;
                                                                                                                      break;
                                                                                                            }//
                                                                                                            break;
                                                                                         }
                                                                                         break;
                                                                      case SDL_QUIT : continuer1_1=continuer1_2=0,i=1;
                                                                                                             break;
                                                                      }
                                                                                    }
                                                                                }
                                                                                break;            
                                                    case 2 : continuer1=continuer2=0;
                                                             break;
                                                   }
                                                   break;
                                
                               }             
                               break;
           }
           break;
                       }
                 }
 if(fond)
          SDL_FreeSurface(fond);
 if(fond1)
          SDL_FreeSurface(fond1);
 if(fond2)
          SDL_FreeSurface(fond2);
 

 if(fond3__2_1)
              SDL_FreeSurface(fond3__2_1);
 if(fond3__2_2)
              SDL_FreeSurface(fond3__2_2);
 if(fond3__2_3)
              SDL_FreeSurface(fond3__2_3);
 if(fond3__2_4)
              SDL_FreeSurface(fond3__2_4);
 if(fond3__2_5)
              SDL_FreeSurface(fond3__2_5);
 if(fond3__2_6)
              SDL_FreeSurface(fond3__2_6);
 if(fond3__2_7)
              SDL_FreeSurface(fond3__2_7);
 if(fond3__2_8)
              SDL_FreeSurface(fond3__2_8);
 if(fond3__2_9)
              SDL_FreeSurface(fond3__2_9);
 if(fond3__2_10)
              SDL_FreeSurface(fond3__2_10);
 if(fond3__2_11)
              SDL_FreeSurface(fond3__2_11);
 if(fond3__2_12)
              SDL_FreeSurface(fond3__2_12);
 if(fond3__2_13)
              SDL_FreeSurface(fond3__2_13);
 if(fond3__2_14)
              SDL_FreeSurface(fond3__2_14);
 if(fond3__2_15)
              SDL_FreeSurface(fond3__2_15);
 

 TTF_Quit();
 SDL_Quit();  
}


 
   





