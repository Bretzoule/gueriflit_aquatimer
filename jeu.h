#ifndef JEU_H
#define JEU_H
/*! \file jeu.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sat Jan 25 19:04:26 2020
 *
 *  \brief Ensemble des définitions des fonctions de jeu.c
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
  \fn void jeuSplitScreen(int int_loadGame)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:23:34 2020
  \brief permet d'initialiser le jeu en mode joueur vs joueur
  \param int int_loadGame : 1 si l'on commence une nouvelle partie, 0 si on en charge une
  \remarks
*/
void jeuSplitScreen(int int_loadGame);

/*!
  \fn void initTabJoueur(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur, int int_nombreBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:31:50 2020
  \brief permet d'initialiser la grille pour un joueur
  \remarks
*/

void initTabJoueur(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur, int int_nombreBateaux);

/*!
  \fn void freeGrille(int*** ppint_matrice, int int_tailleGrille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 17:25:40 2020
  \param int*** ppint_matrice : matrice à libérer
  \param int int_tailleGrille : taille de la matrice
  \brief permet de libérer la grille
  \remarks
*/

void freeGrille(int*** ppint_matrice, int int_tailleGrille);

/*!
  \fn void testToucheCoule(int int_valeurTouche, int int_tailleFlotte, int int_tailleGrille, batostruc* flotte, int int_joueur)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 16 09:48:20 2020
  \brief permet de dire si un bateau à été touché, coulé ou touché coulé (rapporte le type de bateau coulé
  \param int int_valeurTouche : si != (-int_tailleGrille-3), bateau touché, si positif, bateau coulé
  \param int int_tailleFlotte : taille de la flotte utilisée
  \param int int_tailleGrille : taille de la grille utilisée
  \param batostruc* : flotte utilisée
  \param int int_joueur : numero du joueur
  \remarks
*/

void testToucheCoule(int int_valeurTouche, int int_tailleFlotte, int int_tailleGrille, batostruc* flotte, int int_joueur);

/*!
  \fn void initTabIA(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur, int int_nombreBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 16 09:48:20 2020
  \brief permet de dire si un bateau à été touché, coulé ou touché coulé (rapporte le type de bateau coulé
  \param int** ppint_grille : grille de jeu
  \param int int_nombreBateaux : taille de la flotte utilisée
  \param int int_tailleGrille : taille de la grille utilisée
  \param batostruc* : flotte utilisée
  \param int int_joueur : numero du joueur
  \remarks
*/
void initTabIA(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur, int int_nombreBateaux);


/*!
  \fn int joueJoueur(int** GrilleAttaque, int** GrilleDefense,int int_nombreBateaux,int int_tailleGrille,batostruc* flotteUtilisee,int int_joueur)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 09:49:01 2020
  \brief permet de dérouler les fonctions de tir, de mise à jour de la grille et d'affichage du jeu
  \param int** GrilleAttaque : grille de jeu en attaque
  \param int** GrilleDefense : grille de jeu en défense
  \param int int_tailleGrille : taille de la grille en entrée
  \param batostruc* flotte : flotte utilisée
  \param int int_joueur : numéro du joueur
  \param int int_nombreBateaux : nombre de bateaux
  \remarks
*/

int joueJoueur(int** GrilleAttaque, int** GrilleDefense,int int_nombreBateaux,int int_tailleGrille,batostruc* flotteUtilisee,int int_joueur);

/*!
  \fn jeuIabateau(int int_loadGame);
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:23:34 2020
  \brief permet d'initialiser le jeu en mode joueur vs IA Facile
  \param int int_loadGame : 1 si l'on commence une nouvelle partie, 0 si on en charge une
  \remarks
*/
void jeuIabateau(int int_loadGame);
/*!
  \fn jeuIANRV(int int_loadGame);
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:23:34 2020
  \brief permet d'initialiser le jeu en mode joueur vs IA plus intelligente
  \param int int_loadGame : 1 si l'on commence une nouvelle partie, 0 si on en charge une
  \remarks
*/

void jeuIANRV(int int_loadGame);
/*!
  \fn void afficheVictoire(void)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Tue Jan 21 13:57:22 2020
  \brief permet d'afficher le trophée
  \remarks
*/

void afficheVictoire(void);

#endif
