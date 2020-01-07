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
#endif
