#ifndef IA_H
#define IA_H

#include <stdlib.h>
#include <stdio.h>
#define ERREURALLOCATION -1
#define BATEAU_VIVANT 1
#define BATEAU_TOUCHE 2
#define EAU_VIVANTE 0
#define EAU_MORTE -1
#define N 10

int choixdirectionia();
void coordIA(int int_tailleGrille,char *coord);
int ajouteBateauIA(int **Grille, int int_tailleBateau, int int_tailleGrille);
#endif
