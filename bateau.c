/*! \file bateau.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Thu Dec 19 11:19:41 2019
 *
 *  \brief initialisation des bateaux
 *
 *
 */
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "bateau.h"

int demandeValeur(int int_valeur) {
  int int_retour = 0;
  int_retour = scanf("%d", &int_valeur);
    if (int_retour == 0) {
      fprintf(stderr, "Entrée incorrecte\n"); // verification entrée
      exit(ERREUR_SAISIE);
    }
  return (int_valeur);
}

int voisinNord(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[int_x][(int_y - 1 + int_largeur) % int_largeur]);
}

int voisinNordEst(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[(int_x + 1) % int_longueur][(int_y + int_largeur - 1) % int_largeur]);
}

int voisinNordOuest(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[(int_x + int_largeur - 1) % int_largeur][(int_y + int_longueur - 1) % int_longueur]);
}

int voisinSud(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[int_x][(int_y + 1) % int_largeur]);
}

int voisinSudEst(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[(int_x + 1) % int_longueur][(int_y + 1) % int_largeur]);
}

int voisinSudOuest(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[(int_x + int_longueur - 1) % int_longueur][(int_y + 1) % int_largeur]);
}

int voisinOuest(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[(int_x + int_longueur - 1) % int_longueur][(int_y)]);
}

int voisinEst(int **tint_jeu, int int_x, int int_y, int int_longueur, int int_largeur)
{
  return (tint_jeu[(int_x + int_longueur + 1) % int_longueur][(int_y)]);
}

int checkVideAutour(int **tint_jeu, int int_x, int int_y, int int_tailleGrille)
{
  int int_res = 0;
  if ((int_x == 0) && (int_y == 0))
  {
    int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
  }
  else
  {
    if ((int_x == 0) && (int_y == int_tailleGrille))
    {
      int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
    }
    else
    {
      if ((int_x == int_tailleGrille) && (int_y == 0))
      {
        int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
      }
      else
      {
        if ((int_x == int_tailleGrille) && (int_y == int_tailleGrille))
        {
          int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
        }
        else
        {
          if (int_y == 0)
          {
            int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
          }
          if (int_x == 0)
          {
            int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
          }
          if (int_x == int_tailleGrille)
          {
            int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
          }
          if (int_y == int_tailleGrille)
          {
            int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
          }
          else
          {
            int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
          }
        }
      }
    }
  }
  return (int_res);
}

int ajouteBateau(int **Grille, int int_tailleBateau, int int_tailleGrille)
{
  char *coord = malloc(sizeof(char) * 2);
  int int_debutBateauX = 0;
  int int_placementValide = 0;
  int int_debutBateauY = 0;
  int int_finBateauX = 0;
  int int_finBateauY = 0;
  int int_okPosee = 1;
  int int_j;
  int int_i;
  do
  {
    printf("Début du bateau : \n");
    demandeCoord(coord); /* Récupération coordonnées */
    int_debutBateauY = atoi(&coord[1])-1;
    int_debutBateauX = (char)toupper(coord[0])-65;
  } while (((int_debutBateauX >= 0) && (int_debutBateauX < int_tailleGrille) && (int_debutBateauY >= 0) && (int_debutBateauY < int_tailleGrille)) && (checkVideAutour(Grille, int_debutBateauX, int_debutBateauY, int_tailleGrille) != 0)); /* On redemande les coordonnées tant que l'emplacement n'est pas valide */
  int_i = int_debutBateauY;
  int_j = int_debutBateauX;
  do
  {
    printf("Dernière case du bateau");
    demandeCoord(coord);
    int_debutBateauY = atoi(&coord[1])-1;
    int_debutBateauX = (char)toupper(coord[0]) - 65;
  } while ((int_finBateauX >= 0) && (int_finBateauX < int_tailleGrille) && (int_finBateauY >= 0) && (int_finBateauY < int_tailleGrille) && (((abs(int_debutBateauX - int_finBateauX + 1) == int_tailleBateau) && (int_debutBateauY == int_finBateauY)) || ((abs(int_debutBateauY - int_finBateauY + 1) == int_tailleBateau) && (int_debutBateauX == int_finBateauX))) && (checkVideAutour(Grille, int_finBateauY, int_finBateauX, int_tailleGrille) != 0));
  while ((int_i <= int_finBateauY) && (int_placementValide == 1))
  {
    while ((int_j <= int_finBateauX) && (int_placementValide == 1))
    {
      if (checkVideAutour(Grille, int_i, int_j, int_tailleGrille) != 0)
         /* vérification placement valide */
      {
        int_placementValide = 0;
      }
      int_j++;
    }
    int_i++;
  }
  if (int_placementValide == 1)
  {
    for (int_i = int_debutBateauY; int_i <= int_finBateauY; int_i++)
    {
      for (int_j = int_debutBateauX; int_j <= int_finBateauX; int_j++)
      {
        {
          Grille[int_i][int_j] = BATEAU_VIVANT;
        }
      }
    }
  }
  else
  {
    printf("Erreur de placement !");
    int_okPosee = 0;
  }
  free(coord);
  return (int_okPosee); // répéter cette fonction tant que le placement n'est pas valide
}


int demandeNombreBateau(int int_tailleGrille) {
  int int_nbBateau = 0;
  int int_nbMaxBateaux = round((int_tailleGrille*int_tailleGrille)/10);
  printf("Le nombre maximal de bateaux pour une grille de taille \"%d\" est : %d \n", int_tailleGrille, int_nbMaxBateaux);
  while ((int_nbBateau > int_nbMaxBateaux) && (int_nbBateau < 0)) {
    printf("Le nombre entrée dépasse la capacité de la grille !\n");
      int_nbBateau = demandeValeur(int_nbBateau);
  }
  return (int_nbBateau);
}

batostruc* constructionFlotteHumain(batostruc* listedesbateaux,int int_tailleGrille, int int_modePerso) {
  int int_i;
  int int_j;
  int int_k;
  int int_nombreBateaux = 10;
  ptrint_nombreBato = &int_nombreBateaux;
  if (int_modePerso == 1) {
    int_nombreBateaux = demandeNombreBateau(int_tailleGrille);
    listedesbateaux = malloc(sizeof(batostruc)*int_nombreBateaux);
    for (int_i = 0; int_i < int_nombreBateaux; int_i++)
    {
      //construitFlotte(listedesbateaux[int_i]);
    }
  } else
  {
    int_tailleGrille = 10;
    listedesbateaux = malloc(sizeof(batostruc)*int_nombreBateaux);
    strcpy(listedesbateaux[0].nom,"Porte-Avion");
    listedesbateaux[0].taille = 6;
    strcpy(listedesbateaux[1].nom,"Croiseur");
    listedesbateaux[1].taille = 4;
    strcpy(listedesbateaux[2].nom,"Croiseur");
    listedesbateaux[2].taille = 4;
    for (int_k = 3; int_k < 6; int_k++)
    {
      strcpy(listedesbateaux[2].nom,"Sous-Marin");
      listedesbateaux[2].taille = 3;
    }
    for (int_j = 6; int_j < 10; int_j++)
    {
      strcpy(listedesbateaux[int_j].nom,"Torpilleur");
      listedesbateaux[int_j].taille = 2;
    }
  }
  return(listedesbateaux);
}
