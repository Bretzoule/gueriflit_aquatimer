#ifndef AFFICHE_H
#define AFFICHE_H
/*! \file affichage.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sat Jan 25 18:51:29 2020
 *
 *  \brief Ensemble des fonctions associées à affichage.c
 *
 *
 */

// Inclusion des entêtes de librairies
#include <stdlib.h>
#include <stdio.h>
#define EXIT_SUCCESS 0
#define ERREUR_SAISIE -1


#include <stdlib.h>
#include <stdio.h>
#include "combat.h"
#include "bateau.h"
#define ERREURALLOCATION -1
#define N 10

/*!
\fn void init()
\brief initialise la matrice
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille
\version 0.1
\date 9/12/19
*/
void init(int*** ppint_grille, int int_tailleGrille);

/*!
\fn void afficherGrille(int** ppint_grille)
\brief Permet d'afficher la grille (point de vue allié)
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 9/12/19
*/
void afficherGrille(int** ppint_grille, int int_tailleGrille);

/*!
\fn void afficherenmie(int** ppint_grille,int int_tailleGrile)
\brief Permet d'afficher la grille en cachant les bateaux vivants (point de vue de l'adversaire)
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date
*/
void afficherEnmie(int** ppint_grille,int int_tailleGrille);
#endif
