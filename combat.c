/*!
*  \file combat.c
*  \author Hugo POINTEREAU <pointereau@eisti.eu>
*  \version 0.1
*  \date
*
*  \brief effectue les fonctions de tir
*
*/

/* Inclusion des entêtes de librairies */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "combat.h"
#include "affichage.h"
#include "ia.h"


int effettir(int** ppint_grille, int int_coord_x, int int_coord_y){
  int int_retour;
  int_retour=0;
  if (ppint_grille[int_coord_x][int_coord_y]== 1) {
      ppint_grille[int_coord_x][int_coord_y] = 2;
      int_retour =1;
  }
  else{
    ppint_grille[int_coord_x][int_coord_y] = -1;
  }
  return(int_retour);
}

int valitir(int** ppint_grille, int int_coord_x, int int_coord_y){
  int int_retour;
  int_retour=0;
  if ((ppint_grille[int_coord_x][int_coord_y]== 2)||(ppint_grille[int_coord_x][int_coord_y]== -1)) {
    int_retour = 1;
  }
  return (int_retour);
}

void demandeCoord(char *coord)
{
  int int_retour;
  printf("Entrez vos coordonnées de la forme \"A9\"\n");
  fflush(stdin);
  int_retour = scanf("%s", coord);
  fflush(stdin);
  if (int_retour == 0)
  {
    exit(ERREUR_SAISIE);
  }
}

int fin(int** ppint_grille,int int_tailleGrille){
  int int_compteur;
  int_compteur =0;
  for (int i = 0; i < int_tailleGrille; i++) {
    for (int j = 0; j < int_tailleGrille; j++) {
      if (ppint_grille[i][j]==1) {
        int_compteur = int_compteur +1;
      }
    }
  }
  return (int_compteur);
}

int rapporttir(int** ppint_grille, int int_coord_x, int int_coord_y,int int_tailleGrille){
  int int_compteur;
  int int_X;
  int int_Y;
  int_compteur =0;
  int_X = int_coord_x;
  int_Y = int_coord_y;
  if (ppint_grille[int_coord_x][int_coord_y]==2) {
    int_compteur =int_tailleGrille ;
    while ((int_coord_x <int_tailleGrille)&&((ppint_grille[int_coord_x][int_coord_y]==1)||(ppint_grille[int_coord_x][int_coord_y]==2))) {
      if (ppint_grille[int_coord_x][int_coord_y]==1) {
        int_compteur = 0;
        int_coord_x = int_coord_x +1;
      } else {
        int_compteur = int_compteur+1;
        int_coord_x = int_coord_x +1;
      }
    }
    int_coord_x =int_X;
    while ((-1 <int_coord_x)&&((ppint_grille[int_coord_x][int_coord_y]==1)||(ppint_grille[int_coord_x][int_coord_y]==2))) {
      if (ppint_grille[int_coord_x][int_coord_y]==1) {
        int_compteur = 0;
        int_coord_x = int_coord_x -1;
      }
      else {
      int_coord_x = int_coord_x -1;
      int_compteur = int_compteur+1;
    }
    }
    int_coord_x =int_X;
    while ((int_coord_y <int_tailleGrille)&&((ppint_grille[int_coord_x][int_coord_y]==1)||(ppint_grille[int_coord_x][int_coord_y]==2))) {
      if (ppint_grille[int_coord_x][int_coord_y]==1) {
        int_compteur = 0;
        int_coord_y = int_coord_y +1;
      }else {
      int_coord_y = int_coord_y +1;
      int_compteur = int_compteur+1;
    }
    }
    int_coord_y =int_Y;
    while ((-1 <int_coord_y)&&((ppint_grille[int_coord_x][int_coord_y]==1)||(ppint_grille[int_coord_x][int_coord_y]==2))) {
      if (ppint_grille[int_coord_x][int_coord_y]==1) {
        int_compteur = 0;
        int_coord_y = int_coord_y -1;
      } else {
      int_coord_y = int_coord_y -1;
      int_compteur = int_compteur+1;
    }
    }
  }
    return(int_compteur-int_tailleGrille-3);
}

