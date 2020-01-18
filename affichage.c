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


void init(int*** ppint_grille, int int_tailleGrille)
{
  *ppint_grille =calloc(int_tailleGrille,sizeof(int*));
  for (int i = 0; i < int_tailleGrille; i++) //allocation de l'espace pour la matrice
  {
    (*ppint_grille)[i] = calloc(int_tailleGrille,sizeof(int*));
  }
}

void afficherGrille(int** ppint_grille,int int_tailleGrille)
{
  printf("GRILLE DE VOS BATEAUX\n");
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
      if (ppint_grille[i][j]==BATEAU_VIVANT) {
        printf("| ■ ");
      }
      else
      {
        if (ppint_grille[i][j]==BATEAU_TOUCHE) {
          printf("| \033[31m■\033[0m ");
        }
        else
        {
          if (ppint_grille[i][j]==EAU_MORTE) {
            printf("| \033[96m▒\033[0m ");
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

void afficherEnmie(int** ppint_grille,int int_tailleGrille){
  printf("GRILLE DE VOS TIRS\n");
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
      if (ppint_grille[i][j]==BATEAU_VIVANT) {
        printf("| \033[34m▒\033[0m ");
      }
      else
      {
        if (ppint_grille[i][j]==BATEAU_TOUCHE) {
          printf("| \033[31m■\033[0m ");
        }
        else
        {
          if (ppint_grille[i][j]==EAU_MORTE) {
            printf("| \033[96m▒\033[0m ");
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
