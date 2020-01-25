#ifndef MENU_H
#define MENU_H
/*! \file menu.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sat Jan 25 18:46:13 2020
 *
 *  \brief Ensemble des déclarations associées à menu.c
 *
 *
 */

// Inclusion des entêtes de librairies
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

/*!
  \fn void afficheMenu(void)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Sat Jan 25 17:57:38 2020
  \brief permet d'afficher le menu
  \remarks
*/

void afficheMenu(void);

/*!
  \fn int askLoad(void)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Tue Jan 21 14:26:53 2020
  \brief permet de demander si l'utilisateur veut charger une partie
  \return int int_load : 1 si l'utilisateur veut charger, 0 sinon
  \remarks
*/
int askLoad(void);

#endif
