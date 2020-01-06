#ifndef COMBAT_H
#define COMBAT_H

#include <stdlib.h>
#include <stdio.h>
#define ERREURALLOCATION -1
#define BATEAU_VIVANT 1
#define BATEAU_TOUCHE 2
#define EAU_VIVANTE 0
#define EAU_MORTE -1
#define N 10

int tir(int** ppint_grille, int int_coord_x, int int_coord_y);

#endif