int tir(int** ppint_grille,int int_tailleGrille){
  char *coord = malloc(sizeof(char) * 2);
  int int_coord_x;
  int int_coord_y;
  int int_retour;
  int int_test;
  do {
    demandeCoord(coord);
    int_coord_y = atoi(&coord[1])-1;
    int_coord_x = (char)toupper(coord[0])-65;
    if (int_coord_x >int_tailleGrille - 1) {
      printf("Entrez une coordonnées X valide\n");
      scanf("%s",&coord[0] );
      int_coord_x = (char)toupper(coord[0])-65;
    }
    int_test = valitir(ppint_grille,int_coord_x,int_coord_y);
  } while ((((int_coord_x < 0) || (int_coord_x > int_tailleGrille-1))||((int_coord_y < 0) || (int_coord_y > int_tailleGrille-1))) ||(int_test==1));
  effettir(ppint_grille,int_coord_x,int_coord_y);
  int_retour = rapporttir(ppint_grille,int_coord_x,int_coord_y,int_tailleGrille);
  return(int_retour);
}

int tirIA(int** ppint_grille,int int_tailleGrille){
  char *coord = malloc(sizeof(char) * 2);
  int int_coord_x;
  int int_coord_y;
  int int_retour;
  int int_test;
  do {

    int_coord_y = coordIAY(int_tailleGrille);
    int_coord_x = coordIAX(int_tailleGrille);
    int_test = valitir(ppint_grille,int_coord_x,int_coord_y);
  } while ((((int_coord_x < 0) || (int_coord_x > int_tailleGrille-1))||((int_coord_y < 0) || (int_coord_y > int_tailleGrille-1))) ||(int_test==1));
  effettir(ppint_grille,int_coord_x,int_coord_y);
  int_retour = rapporttir(ppint_grille,int_coord_x,int_coord_y,int_tailleGrille);
  free(coord);
  return(int_retour);
}


int tirIASC(int** ppint_grille,int int_tailleGrille,int int_coord_x,int int_coord_y){
  int int_retour;
  effettir(ppint_grille,int_coord_x,int_coord_y);
  int_retour = rapporttir(ppint_grille,int_coord_x,int_coord_y,int_tailleGrille);
  return(int_retour);
}



int TirV2(int** ppint_grille, int int_coord_x, int int_coord_y,int int_tailleGrille){
  int int_retour;
  int int_X;
  int int_Y;
  int_X = int_coord_x;
  int_Y = int_coord_y;
  if (ppint_grille[int_coord_x][int_coord_y]==2) {
    int_coord_x= int_coord_x+1;
    while ((int_coord_x <int_tailleGrille)&&(ppint_grille[int_coord_x][int_coord_y]==1)) {
      int_retour=tirIASC(ppint_grille,int_tailleGrille,int_coord_x,int_coord_y);
      int_coord_x= int_coord_x+1;
      }
    int_coord_x =int_X;
    int_coord_x= int_coord_x-1;
    while ((-1 <int_coord_x)&&(ppint_grille[int_coord_x][int_coord_y]==1)) {
      int_retour=tirIASC(ppint_grille,int_tailleGrille,int_coord_x,int_coord_y);
      int_coord_x= int_coord_x-1;
    }
    int_coord_x =int_X;
    int_coord_y= int_coord_y+1;
    while ((int_coord_y <int_tailleGrille)&&(ppint_grille[int_coord_x][int_coord_y]==1)) {
      int_retour=tirIASC(ppint_grille,int_tailleGrille,int_coord_x,int_coord_y);
      int_coord_y= int_coord_y+1;
    }
    int_coord_y =int_Y;
    int_coord_y= int_coord_y-1;
    while ((-1 <int_coord_y)&&(ppint_grille[int_coord_x][int_coord_y]==1)) {
      int_retour=tirIASC(ppint_grille,int_tailleGrille,int_coord_x,int_coord_y);
      int_coord_y= int_coord_y-1;
    }
  }
    return(int_retour);
}
