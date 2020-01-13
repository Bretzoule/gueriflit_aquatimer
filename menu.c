/*!
*  \file menu.c
*  \author Hugo POINTEREAU <pointereau@eisti.eu>
*  \version 0.1
*  \date 8/01/2020
*  \brief  menu pour le jeu de la bataille naval
*
*/

/* Inclusion des entêtes de librairies */
#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"
#include "combat.h"
#include "bateau.h"
#include "ia.h"
#include "jeu.h"


/*!
\fn int menu(void)
\brief créer le menu pour le choix des questions
\author Hugo Pointereau
\retunr 0 si pas de probleme
*/
int choixmenu(void){ // permet de savoir qu'elle est le nombre pour le menu
  int int_retour;
  int int_choix;
  printf ("Quel est votre choix : ");
  int_retour = scanf ("%d", &int_choix);
     if (int_retour == 0) {
	  printf ("Probleme de saisie\n");
	  exit (-1);
     }
     return (int_choix);
}
/*!
\fn void menu(void)
\brief permet d'afficher les différentes choix pour les questions
\author Hugo Pointereau
\menu pour le jeu de la bataille navale avec affichage
*/
void menu(void){
  int int_menu; // menu avec indication sur le terminal de ce qu'il faut faire
  printf("██████╗  █████╗ ████████╗ █████╗ ██╗██╗     ██╗     ███████╗\n");
  printf("██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║██║     ██║     ██╔════╝\n");
  printf("██████╔╝███████║   ██║   ███████║██║██║     ██║     █████╗  \n");
  printf("██╔══██╗██╔══██║   ██║   ██╔══██║██║██║     ██║     ██╔══╝  \n");
  printf("██████╔╝██║  ██║   ██║   ██║  ██║██║███████╗███████╗███████╗\n");
  printf("╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝╚══════╝\n");
  printf("\n");
  printf("\n");
  printf("    ███╗   ██╗ █████╗ ██╗   ██╗ █████╗ ██╗     ███████╗\n");
  printf("    ████╗  ██║██╔══██╗██║   ██║██╔══██╗██║     ██╔════╝\n");
  printf("    ██╔██╗ ██║███████║██║   ██║███████║██║     █████╗  \n");
  printf("    ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║██║     ██╔══╝  \n");
  printf("    ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║███████╗███████╗\n");
  printf("    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝╚══════╝\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("1: bataille navale sur un même ecran entre 2 joueurs humains\n");
  printf("\n");
  printf("2: bataille navale contre une IA bateau\n");
  printf("\n");
  printf("3: bataille navale contre une IA plus intelligente\n");
  int_menu = choixmenu();
  switch (int_menu){ // chaque choix se fait dans ce switch
  case 1 :
    printf("Initialisation mode 1v1 ! \n");
      jeuSplitScreen();
    break;
  case 2 :
    printf("Initialisation mode 1vIA - niveau de difficulté : Mousse ! \n");
    break;
  case 3 :
    printf("Initialisation mode 1vIA - niveau de difficulté : Barbe Noire ! \n");
    break;
  default:
    printf("Au revoir ! \n");
    break;
     }
}
