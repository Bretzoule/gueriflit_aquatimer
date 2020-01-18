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

/*!
\fn int choixdirectionia()
\brief random pour la direction du bateau de l'IA
\author Hugo POINTEREAU <pointereau@eisti.eu>
\return int int_randomPos : choix aléatoire d'une direction 
\version 0.1
\date 16/01/2020
*/
int choixdirectionia(void);
/*!
\fn int coordIA(int int_tailleGrille, char *coord)
\brief modifie les coordonnées passées en parametre
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int int_tailleGrile : taille de la grille 
\param char* coord : Coordonnées selectionnées par l'IA
\version 0.1
\date  16/01/2020
*/
void coordIA(int int_tailleGrille,char *coord);
/*!
\fn int coordIA(int int_tailleGrille)
\brief retourner les coordonné pour les bateaux de l'IA
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int** Grille : grille de jeu 
\param int int_tailleGrile : taille de la grille 
\param int int_tailleBateau : taille du bateau à placer
\return int int_okPosee : retourne 1 si tout s'est bien passé, 0 si une erreur s'est produite
\version 0.1
\date  16/01/2020
*/
int ajouteBateauIA(int **Grille, int int_tailleBateau, int int_tailleGrille);
#endif
