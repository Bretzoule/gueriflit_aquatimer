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


/*!
\fn void init()
\brief initialise la matrice
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 9/12/19
*/
void init(int*** ppint_grille, int int_tailleGrille)
{
  *ppint_grille =calloc(int_tailleGrille,sizeof(int*));
  for (int i = 0; i < int_tailleGrille; i++) //allocation de l'espace pour la matrice
  {
    (*ppint_grille)[i] = calloc(int_tailleGrille,sizeof(int*));
  }
}

/*!
\fn void afficherGrille(int** ppint_grille)
\brief  affiche la grille du jeu
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date 9/12/19
*/
void afficherGrille(int** ppint_grille,int int_tailleGrille)
{
  printf("   ");
  for (int k = 1; k < int_tailleGrille+1; k++) {
      printf("  %d ",k );
  }
  printf("\n");
  for (int i = 0; i < int_tailleGrille; i++)
  {
    printf("   ");
    for (int k = 0; k < int_tailleGrille; k++)
    {
      printf("+---" ); // pour faire une belle matrice sur le terminal
    }
    printf("+\n");
    printf(" %c ",i+65 );
    for (int j = 0; j < int_tailleGrille; j++)
    {
      if (ppint_grille[i][j]==1) {
        printf("| ■ ");
      }
      else
      {
        if (ppint_grille[i][j]==2) {
          printf("| \033[31m■\033[0m ");
        }
        else
        {
          if (ppint_grille[i][j]==-1) {
            printf("| \033[36m▒\033[0m ");
          }
          else
          {
            printf("| \033[34m▒\033[0m ");

          }
        }
      }
    }
    printf("|\n");
  }
  printf("   ");
  for (int k = 0; k < int_tailleGrille; k++)
  {
    printf("+---" );
  }
  printf("+\n");
}
