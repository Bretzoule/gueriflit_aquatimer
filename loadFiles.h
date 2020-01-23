#ifndef LOADFILES_H
#define LOADFILES_H
/*! \file loadFiles.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Thu Jan 16 11:41:42 2020
 *
 *  \brief ensemble des fonctions permettant de charger un fichier
 *
 *
 */

// Inclusion des entêtes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bateau.h"
#include <time.h>
#define EXIT_SUCCESS 0
#define ERREUR_SAISIE -1
#define ERREUR_OUVERTURE -1

/*!
  \fn int saveGameToFile(int** Grille, int int_tailleGrille, batostruc* flotte, int int_joueur, int int_nbBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu> & DRAESCHER Lucas <draescherl@eisti.eu>
  \version 0.1
  \date Tue Jan 21 14:31:52 2020
  \brief permet de sauvegarder la partie à un état donné, à l'aide du numéro de joueur, la taille de la grille, le nombre de bateaux, la flotte ainsi que la grille
  \param int** Grille : grille de jeu
  \param int int_tailleGrille : taille de la grille en entrée
  \param batostruc* flotte : flotte utilisée
  \param int int_joueur : numéro du joueur
  \param int int_nbBateaux : nombre de bateaux
  \return int int_retour : Retourne 1 si la sauvegarde à été effectuée
  \remarks
*/
int saveGameToFile(int** GrilleJ1, int** GrilleJ2, int int_tailleGrille, batostruc* flotte, int int_joueur,int int_nbBateaux);

/*!
  \fn int askSave(int** Grille, int int_tailleGrille, batostruc* flotte, int int_joueur, int int_nbBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu> & DRAESCHER Lucas <draescherl@eisti.eu>
  \version 0.1
  \date Tue Jan 21 14:31:52 2020
  \brief permet de sauvegarder la partie à un état donné, à l'aide du numéro de joueur, la taille de la grille, le nombre de bateaux, la flotte ainsi que la grille
  \param int** Grille : grille de jeu
  \param int int_tailleGrille : taille de la grille en entrée
  \param batostruc* flotte : flotte utilisée
  \param int int_joueur : numéro du joueur
  \param int int_nbBateaux : nombre de bateaux
  \return int int_retour : Retourne 1 si la sauvegarde à été effectuée
  \remarks
*/
int askSave(int** GrilleJ1, int** GrilleJ2, int int_tailleGrille, batostruc* flotte, int int_joueur,int int_nbBateaux);


/*!
  \fn int getIntFromSave(FILE* fichierSav)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 14:02:19 2020
  \brief permet de récupérer un entier sur le flux de fichier
  \return int int_retour : entier à retourner
  \remarks
*/

int getIntFromSave(FILE* fichierSav);

/*!
  \fn FILE* openFile(char* filePath[50])
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 13:55:23 2020
  \brief permet d'ouvrir un fichier donné en paramètre
  \param char* filePath : chemin d'accès au fichier
  \return FILE* fichierSav : permet de retourner l'entité FILE* associée au fichier
  \remarks
*/

FILE* openFile(char* filePath);


/*!
  \fn void askFilePath(char* filePath[50])
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 13:40:29 2020
  \brief permet de récupérer le chemin d'accès au fichier
  \param char* filePath : chemin d'accès au fichier
  \remarks
*/

void askFilePath(char* filePath);
#endif
