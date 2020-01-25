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

int askLoad(void) {
  int int_load;
  do
  {
    printf("Voulez vous charger une partie déjà commencée ? - Tapez 1 si oui, 0 sinon ! \n");
    int_load = demandeValeur(int_load);
  } while ((int_load != 1) && (int_load != 0));
  return (int_load);
}

void afficheMenu(void) {
  printf("\n");
  printf("██╗     ███████╗     ██████╗ ██╗   ██╗███████╗██████╗ ██╗███████╗██╗     ██╗████████╗\n");
  printf("██║     ██╔════╝    ██╔════╝ ██║   ██║██╔════╝██╔══██╗██║██╔════╝██║     ██║╚══██╔══╝\n");
  printf("██║     █████╗      ██║  ███╗██║   ██║█████╗  ██████╔╝██║█████╗  ██║     ██║   ██\n");
  printf("██║     ██╔══╝      ██║   ██║██║   ██║██╔══╝  ██╔══██╗██║██╔══╝  ██║     ██║   ██║\n");
  printf("███████╗███████╗    ╚██████╔╝╚██████╔╝███████╗██║  ██║██║██║     ███████╗██║   ██║\n");
  printf("╚══════╝╚══════╝     ╚═════╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝╚═╝     ╚══════╝╚═╝   ╚═╝\n");
  printf("\n");
  printf("\n");
  printf("   █████╗  ██████╗ ██╗   ██╗ █████╗ ████████╗██╗███╗   ███╗███████╗██████╗   \n");
  printf("  ██╔══██╗██╔═══██╗██║   ██║██╔══██╗╚══██╔══╝██║████╗ ████║██╔════╝██╔══██╗ \n");
  printf("  ███████║██║   ██║██║   ██║███████║   ██║   ██║██╔████╔██║█████╗  ██████╔╝  \n");
  printf("  ██╔══██║██║▄▄ ██║██║   ██║██╔══██║   ██║   ██║██║╚██╔╝██║██╔══╝  ██╔══██╗  \n");
  printf("  ██║  ██║╚██████╔╝╚██████╔╝██║  ██║   ██║   ██║██║ ╚═╝ ██║███████╗██║  ██║  \n");
  printf("  ╚═╝  ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝  \n");
  printf("\n");
  printf("\n");
  printf("**********************************************************************\n");
  printf("\n");
  printf(" 1 : Bataille Navale sur un même ecran entre 2 joueurs humains !\n");
  printf("\n");
  printf(" 2 : Bataille Navale contre une IA bateau !\n");
  printf("\n");
  printf(" 3 : Bataille Navale contre une IA plus intelligente !\n");
  printf("\n");
  printf(" 4 : Quitter le jeu ! \n");
  printf("\n");
printf("**********************************************************************\n");
  printf("\n");
}


void menu(void){
  int int_load;
  int int_menu; // menu avec indication sur le terminal de ce qu'il faut faire
  afficheMenu();
  int_menu = choixmenu();
  switch (int_menu){ // chaque choix se fait dans ce switch
  case 1 :
    printf("Initialisation mode 1v1 ! \n");
    int_load = askLoad();
    jeuSplitScreen(int_load);
    break;
  case 2 :
    printf("Initialisation mode 1vIA - niveau de difficulté : Mousse ! \n");
    int_load = askLoad();
    jeuIabateau(int_load);
    break;
  case 3 :
    printf("Initialisation mode 1vIA - niveau de difficulté : Barbe Noire ! \n");
    int_load = askLoad();
    jeuIANRV(int_load);
    break;
  default:
    printf("Au revoir ! \n");
    break;
     }
}
