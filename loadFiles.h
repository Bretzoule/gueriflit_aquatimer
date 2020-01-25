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
#define ERREUR_ALLOC -1

/*!
  \fn void supprSave(char* filePath)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Sat Jan 25 15:50:04 2020
  \param char* filePath : chemin du fichier à supprimer
  \brief permet de supprimer le fichier de sauvegarde si nécessaire
  \remarks
*/

void supprSave(char* filePath);

/*!
  \fn int saveGameToFile(int** GrilleJ1, int** GrilleJ2, int int_tailleGrille, batostruc* flotte, int int_joueur,int int_nbBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu> & DRAESCHER Lucas <draescherl@eisti.eu>
  \version 0.1
  \date Tue Jan 21 14:31:52 2020
  \brief permet de sauvegarder la partie à un état donné, à l'aide du numéro de joueur, la taille de la grille, le nombre de bateaux, la flotte ainsi que la grille
  \param int** GrilleJ1 : grille de jeu J1
  \param int** GrilleJ2: grille de jeu J2
  \param int int_tailleGrille : taille de la grille en entrée
  \param batostruc* flotte : flotte utilisée
  \param int int_joueur : numéro du joueur
  \param int int_nbBateaux : nombre de bateaux
  \return int int_retour : Retourne 1 si la sauvegarde à été effectuée
  \remarks
*/
int saveGameToFile(int** GrilleJ1, int** GrilleJ2, int int_tailleGrille, batostruc* flotte, int int_joueur,int int_nbBateaux);

/*!
  \fn int askSave(char* filePath, int** GrilleJ1, int** GrilleJ2, int int_tailleGrille, batostruc* flotte, int int_joueur,int int_nbBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu> & DRAESCHER Lucas <draescherl@eisti.eu>
  \version 0.1
  \date Tue Jan 21 14:31:52 2020
  \brief permet de sauvegarder la partie à un état donné, à l'aide du numéro de joueur, la taille de la grille, le nombre de bateaux, la flotte ainsi que la grille
  \param char* filePath : chemin du fichier
  \param int** GrilleJ1: grille de jeu J1
  \param int** GrilleJ2: grille de jeu J2
  \param int int_tailleGrille : taille de la grille en entrée
  \param batostruc* flotte : flotte utilisée
  \param int int_joueur : numéro du joueur
  \param int int_nbBateaux : nombre de bateaux
  \return int int_retour : Retourne 1 si la sauvegarde à été effectuée
  \remarks
*/
int askSave(char* filePath, int** GrilleJ1, int** GrilleJ2, int int_tailleGrille, batostruc* flotte, int int_joueur,int int_nbBateaux);


/*!
  \fn int getIntFromSave(FILE* fichierSav)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 14:02:19 2020
  \brief permet de récupérer un entier sur le flux de fichier
  \param FILE* fichierSav : permet de retourner l'entité FILE* associée au fichier
  \return int int_retour : entier à retourner
  \remarks
*/

int getIntFromSave(FILE* fichierSav);

/*!
  \fn int validationFichier(char* filePath)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Sat Jan 25 19:17:17 2020
  \brief permet de valider ou non un fichier
  \param FILE* fichierSav : fichier en entrée
  \return int int_retour : retourne 1 si tout s'est bien passé
  \remarks
*/

int validationFichier(char* filePath);


/*!
  \fn FILE* openFile(char* filePath)
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
  \fn void askFilePath(char* filePath)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 13:40:29 2020
  \brief permet de récupérer le chemin d'accès au fichier
  \param char* filePath : chemin d'accès au fichier
  \remarks
*/

void askFilePath(char* filePath);


/*!
  \fn int getFlotteFromSave(FILE* fichierSav, int int_nombreBateaux, batostruc* flotteUtilisee)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 14:02:19 2020
  \brief permet de récupérer un entier sur le flux de fichier
  \param FILE* fichierSav : permet de retourner l'entité FILE* associée au fichier
  \param int int_nombreBateau : nombre de bateaux sur la grille
  \param batostruc* flotteUtilisée : flotteutilisée en entrée
  \return batostruc flotteUtilisée : flotteutilisée remplie en sortie
  \remarks
*/
batostruc* getFlotteFromSave(FILE* fichierSav, int int_nombreBateaux, batostruc* flotteUtilisee);

/*!
  \fn void getTabFromSave(FILE* fichierSav,int** GrilleJ1, int** GrilleJ2, int int_tailleGrille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Fri Jan 24 14:46:42 2020
  \brief permet de récupérer la grille depuis la sauvegarde
  \param FILE* fichierSav : permet de retourner l'entité FILE* associée au fichier
  \param int** GrilleJ1 : grille du joueur 1
  \param int** GrilleJ2 : grille de joueur 2 (ou de l'IA)
  \param int int_tailleGrille : taille de la grille en entrée
  \remarks
*/
void getTabFromSave(FILE* fichierSav,int** GrilleJ1, int** GrilleJ2, int int_tailleGrille);

#endif
