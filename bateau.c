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
  fflush(stdin);
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
    printf("Je rentre dans 0,0 \n");
    int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
  }
  else
  {
    if ((int_x == 0) && (int_y == int_tailleGrille))
    {
      printf("Je rentre dans 0,max \n");
      int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
    }
    else
    {
      if ((int_x == int_tailleGrille) && (int_y == 0))
      {
        printf("Je rentre dans max,0 \n");
        int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
      }
      else
      {
        if ((int_x == int_tailleGrille) && (int_y == int_tailleGrille))
        {
          printf("Je rentre dans max,max \n");
          int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
        }
        else
        {
          if ((int_y == 0) && (int_x != 0))
          {
            printf("Je rentre dans x,0 \n");
            int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
          }
          else
          { if ((int_x == 0) && (int_y != 0))
            {
              printf("Je rentre dans 0,y \n");
              int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
            } else
            { if ((int_x == int_tailleGrille) && (int_y != int_tailleGrille) && (int_y != 0))
              {
                printf("Je rentre dans max,y \n");
                int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
              } else
              { if ((int_y == int_tailleGrille) && (int_x != int_tailleGrille) && (int_x != 0))
                {
                  printf("Je rentre dans x,max \n");
                  int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
                }
                else
                {
                  printf("Je rentre dans x,y \n");
                  int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
                }
              }
            }
          }
        }
      }
    }
  }
  printf("La valeur du voisin est : %d \n",int_res);
  return (int_res);
}

int askDirection(int int_directionBato) {
  printf("Veuillez choisir la direction du bateau en cours de placement : \n");
  printf("1 - Horizontal (Droite) \n");
  printf("2 - Vertical (Bas)\n");
  do
  {
    int_directionBato = demandeValeur(int_directionBato);
  } while ((int_directionBato != 1) && (int_directionBato != 2));
  return (int_directionBato);
}

int verifRange(int int_longueurTab, int int_X, int int_Y, int int_Direction,int int_tailleBateau) {
  int int_valide = 0;
  if (int_Direction == 2) { // orienté vertical sud
    if ((int_X + int_tailleBateau) < int_longueurTab) {
      int_valide = 1;
    }
    printf("Int_valide = %d \n",int_valide);
  } else {
   if ((int_Y + int_tailleBateau) < int_longueurTab) {
     int_valide = 1;
    }
  }
  return (int_valide);
}

int verifVoisins(int** Grille, int int_X, int int_Y, int int_tailleGrille, int int_directionBateau, int int_tailleBateau) {
  int int_valide = 0;
  int int_i = 0;
  if (int_directionBateau == 2) {
    int_i = int_X;
    while ((int_i < int_X + int_tailleBateau) && (checkVideAutour(Grille, int_i,int_Y, int_tailleGrille) == 0)) {
      int_i++;
    }
    if (int_i == int_tailleBateau+int_X) {
      int_valide = 1;
    }
  } else {
    int_i = int_Y;
    while ((int_i < int_Y + int_tailleBateau) && (checkVideAutour(Grille, int_X,int_i, int_tailleGrille) == 0)) {
      int_i++;
    }
    if (int_i == int_tailleBateau+int_Y) {
      int_valide = 1;
    }
  }
  printf("int_valide = %d \n", int_valide);
  return (int_valide);
}

void placeBateau(int** Grille, int int_debutBateauX, int int_debutBateauY, int int_tailleBateau, int int_directionBateau) {
  int int_i = 0;
  if (int_directionBateau == 2) {
    int_i = int_debutBateauX;
    while (int_i < (int_debutBateauX + int_tailleBateau)) {
      printf("Zouloued \n");
      Grille[int_i][int_debutBateauY] = BATEAU_VIVANT;
      int_i++;
    }
  } else {
    int_i = int_debutBateauY;
    while (int_i < (int_debutBateauY + int_tailleBateau)) {
      printf("Chibros \n");
     Grille[int_debutBateauX][int_i] = BATEAU_VIVANT;
      int_i++;
    }
  }
}


