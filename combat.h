#ifndef COMBAT_H
#define COMBAT_H

#include <stdlib.h>
#include <stdio.h>
<<<<<<< HEAD

=======
#define ERREURALLOCATION -1
#define BATEAU_VIVANT 1
#define BATEAU_TOUCHE 2
#define EAU_VIVANTE 0
#define EAU_MORTE -1
>>>>>>> 4e8a6e31d55858f0cdca926e5a88246fa2d0d428
#define N 10

int effettir(int** ppint_grille, int int_coord_x, int int_coord_y);
int valitir(int** ppint_grille, int int_coord_x, int int_coord_y);
void demandeCoord(char **coord);
int tir(int** ppint_grille);
#endif
