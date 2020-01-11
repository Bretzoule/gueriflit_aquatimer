/*!
*  \file main.c
*  \author Hugo POINTEREAU <pointereau@eisti.eu>
*  \version 0.1
*  \date 19/12/19
*
*  \brief jeu de la bataille navale
*
*/

/* Inclusion des entêtes de librairies */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "affichage.h"
#include "combat.h"
#include "bateau.h"

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int** ppint_grille;
  int int_okPosee = 0;
  int int_i;
  int int_tailleGrille = 10;
  int int_modePerso = 0;
  batostruc* flotteUtilisee = NULL;
  int int_nombreBateaux = 10;
  printf("Quelle est la taille de votre grille (veuillez entrer 10 pour une grille par défaut)\n");
  int_tailleGrille = demandeValeur(int_tailleGrille);
  while (int_tailleGrille < 7) {
    printf("Vous n'allez pas jouer sur une grille aussi petite quand même (la valeur minimale acceptable est 7) !\n");
    int_tailleGrille = demandeValeur(int_tailleGrille);
  }
  printf("Souhaitez-vous jouer avec une flotte personnalisée ? (1 si oui, 0 si non)\n");
  int_modePerso = demandeValeur(int_modePerso);
  while ((int_modePerso != 0) && (int_modePerso != 1)) {
    printf("J'avais dit 1 ou 0....\n");
    int_modePerso = demandeValeur(int_modePerso);
  }
  if (int_modePerso == 1) {
    int_nombreBateaux = demandeNombreBateau(int_tailleGrille);
  }
  flotteUtilisee = constructionFlotteHumain(flotteUtilisee,int_tailleGrille,int_modePerso,int_nombreBateaux);
  printf("%d \n",int_nombreBateaux);
  init(&ppint_grille, int_tailleGrille);
  afficherGrille(ppint_grille,int_tailleGrille);
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
  for (int i = 0; i < 4; i++) {
    tir(ppint_grille,int_tailleGrille);
    afficherGrille(ppint_grille,int_tailleGrille);
    afficherEnmie(ppint_grille,int_tailleGrille);
    }
  return 0;
}
