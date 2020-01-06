/*! \file bateau.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Thu Dec 19 11:21:38 2019
 *
 *  \brief ensemble des en-têtes de fct de bateau.c
 *
 *
 */

// Inclusion des entêtes de librairies
#ifndef BATEAU_H
#define BATEAU_H

#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"
#include "combat.h"

#define EXIT_SUCCESS 0
#define ERREUR_SAISIE -1

int voisinNord(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
int voisinNordEst(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
int voisinNordOuest(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
int voisinSud(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
int voisinSudEst(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
int voisinSudOuest(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
int voisinOuest(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
int voisinEst(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur);
/*!
  \fn int checkVideAutour(int** Grille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet d'ajouter un porte avion sur la grille
  \return somme des valeurs des cases autour de la position
  \param int** Grille : grille en entrée
  \param int int_PosX : Position X
  \param int int_PosY : Position Y
  \param int int_tailleGrille : taille de la grille (en x ou en y car grille carrée)
  \remarks permet de récupérer les valeurs des cases voisines
*/
int checkVideAutour(int **Grille, int int_PosX, int int_PosY, int int_tailleGrille);
/*!
  \fn int ajouteBateau(int** Grille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet d'ajouter un bateau sur la grille
  \return int_okPosee : retourne 1 si tout s'est bien déroulé et que le bateau est bien posé, retourne 0 si une erreur s'est produite
  \param int** Grille : grille en entrée
  \param int int_tailleBateau : taille du bateau à poser
  \param int int_tailleGrille : taille de la grille
  \remarks cette fonction doit s'éxécuter tant que le bateau n'est pas correctement positionné sur la grille, ainsi, tant que int_okPosee != 1, la fonction doit se réexécuter avec le code "Erreur de placement"
*/
int ajouteBateau(int **Grille, int int_tailleBateau, int int_tailleGrille);
#endif
