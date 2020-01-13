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

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  menu();
  return 0;
}
