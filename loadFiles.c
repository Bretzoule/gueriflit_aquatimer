/*! \file loadFiles.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Thu Jan 16 11:42:12 2020
 *
 *  \brief ensemble des fonctions permettant de charger / enregistrer la partie depuis/vers un fichier
 *
 *
 */

/*!
  \fn void saveGameToFile(int** Grille, int int_tailleGrille, batostruc* flotte, int int_joueur, int int_nbBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu> & DRAESCHER Lucas <draescherl@eisti.eu>
  \version 0.1
  \date Tue Jan 21 14:31:52 2020
  \brief permet de sauvegarder la partie à un état donné, à l'aide du numéro de joueur, la taille de la grille, le nombre de bateaux, la flotte ainsi que la grille
  \param int** Grille : grille de jeu
  \param int int_tailleGrille : taille de la grille en entrée
  \param batostruc* flotte : flotte utilisée
  \param int int_joueur : numéro du joueur
  \param int int_nbBateaux : nombre de bateaux
  \return int int_retour : Retourne 1 si la sauvegarde à été effectuée
  \remarks
*/

int saveGameToFile(int **GrilleJ1, int **GrilleJ2, int int_tailleGrille, batostruc *flotte, int int_joueur, int int_nbBateaux)
{
  int int_retour = 1;
  char *fileName = malloc(sizeof(char) * 50);
  time_t rawtime;
  struct tm *timeinfo;
  char strDate[50];
  FILE *fichierSav = NULL;
  int int_i = 0;
  int int_j = 0;
  int int_k = 0;
  strcpy(fileName, "./saves/GAMESAVE");
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(strDate, 50, "-%D-%R.sav", timeinfo);
  strconcat(fileName, strDate);
  fichierSav = fopen(fileName, "w+");
  if (fichierSav == NULL)
  {
    fprintf(stderr, "Erreur d'ouverture du fichier");
    exit(ERREUR_OUVERTURE);
  }
  fprintf(fichierSav, "%d\n", int_tailleGrille);
  fprintf(fichierSav, "%d\n", int_nbBateaux);
  for (int_k = 0; int_k < int_nbBateaux; int_k++)
  {
    fprintf(fichierSav, "#%s;", flotte[int_k].nom);
    fprintf(fichierSav, "%s;", flotte[int_k].taille);
    fprintf(fichierSav, "%s;", flotte[int_k].statut);
  }
  fprintf(fichierSav, "\n");
  for (int_i = 0; int_i < int_tailleGrille; int_i++)
  {
    for (int_j = 0; int_j < int_tailleGrille; int_j++)
    {
      fprintf(fichierSav, "%d", GrilleJ1[int_i][int_j]);
    }
    fprintf(fichierSav, "\n");
  }
  for (int_i = 0; int_i < int_tailleGrille; int_i++)
  {
    for (int_j = 0; int_j < int_tailleGrille; int_j++)
    {
      fprintf(fichierSav, "%d", GrilleJ2[int_i][int_j]);
    }
    fprintf(fichierSav, "\n");
  }
  fprintf(fichierSav, "%d\n", int_joueur);
  fclose(fichierSav);
  printf("Partie sauvegardée sous : %s - Merci d'avoir joué! \n",fileName)
  return (int_retour);
}

/*!
  \fn int askSave(int** Grille, int int_tailleGrille, batostruc* flotte, int int_joueur, int int_nbBateaux)
  \author LEFLOCH Thomas <leflochtho@eisti.eu> & DRAESCHER Lucas <draescherl@eisti.eu>
  \version 0.1
  \date Tue Jan 21 14:31:52 2020
  \brief permet de sauvegarder la partie à un état donné, à l'aide du numéro de joueur, la taille de la grille, le nombre de bateaux, la flotte ainsi que la grille
  \param int** Grille : grille de jeu
  \param int int_tailleGrille : taille de la grille en entrée
  \param batostruc* flotte : flotte utilisée
  \param int int_joueur : numéro du joueur
  \param int int_nbBateaux : nombre de bateaux
  \return int int_retour : Retourne 1 si la sauvegarde à été effectuée
  \remarks
*/
int askSave(int **GrilleJ1, int **GrilleJ2, int int_tailleGrille, batostruc *flotte, int int_joueur, int int_nbBateaux)
{
  int int_retour = 0;
  do
  {
    printf("Souhaitez vous sauvegarder la partie ou continuer ? \n 1 : Sauvegarder || 0 : Continuer ! \n");
    int_valueAsk = demandeValeur(int_valueAsk);
  } while ((int_valueAsk != 0) || (int_valueAsk != 1));
  if (int_valueAsk == 1)
  {
    int_retour = saveGameToFile(int **GrilleJ1, int **GrilleJ2, int int_tailleGrille, batostruc *flotte, int int_joueur, int int_nbBateaux);
  }
  return int_retour;
}