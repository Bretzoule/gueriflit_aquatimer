/*!
*  \file main.c
*  \author Hugo POINTEREAU <pointereau@eisti.eu>
*  \version 0.1
*  \date 19/12/19
*
*  \brief jeu de la bataille navale
*
*/

/* Inclusion des entêtes de librairies */
#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"
#include "combat.h"
#include "bateau.h"


int main(int argc, char const *argv[]) {
  int** ppint_grille;
  init(&ppint_grille);
  afficherGrille(ppint_grille);
  for (int i = 0; i < 4; i++) {
    tir(ppint_grille);
    afficherGrille(ppint_grille);
  }
  return 0;
}
