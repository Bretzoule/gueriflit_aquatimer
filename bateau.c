/*! \file bateau.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Thu Dec 19 11:19:41 2019
 *
 *  \brief initialisation des bateaux
 *
 *
 */

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

/*!
  \fn int checkVideAutour(int** Grille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet d'ajouter un porte avion sur la grille
  \return somme des valeurs des cases autour de la position
  \param int** Grille : grille en entrée
  \param int int_PosX : Position X
  \param int int_PosY : Position Y
  \param int int_tailleGrille : taille de la grille (en x ou en y car grille carrée)
  \remarks permet de récupérer les valeurs des cases voisines
*/
int checkVideAutour(int **Grille, int int_PosX, int int_PosY, int int_tailleGrille)
{
  int int_res = 0;
  if ((int_PosX == 0) && (int_PosY == 0))
  {
    int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
  }
  else
  {
    if ((int_PosX == 0) && (int_PosY == int_tailleGrille))
    {
      int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
    }
    else
    {
      if ((int_PosX == int_tailleGrille) && (int_PosY == 0))
      {
        int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
      }
      else
      {
        if ((int_PosX == int_tailleGrille) && (int_PosY == int_tailleGrille))
        {
          int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
        }
      else
      {
        if (int_PosY == 0)
        {
          int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
        }
        if (int_PosX == 0)
        {
          int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinSudEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
        }
        if (int_PosX == int_tailleGrille)
        {
          int_res = (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordEst(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
        }
        if (int_PosY == int_tailleGrille)
        {
          int_res = (voisinSud(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinNord(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + (voisinSudOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille) + voisinNordOuest(tint_jeu, int_x, int_y, int_tailleGrille, int_tailleGrille));
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

/*! // à déplacer d'ici !
  \fn demandeCoord(char** coord)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet de récupérer des coordonées
  \remarks
*/
void demandeCoord(char **coord)
{
  printf("Entrez vos coordonnées de la forme \"A9\"\n");
  fflush(stdin);
  int_retour = scanf(% s, &coord);
  if (int_retour == 0)
  {
    fprintf("Erreur de coordonnées", stderr);
    exit(ERREUR_SAISIE);
  }
}

/*!
  \fn int ajouteBateau(int** Grille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet d'ajouter un bateau sur la grille
  \return int_okPosee : retourne 1 si tout s'est bien déroulé et que le bateau est bien posé, retourne 0 si une erreur s'est produite
  \param int** Grille : grille en entrée
  \param int int_tailleBateau : taille du bateau à poser
  \param int int_tailleGrille : taille de la grille
  \remarks cette fonction doit s'éxécuter tant que le bateau n'est pas correctement positionné sur la grille, ainsi, tant que int_okPosee != 1, la fonction doit se réexécuter avec le code "Erreur de placement"
*/
int ajouteBateau(int **Grille, int int_tailleBateau, int int_tailleGrille)
{
  char *coord = malloc(sizeof(char) * 2);
  int int_debutBateauX = 0;
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
    int_debutBateauY = atoi(coord[1]);
    int_debutBateauX = atoi(toUpper(coord[0])) - 65;
  } while (((int_debutBateauX >= 0) && (int_debutBateauX < int_tailleGrille) && (int_debutBateauY >= 0) && (int_debutBateauY < int_tailleGrille)) && (checkVideAutour(Grille, int_debutBateauX, int_debutBateauY, int_tailleGrille) != 0)); /* On redemande les coordonnées tant que l'emplacement n'est pas valide */
  int_i = int_debutBateauY;
  int_j = int_debutBateauX;
  do
  {
    printf("Dernière case du bateau");
    demandeCoord(coord);
    int_finBateauY = atoi(coord[1]);
    int_finBateauX = atoi(toUpper(coord[0])) - 65;
  } while ((int_finBateauX >= 0) && (int_finBateauX < int_tailleGrille) && (int_finBateauY >= 0) && (int_finBateauY < int_tailleGrille) && (((abs(int_debutBateauX - int_finBateauX + 1) == int_tailleBateau) && (int_debutBateauY == int_finBateauY)) || ((abs(int_debutBateauY - int_finBateauY + 1) == int_tailleBateau) && (int_debutBateauX == int_finBateauX))) && (checkVideAutour(Grille, int_finBateauY, int_finBateauX, int_tailleGrille) != 0));
  while ((int_i <= int_finBateauY) && (int_placementValide == 1))
  {
    while ((int_j <= int_finBateauX) && (int_placementValide == 1))
    {
      if (checkVideAutour(Grille, int_i, int_j) != 0)
        ; /* vérification placement valide */
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
          Grille[int_i][int_j] = BATEAUVIVANT;
        }
      }
    }
  }
  else
  {
    printf("Erreur de placement !");
    int_okPosee = 0;
  }
  return (int_okPosee); // répéter cette fonction tant que le placement n'est pas valide
}