#ifndef AFFICHE_H
#define AFFICHE_H

#include <stdlib.h>
#include <stdio.h>
#include "combat.h"
#include "bateau.h"
#define ERREURALLOCATION -1
#define N 10

void init(int*** ppint_grille);
void afficherGrille(int** ppint_grille);
/*!
  \fn demandeCoord(char** coord)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet de récupérer des coordonées
  \remarks
*/
void demandeCoord(char *coord);
#endif
