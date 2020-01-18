#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#define ERREURALLOCATION -1
#define BATEAU_VIVANT 1
#define BATEAU_TOUCHE 2
#define EAU_VIVANTE 0
#define EAU_MORTE -1
#define N 10

/*!
\fn int menu(void)
\brief créer le menu pour le choix des questions
\author Hugo Pointereau
\return int int_choix : retourne 0 si pas de probleme
*/
int choixmenu(void);

/*!
\fn void menu(void)
\brief permet d'afficher les différentes choix pour les questions
\author Hugo Pointereau
\menu pour le jeu de la bataille navale avec affichage
*/
void menu(void);
#endif
