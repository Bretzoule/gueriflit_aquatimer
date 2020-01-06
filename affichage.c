/*!
*  \file affichage.c
*  \author Hugo POINTEREAU <pointereau@eisti.eu>
*  \version 0.1
*  \date 19/12/19
*
*  \brief affichage pour le jeu de la batailla navale ainsi que l'initilisation
*
*/

/* Inclusion des entêtes de librairies */
#include "affichage.h"

void demandeCoord(char *coord)
{
  int int_retour = 0;
  printf("Entrez vos coordonnées de la forme \"A9\"\n");
  fflush(stdin);
  int_retour = scanf("%s", coord);
  if (int_retour == 0)
  {
fprintf(stderr,"Erreur de coordonnées");
    exit(ERREUR_SAISIE);
  }
}

/*!
\fn void init()
\brief initialise la matrice
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 9/12/19
*/
void init(int*** ppint_grille)
{
  *ppint_grille =calloc(N,sizeof(int*));
  for (int i = 0; i < N; i++) //allocation de l'espace pour la matrice
  {
    (*ppint_grille)[i] = calloc(N,sizeof(int*));
  }
}

/*!
\fn void afficherGrille(int** ppint_grille)
\brief  affiche la grille du jeu
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 9/12/19
*/
void afficherGrille(int** ppint_grille)
{
  printf("   ");
  for (int k = 1; k < N+1; k++) {
      printf("  %d ",k );
  }
  printf("\n");
  for (int i = 0; i < N; i++)
  {
    printf("   ");
    for (int k = 0; k < N; k++)
    {
      printf("+---" ); // pour faire une belle matrice sur le terminal
    }
    printf("+\n");
printf(" %c ",i+65 );
    for (size_t j = 0; j < N; j++)
    {
      printf("| %d ",ppint_grille[i][j]);
    }
    printf("|\n");

  }
  printf("   ");
  for (int k = 0; k < N; k++)
  {
    printf("+---" );
  }
  printf("+\n");
}
