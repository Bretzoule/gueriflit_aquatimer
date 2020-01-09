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

/*!
  \fn void demandeString(char*
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan  9 13:47:44 2020
  \brief
  \remarks
*/


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
  printf("Veuillez choisir la direction du bateau en cours de placement :");
  printf("1 - Horizontal (Droite)");
  printf("2 - Vertical (Bas)");
  do
  {
    int_directionBato = demandeValeur(int_directionBato);
  } while ((int_directionBato != 1) || (int_directionBato != 2));
  return (int_directionBato);
}

int ajouteBateau(int **Grille, int int_tailleBateau, int int_tailleGrille)
{
  char *coord = malloc(sizeof(char) * 2);
  int int_debutBateauX = 0;
  int int_placementValide = 0;
  int int_debutBateauY = 0;
  int int_okPosee = 1;
  int int_directionBato;
  int_directionBato = askDirection(int_directionBato);
  do
  {
    printf("Début du bateau : \n");
    demandeCoord(coord); /* Récupération coordonnées */
    int_debutBateauY = atoi(&coord[1])-1;
    int_debutBateauX = (char)toupper(coord[0])-65;
    printf("int_debutBatoX = %d\n",int_debutBateauX);
  } while (( placementValide || (int_debutBateauX < 0)  || (int_debutBateauX > int_tailleGrille)) || ((int_debutBateauY < 0) || (int_debutBateauY > int_tailleGrille)) || (checkVideAutour(Grille, int_debutBateauX,int_debutBateauY,int_tailleGrille) != 0) || (Grille[int_debutBateauX][int_debutBateauY] != EAU_VIVANTE)); /* On redemande les coordonnées tant que l'emplacement n'est pas valide */
    free(coord);
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

/*!
  \fn batostruc construitFlotte(batostruc bateau, int int_tailleGrille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Mon Dec  9 16:21:57 2019
  \brief permet de remplir une valeur du tableau des bateaux
  \param batostruc bateau : valeur du tableau des bateaux à remplir
  \param int int_tailleGrille : taille de la grille pour s'assurer qu'on ne prenne pas un bateau plus grand que cette dernière
  \return batostruc bateau : entrée du tableau complétée
  \remarks
*/
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
