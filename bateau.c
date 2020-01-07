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
#include <stdio.h>
#include "bateau.h"

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

/*!
  \fn int constructionFlotteHumain(int** ttint_jeu, int tailleGrille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Tue Jan  7 13:19:48 2020
  \brief Permet de récupérer le nombre de bateaux à placer et leur taille/nom
  \param int int_tailleGrille : permet de décider si le joueur joue en mode personnalisé ..x.. ou en mode standard : 10x10
  \return &listedesbateaux : il s'agit de la liste des bateaux utilisés dans la partie
  \remarks
*/

batostruc* constructionFlotteHumain(int int_modePerso) {
  int int_tailleGrille = 10;
  int int_i;
  int int_nombreBateaux = 0;
  batostruc *listedesbateaux;
  if (int_tailleGrille != 10) {
    int_nombreBateaux = demandeNombreBateaux();
    listedesbateaux = malloc(sizeof(batostruc)*int_nombreBateaux);

    for (int_i = 0; int_i < int_nombreBateaux; int_i++)
    {
      construitFlotte(listedesbateaux[int_i]);
    }
  }else
  {
    listedesbateaux = malloc(sizeof(batostruc)*10);
    (listedesbateaux[0]) = {"Porte-Avion", 6 } /* aide inès plz */
     listedesbateaux[1] = ;
      listedesbateaux[2] = ;
      /* ..... à compléter ...... */
  }
  
  
  return(listedesbateaux);
}
