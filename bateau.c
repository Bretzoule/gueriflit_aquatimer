/*! \file bateau.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Thu Dec 19 11:19:41 2019
 *
 *  \brief initialisation des bateaux
 *
 *
 */

/*!
  \fn int ajoutePorteAvion(int** Grille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 11:23:22 2019
  \brief permet d'ajouter un porte avion sur la grille
  \remarks
*/

int ajoutePorteAvion(int** Grille, int int_tailleBateau) {
  char* coord = malloc(sizeof(char)*2);
  int int_debutBateauX = 0;
  int int_debutBateauY = 0;
  int int_okPosee = 0;
  do {
    printf("Début du bateau : \n");
    demandeCoord(coord);
    int_debutBateauY = atoi(coord[1]);
    int_debutBateauX = atoi(toUpper(coord[0]))-65;
  } while (checkVideAutour(int_debutBateauX,int_debutBateauY) != 0 );
  Grille[int_debutBateauY][int_debutBateauX] = -1;
  do
  {
    printf("Dernière case du bateau");
    demandeCoord(coord);
    int_debutBateauY = atoi(coord[1]);
    int_debutBateauX = atoi(toUpper(coord[0]))-65;
  } while((int_finBateauX >= 0) && (int_finBateauX < N) && (int_finBateauY >= 0) && (int_finBateauY < N) && (((abs(int_debutBateauX-int_finBateauX+1) == int_tailleBateau) && (int_debutBateauY == int_finBateauY)) || ((abs(int_debutBateauY-int_finBateauY+1) == int_tailleBateau) && (int_debutBateauX == int_finBateauX))));
  int int_i;
  for (int_i = int_debutBateauY; int_i < int_finBateauY; int_i++)
  {
    int int_j;
    for (int_j = int_debutBateauX; int_j < int_debutBateauX; int_j++)
    {
      Grille[int_debutBateauY][int_debutBateauX] = BATEAUVIVANT;
    }
  }
  return (int_okPosee);
}

/*!
  \fn int ajoute
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Dec 19 12:31:32 2019
  \brief
  \remarks
*/

int ajouteCroiseur(int** Grille) {

  return ();
}
