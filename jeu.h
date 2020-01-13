#ifndef JEU_H
#define JEU_H

#include <stdlib.h>
#include <stdio.h>
#define ERREURALLOCATION -1
#define BATEAU_VIVANT 1
#define BATEAU_TOUCHE 2
#define EAU_VIVANTE 0
#define EAU_MORTE -1
#define N 10

/*!
  \fn int askFlotteCustom(void)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:05:02 2020
  \brief permet de demander si l'utilisateur souhaite une flotte personnalisée ou non
  \return int int_modePerso : retourne 1 si le mode est personnalisé, 0 si standard
  \remarks
*/

int askFlotteCustom(void);

/*!
  \fn int askGrille(void)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:02:46 2020
  \brief permet de demander la taille de la grille
  \return int_tailleGrille : taille de la grille de jeu
  \remarks
*/

int askGrille(void);

/*!
  \fn void jeuSplitScreen(void)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:23:34 2020
  \brief permet d'initialiser le jeu en mode joueur vs joueur
  \remarks
*/

void jeuSplitScreen(void);

#endif
