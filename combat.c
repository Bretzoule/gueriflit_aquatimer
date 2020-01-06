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
  if (int_retour == 0)
  {
    exit(-1);
  }
}
/*!
\fn int tir(int** ppint_grille)
\brief
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date
*/
int tir(int** ppint_grille){
  char *coord = malloc(sizeof(char) * 2);
  int int_coord_x;
  int int_coord_y;
  int int_retour;
  do {
    demandeCoord(coord);
    int_coord_y = atoi(&coord[1])-1;
    int_coord_x = (char)toupper(coord[0])-65;
  } while (((int_coord_y < 0) || (int_coord_y > 11))&&((11>int_coord_x)||(int_coord_x>0)));//(valitir(ppint_grille,int_coord_x,int_coord_y)!=0)/*);

  int_retour =effettir(ppint_grille,int_coord_x,int_coord_y);
  return(int_retour);
}