int ajouteBateau(int **Grille, int int_tailleBateau, int int_tailleGrille)
{
  char *coord = malloc(sizeof(char) * 2);
  int int_debutBateauX = 0;
  int int_debutBateauY = 0;
  int int_okPosee = 1;
  int int_directionBato = 0;
  int_directionBato = askDirection(int_directionBato);
  do
  {
    printf("Début du bateau : \n");
    demandeCoord(coord); /* Récupération coordonnées */
    int_debutBateauY = atoi(&coord[1])-1;
    int_debutBateauX = (char)toupper(coord[0])-65;
    printf("int_debutBatoX = %d\n",int_debutBateauX);
  } while (((int_debutBateauX < 0)  || (int_debutBateauX > int_tailleGrille)) || ((int_debutBateauY < 0) || (int_debutBateauY > int_tailleGrille)) || (checkVideAutour(Grille, int_debutBateauX,int_debutBateauY,int_tailleGrille) != 0) || (Grille[int_debutBateauX][int_debutBateauY] != EAU_VIVANTE)); /* On redemande les coordonnées tant que l'emplacement n'est pas valide */
    free(coord);
    if (verifRange(int_tailleGrille,int_debutBateauX,int_debutBateauY,int_directionBato,int_tailleBateau) == 1) {
      if (verifVoisins(Grille,int_debutBateauX,int_debutBateauY,int_tailleGrille,int_directionBato,int_tailleBateau) == 1) {
        placeBateau(Grille,int_debutBateauX,int_debutBateauY,int_tailleBateau,int_directionBato);
      } else {
        int_okPosee = 0;
      }
    }
    else {
      int_okPosee = 0;
    }
  return (int_okPosee); // répéter cette fonction tant que le placement n'est pas valide
}


int demandeNombreBateau(int int_tailleGrille) {
  int int_nbBateau = 0;
  int int_nbMaxBateaux = round((int_tailleGrille*int_tailleGrille)/10);
  printf("Le nombre maximal de bateaux pour une grille de taille \"%d\" est : %d \n", int_tailleGrille, int_nbMaxBateaux);
  int_nbBateau = demandeValeur(int_nbBateau);
  while ((int_nbBateau > int_nbMaxBateaux) && (int_nbBateau < 0)) {
    printf("Le nombre entrée dépasse la capacité de la grille ! \n");
      int_nbBateau = demandeValeur(int_nbBateau);
  }
  return (int_nbBateau);
}

batostruc* constructionFlotteHumain(batostruc* listedesbateaux,int int_tailleGrille, int int_modePerso, int int_nombreBateaux) {
  int int_i;
  int int_j;
  int int_k;
  if (int_modePerso == 1) {
    listedesbateaux = malloc(sizeof(batostruc)*int_nombreBateaux);
    for (int_i = 0; int_i < int_nombreBateaux; int_i++)
    {
      listedesbateaux[int_i] = construitFlotte(listedesbateaux[int_i],int_tailleGrille);
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
      strcpy(listedesbateaux[int_k].nom,"Sous-Marin");
      listedesbateaux[int_k].taille = 3;
    }
    for (int_j = 6; int_j < 10; int_j++)
    {
      strcpy(listedesbateaux[int_j].nom,"Torpilleur");
      listedesbateaux[int_j].taille = 2;
    }
  }
  return(listedesbateaux);
}

batostruc construitFlotte(batostruc bateau, int int_tailleGrille) {
  char str_tmp[20];
  do
  {
    printf("Veuillez entrer la taille de votre bateau (cette valeur doit être inférieure à la taille de la grille, ici %d) : \n",int_tailleGrille);
    bateau.taille = demandeValeur(bateau.taille);
  } while ((bateau.taille < 0) && (bateau.taille > int_tailleGrille));
    printf("Veuillez entrer le nom de votre bateau (taille du mot inférieure à 20 caractères et sans espaces !) \n");
    fflush(stdin);
    scanf("%s", str_tmp);
    fflush(stdin);
    strcpy(bateau.nom,str_tmp);
    printf("Votre bateau est un : %s de taille %d \n",bateau.nom,bateau.taille);
  return(bateau);
}
