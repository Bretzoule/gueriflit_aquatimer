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
#include <time.h>
#include "ia.h"
#include "bateau.h"

int choixdirectionia(){
  int int_randompos;
  int_randompos = (rand()%(2-1)+1);
  return (int_randompos);
}
int coordIAX(int int_tailleGrille){
  return(rand()%(int_tailleGrille));
}
int coordIAY(int int_tailleGrille){
  return(rand()%(int_tailleGrille));
}

int ajouteBateauIA(int **Grille, int int_tailleBateau, int int_tailleGrille)
{
  int int_debutBateauX = 0;
  int int_debutBateauY = 0;
  int int_okPosee = 1;
  int int_directionBato = 0;
  do
  {
    int_directionBato = choixdirectionia();
    int_debutBateauY = coordIAY(int_tailleGrille);
    int_debutBateauX = coordIAX(int_tailleGrille);
  } while (((int_debutBateauX < 0)  || (int_debutBateauX > int_tailleGrille)) || ((int_debutBateauY < 0) || (int_debutBateauY > int_tailleGrille)) || (checkVideAutour(Grille, int_debutBateauX,int_debutBateauY,int_tailleGrille) != 0) || (Grille[int_debutBateauX][int_debutBateauY] != EAU_VIVANTE)); /* On redemande les coordonnées tant que l'emplacement n'est pas valide */
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
