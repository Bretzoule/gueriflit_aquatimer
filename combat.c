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

/*!
\fn int tir()
\brief
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date
*/
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
/*!
\fn int valitir(int** ppint_grille, int int_coord_x, int int_coord_y)
\brief valide le tir savoir si on a deja tirer
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 06/01/2020
*/
int valitir(int** ppint_grille, int int_coord_x, int int_coord_y){
  int int_retour;
  int_retour=0;
  if ((ppint_grille[int_coord_x][int_coord_y]== 2)||(ppint_grille[int_coord_x][int_coord_y]== -1)) {
    int_retour = 1;
  }
  return (int_retour);
}
/*! // à déplacer d'ici !
  \fn demandeCoord(char** coord)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet de récupérer des coordonées
  \remarks
*/
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
/*!
\fn int Fin(int** ppint_grille,int int_tailleGrille)
\brief condition de fin pour la partie
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 11/01/2020
*/
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
/*!
\fn int rapporttir(int** ppint_grille, int int_coord_x, int int_coord_y,int int_tailleGrille)
\brief dit la du taille du bateaux qui a ete coulé
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 11/01/2020
*/
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
      printf("1\n" );
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
          printf("2\n" );
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
          printf("3\n" );
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
          printf("4\n" );
    }
  }
    return(int_compteur-int_tailleGrille-3);
}
/*!
\fn int tir(int** ppint_grille)
\brief
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date
*/
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
    if (int_coord_x >9) {
      printf("rentrez une coordonnées X valide\n");
      scanf("%s",&coord[0] );
      int_coord_x = (char)toupper(coord[0])-65;
    }
    int_test = valitir(ppint_grille,int_coord_x,int_coord_y);
  } while ((((int_coord_x < 0) || (int_coord_x > int_tailleGrille-1))||((int_coord_y < 0) || (int_coord_y > int_tailleGrille-1))) ||(int_test==1));
  effettir(ppint_grille,int_coord_x,int_coord_y);
  int_retour = rapporttir(ppint_grille,int_coord_x,int_coord_y,int_tailleGrille);
  printf("%d\n",int_retour );
  return(int_retour);
}

/*!
\fn int tirIA(int** ppint_grille)
\brief
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date
*/
int tirIA(int** ppint_grille,int int_tailleGrille){
  char *coord = malloc(sizeof(char) * 2);
  int int_coord_x;
  int int_coord_y;
  int int_retour;
  int int_test;
  do {
    coordIA(int_tailleGrille,coord);
    int_coord_y = atoi(&coord[1]);
    int_coord_x = atoi(&coord[0]);
    int_test = valitir(ppint_grille,int_coord_x,int_coord_y);
  } while ((((int_coord_x < 0) || (int_coord_x > int_tailleGrille-1))||((int_coord_y < 0) || (int_coord_y > int_tailleGrille-1))) ||(int_test==1));
  effettir(ppint_grille,int_coord_x,int_coord_y);
  int_retour = rapporttir(ppint_grille,int_coord_x,int_coord_y,int_tailleGrille);
  printf("%d\n",int_retour );
  free(coord);
  return(int_retour);
}
