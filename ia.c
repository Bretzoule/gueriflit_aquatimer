/*! \file bateau.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mon Jan 6 17:19:41 2020
 *
 *  \brief .c relatif à l'intelligence artificielle
 *
 *
 */
/*!
\fn int tireIARandom(char *coord)
\brief  tire de manière aléatoire
\author LEFLOCH Thomas <leflochtho@eisti.eu>
\version 0.1
\date 9/12/19
\param int** tint_jeu : grille de jeu
\param int int_tailleGrille : taille de la grille
*/

#include "ia.h"

void tireIARandom(int **tint_jeu, int int_tailleGrille)
{
    int int_coord1 = 0;
    int int_coord2 = 0;
    do
    {
        int_coord1 = (rand()/(double)RAND_MAX * ((int_tailleGrille - 1) + 1));
        int_coord2 = (rand()/(double)RAND_MAX * ((int_tailleGrille - 1) + 1));
    } while ((tint_jeu[int_coord1][int_coord2] != 0) && (tint_jeu[int_coord1][int_coord2] != 1));
}
