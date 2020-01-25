#ifndef IA_H
#define IA_H
/*! \file ia.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sat Jan 25 19:04:48 2020
 *
 *  \brief  Ensemble des définitions des fonctions de ia.c
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
\fn int choixdirectionia(void)
\brief random pour la direction du bateau de l'IA
\author Hugo POINTEREAU <pointereau@eisti.eu>
\return int int_randomPos : choix aléatoire d'une direction
\version 0.1
\date 16/01/2020
*/
int choixdirectionia(void);
/*!
\fn int coordIAX(int int_tailleGrille);
\brief modifie les coordonnées passées en parametre
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int int_tailleGrile : taille de la grille
\return coord X
\version 0.1
\date  16/01/2020
*/
int coordIAX(int int_tailleGrille);
/*!
\fn int coordIAY(int int_tailleGrille);
\brief modifie les coordonnées passées en parametre
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int int_tailleGrile : taille de la grille
\return coord Y
\version 0.1
\date  16/01/2020
*/
int coordIAY(int int_tailleGrille);
/*!
\fn int ajouteBateauIA(int **Grille, int int_tailleBateau, int int_tailleGrille);
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
