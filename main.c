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
#include <time.h>
#include "affichage.h"
#include "combat.h"
#include "bateau.h"
#include "jeu.h"
#include "ia.h"
#include "menu.h"
/*!
  \fn int main (int argc, char** argv)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Sat Jan 25 18:47:14 2020
  \brief Fonction principale
  \param argc : Nombre d'argument
  \param argv : Tableau des arguments
  \return EXIT_SUCCES : le programme doit se terminer normalement
  \remarks
*/
int main(int argc, char** argv) {
  srand(time(NULL));
  menu();
  return EXIT_SUCCESS;
}
