#ifndef COMBAT_H
#define COMBAT_H

#include <stdlib.h>
#include <stdio.h>

#define N 10

int effettir(int** ppint_grille, int int_coord_x, int int_coord_y);
int valitir(int** ppint_grille, int int_coord_x, int int_coord_y);
void demandeCoord(char **coord);
int tir(int** ppint_grille);
#endif
