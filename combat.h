#ifndef COMBAT_H
#define COMBAT_H
/*! \file combat.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sat Jan 25 18:50:17 2020
 *
 *  \brief Ensemble des définitions associées à combat.c
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
  \fn int effettir(int** ppint_grille, int int_coord_x, int int_coord_y))
  \brief permet de modifier la valeur d'une case du tableau comme case touchée (bateau touché / eau touché)
  \param int** ppint_grille : grille de jeu
  \param int int_coord_x : coordonnée de tir, X
  \param int int_coord_y : coordonnée de tir, Y
  \return int int_retour : retourne 1 si le tir s'est bien passé, 0 si la case à été manquée
  \author Hugo POINTEREAU <pointereau@eisti.eu>
  \version 0.1
  \date
*/
int effettir(int** ppint_grille, int int_coord_x, int int_coord_y);

/*!
  \fn int valitir(int** ppint_grille, int int_coord_x, int int_coord_y)
  \brief valide le tir savoir si on a deja tirer
  \author Hugo POINTEREAU <pointereau@eisti.eu>
  \param int** ppint_grille : grille de jeu
  \param int int_coord_x : coordonnée de tir, X
  \param int int_coord_y : coordonnée de tir, Y
  \return int int_retour : retourne 1 si le tir est valide, 0 sinon
  \version 0.1
  \date 06/01/2020
*/
int valitir(int** ppint_grille, int int_coord_x, int int_coord_y);

/*!
  \fn demandeCoord(char** coord)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet de récupérer des coordonées
  \param char* coord : coordonnées à modifier en entrée
  \remarks
*/
void demandeCoord(char *coord);

/*!
\fn int tir(int** ppint_grille)
\brief Assure la fonction de tir du programme pour le joueur
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille en entrée
\return int int_retour : 1 si tout s'est bien passé, 0 si une erreur s'est produite / que le tir à échoué
\version 0.1
\date 11/01/2020
*/
int tir(int** ppint_grille,int int_tailleGrille);

/*!
\fn int Fin(int** ppint_grille,int int_tailleGrille)
\brief condition de fin pour la partie
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille
\return int int_compteur : valeur de compteur de case, si une case = 1, on l'incrémente
\date 11/01/2020
*/
int fin(int** ppint_grille,int int_tailleGrille);

/*!
\fn int rapporttir(int** ppint_grille, int int_coord_x, int int_coord_y,int int_tailleGrille)
\brief dit la du taille du bateaux qui a ete coulé
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille
\param int_coord_x : coordonnées en X
\param int_coord_y : coordonnées en Y
\return int_compteur-int_tailleGrille-3 : permet de retourner n'importe quelle valeur différente de -int_tailleGrille-3 si une case est touchée et de retourner la taille du bateau coulé si il est coulé
\version 0.1
\date 11/01/2020
*/
int rapporttir(int** ppint_grille, int int_coord_x, int int_coord_y,int int_tailleGrille);

/*!
\fn int tirIA(int** ppint_grille)
\brief Assure la fonction de tir du programme pour l'IA
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille en entrée
\return int int_retour : 1 si tout s'est bien passé, 0 si une erreur s'est produite / que le tir à échoué
\version 0.1
\date 11/01/2020
*/
int tirIA(int** ppint_grille,int int_tailleGrille);

/*!
\fn int tirIASC(int** ppint_grille,int int_tailleGrille,int int_coord_x,int int_coord_y)
\brief Assure la fonction de tir du programme pour l'IA sans les coordonnées intégrerer
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille en entrée
\param int int_coord_x : coordonnée en x
\param int int_coord_y : coordonnée en y
\return int int_retour : 1 si tout s'est bien passé, 0 si une erreur s'est produite / que le tir à échoué
\version 0.1
\date 11/01/2020
*/
int tirIASC(int** ppint_grille,int int_tailleGrille,int int_coord_x,int int_coord_y);

/*!
\fn int TirV2(int** ppint_grille, int int_coord_x, int int_coord_y,int int_tailleGrille)
\brief Assure la fonction de tir du programme pour l'IA
\author Hugo POINTEREAU <pointereau@eisti.eu>
\param int** ppint_grille : grille en entrée
\param int int_tailleGrille : taille de la grille en entrée
\param int int_coord_x : coordonnée en x
\param int int_coord_y : coordonnée en y
\return int int_retour : 1 si tout s'est bien passé, 0 si une erreur s'est produite / que le tir à échoué
\version 0.1
\date 11/01/2020
*/
int TirV2(int** ppint_grille, int int_coord_x, int int_coord_y,int int_tailleGrille);
#endif
