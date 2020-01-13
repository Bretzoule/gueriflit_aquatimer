/*!
*  \file jeu.c
*  \author Hugo POINTEREAU <pointereau@eisti.eu>
*  \version 0.1
*  \date 8/01/2020
*
*  \brief avec les fonctions de jeu
*
*/

/* Inclusion des entêtes de librairies */
#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"
#include "combat.h"
#include "bateau.h"


/*!
  \fn int askGrille(void)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:02:46 2020
  \brief permet de demander la taille de la grille
  \return int_tailleGrille : taille de la grille de jeu
  \remarks
*/

int askGrille(void) {
  int int_tailleGrille = 0;
  printf("Quelle est la taille de votre grille (veuillez entrer 10 pour une grille par défaut)\n");
  int_tailleGrille = demandeValeur(int_tailleGrille);
  while (int_tailleGrille < 7) {
    printf("Vous n'allez pas jouer sur une grille aussi petite quand même (la valeur minimale acceptable est 7) !\n");
    int_tailleGrille = demandeValeur(int_tailleGrille);
  }
  return (int_tailleGrille);
}

int askFlotteCustom(void) {
  int int_modePerso = -1;
  printf("Souhaitez-vous jouer avec une flotte personnalisée ? (1 si oui, 0 si non)\n");
  int_modePerso = demandeValeur(int_modePerso);
  while ((int_modePerso != 0) && (int_modePerso != 1)) {
    printf("J'avais dit 1 ou 0....\n");
    int_modePerso = demandeValeur(int_modePerso);
  }
  return (int_modePerso);
}

/*!
  \fn void initTabJoueur(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Jan 13 16:31:50 2020
  \brief permet d'initialiser la grille pour un joueur
  \remarks
*/

void initTabJoueur(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur, int int_nombreBateaux) {
  int int_i;
  int int_okPosee;
  printf("Initialisation grille pour le joueur %d ! \n",int_joueur);
  init(&ppint_grille, int_tailleGrille);
  for (int_i = 0; int_i < int_nombreBateaux; int_i++)
  {
    system("clear");
    afficherGrille(ppint_grille,int_tailleGrille);
    printf("Vous placez un %s, taille = %d \n",flotteUtilisee[int_i].nom, flotteUtilisee[int_i].taille);
     do
     {
       int_okPosee = ajouteBateau(ppint_grille,flotteUtilisee[int_i].taille,int_tailleGrille);
       afficherGrille(ppint_grille,int_tailleGrille);
     } while (int_okPosee != 1);
  }
}

void jeuSplitScreen(void) {
  batostruc* flotteUtilisee = NULL;
  int int_tailleGrille;
  int int_modePerso = 0;
  int** ppint_grille_J1;
  int** ppint_grille_J2;
  int int_joueur = 1;
  int int_nombreBateaux = 10;
  int_tailleGrille = askGrille();
  int_modePerso = askFlotteCustom();
  if (int_modePerso == 1) {
    int_nombreBateaux = demandeNombreBateau(int_tailleGrille);
  }
  flotteUtilisee = constructionFlotteHumain(flotteUtilisee,int_tailleGrille,int_modePerso,int_nombreBateaux);
  initTabJoueur(ppint_grille_J1,int_tailleGrille,flotteUtilisee,1,int_nombreBateaux);
  initTabJoueur(ppint_grille_J1,int_tailleGrille,flotteUtilisee,1, int_nombreBateaux);
  while(fin(ppint_grille_J1,int_tailleGrille)!=0 || (fin(ppint_grille_J1,int_tailleGrille)!=0)) {
    if (int_joueur == 1) {
      tir(ppint_grille_J2,int_tailleGrille);
      afficherGrille(ppint_grille_J1,int_tailleGrille);
      afficherEnmie(ppint_grille_J2,int_tailleGrille);
    } else {
      tir(ppint_grille_J1,int_tailleGrille);
      afficherGrille(ppint_grille_J2,int_tailleGrille);
      afficherEnmie(ppint_grille_J1,int_tailleGrille);
    }
    int_joueur = ((int_joueur)%2)+1;
  }
  if (fin(ppint_grille_J1,int_tailleGrille) == 0) {
    printf("Le joueur 2 à gagné la partie ! \n");
  } else {
    printf("Le joueur 1 à gagné la partie ! \n");
  }
  freeGrille(ppint_grille_J1);
  freeGrille(ppint_grille_J2);
  freeTab(flotteUtilisee);
}
