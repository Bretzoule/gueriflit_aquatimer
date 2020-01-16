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
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ia.h"
#include "bateau.h"

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
/*!
\fn int choixdirectionia()
\brief random pour la direction du bateau de l'IA
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 16/01/2020
*/
int choixdirectionia(){
  int int_randompos;
  int_randompos = (rand()/(double)RAND_MAX * ((2 - 1) + 1));
  return (int_randompos);
}
/*!
\fn int coordIA(int int_tailleGrille)
\brief retourner les coordonné pour les bateaux de l'IA
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date  16/01/2020
*/
void coordIA(int int_tailleGrille,char *coord){
  int int_X;
  int int_Y;
  int_X = (rand()/(double)RAND_MAX * (int_tailleGrille-1));
  int_Y = (rand()/(double)RAND_MAX * (int_tailleGrille-1));
  coord[0]= int_X;
  coord[1]= int_Y;
}

int ajouteBateauIA(int **Grille, int int_tailleBateau, int int_tailleGrille)
{
  char *coord = malloc(sizeof(char) * 2);
  int int_debutBateauX = 0;
  int int_debutBateauY = 0;
  int int_okPosee = 1;
  int int_directionBato = 0;
  do
  {
    int_directionBato = choixdirectionia();
    coordIA(int_tailleGrille,coord); /* Récupération coordonnées */
    int_debutBateauY = atoi(&coord[1]);
    int_debutBateauX = atoi(&coord[0]);
  } while (((int_debutBateauX < 0)  || (int_debutBateauX > int_tailleGrille)) || ((int_debutBateauY < 0) || (int_debutBateauY > int_tailleGrille)) || (checkVideAutour(Grille, int_debutBateauX,int_debutBateauY,int_tailleGrille) != 0) || (Grille[int_debutBateauX][int_debutBateauY] != EAU_VIVANTE)); /* On redemande les coordonnées tant que l'emplacement n'est pas valide */
    free(coord);
    if (verifRange(int_tailleGrille,int_debutBateauX,int_debutBateauY,int_directionBato,int_tailleBateau) == 1) {
      if (verifVoisins(Grille,int_debutBateauX,int_debutBateauY,int_tailleGrille,int_directionBato,int_tailleBateau) == 1) {
        placeBateau(Grille,int_debutBateauX,int_debutBateauY,int_tailleBateau,int_directionBato);
      } else {
        int_okPosee = 0;
      }
    }
    else {
      int_okPosee = 0;
    }
  return (int_okPosee); // répéter cette fonction tant que le placement n'est pas valide
}
