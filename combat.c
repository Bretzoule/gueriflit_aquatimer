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
#include "combat.h"
/*!
\fn void tir()
\brief
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date
*/
int tir(int** ppint_grille, int int_coord_x, int int_coord_y){
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
