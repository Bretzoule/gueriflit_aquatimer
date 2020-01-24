/*! \file loadFiles.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Thu Jan 16 11:42:12 2020
 *
 *  \brief ensemble des fonctions permettant de charger / enregistrer la partie depuis/vers un fichier
 *
 *
 */
#include "loadFiles.h"
#include <errno.h>
#define bufSize 1024
#define DATE_LENGTH 80

int saveGameToFile(int **GrilleJ1, int **GrilleJ2, int int_tailleGrille, batostruc *flotte, int int_joueur, int int_nbBateaux)
{
  int int_retour = 1;
  char* fileName = malloc(sizeof(char)*100);
  FILE *fichierSav = NULL;
  int int_i = 0;
  int int_j = 0;
  int int_k = 0;
  time_t rawtime;
  struct tm *timeinfo;
  char strDate[DATE_LENGTH];
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strcpy(fileName,"./saves/GAMESAVE-");
  strftime(strDate, DATE_LENGTH,"%d\\%m\\%Y-%H:%M:%S.sav",timeinfo);
  if (fileName == NULL) {
    fprintf(stderr, "Erreur de reallocation : %d \n",errno); // verification entrée
      exit(ERREUR_ALLOC);
  }
  strcat(fileName,strDate);
  fichierSav = fopen(fileName,"w+");
  if (fichierSav == NULL)
  {
    printf("Création du fichier !\n");
    fichierSav = fopen(fileName,"w+");
    if (fichierSav == NULL) {
      printf("Erreur d'ouverture \n");
      exit(ERREUR_OUVERTURE);
    }
  }
  printf("Sauvegarde en cours ! \n");
  fprintf(fichierSav, "%d\n", int_tailleGrille);
  fprintf(fichierSav, "%d\n", int_nbBateaux);
  for (int_k = 0; int_k < int_nbBateaux; int_k++)
  {
    fprintf(fichierSav, "#%s;", flotte[int_k].nom);
    fprintf(fichierSav, "%d;", flotte[int_k].taille);
    fprintf(fichierSav, "%d;", flotte[int_k].statut);
  }
  fprintf(fichierSav, "%s", "\n");
  for (int_i = 0; int_i < int_tailleGrille; int_i++)
  {
    for (int_j = 0; int_j < int_tailleGrille; int_j++)
    {
      fprintf(fichierSav, "%d", GrilleJ1[int_i][int_j]+1);
    }
    fprintf(fichierSav, "%s", "\n");
  }
  for (int_i = 0; int_i < int_tailleGrille; int_i++)
  {
    for (int_j = 0; int_j < int_tailleGrille; int_j++)
    {
      fprintf(fichierSav, "%d", GrilleJ2[int_i][int_j]+1);
    }
    fprintf(fichierSav, "%s", "\n");
  }
  fprintf(fichierSav, "%d\n", int_joueur);
  fclose(fichierSav);
  printf("Partie sauvegardée sous : %s - Merci d'avoir joué! \n",fileName);
  return (int_retour);
  free(fileName);
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
int askSave(char* filePath, int **GrilleJ1, int **GrilleJ2, int int_tailleGrille, batostruc *flotte, int int_joueur, int int_nbBateaux)
{
  int int_valueAsk = 0;
  int int_retour = 0;
  char command[53] = "rm ";
  do
  {
    printf("Souhaitez vous sauvegarder la partie ou continuer ? \n 1 : Sauvegarder || 0 : Continuer ! \n");
    int_valueAsk = demandeValeur(int_valueAsk);
  } while ((int_valueAsk != 0) && (int_valueAsk != 1));
  if (int_valueAsk == 1)
  {
    if (strlen(filePath) != 0)
    {
      printf("Une sauvegarde existe déjà, vous allez la remplacer.");
      strcat(command,filePath);
      system(command);
      }
      int_retour = saveGameToFile(GrilleJ1, GrilleJ2, int_tailleGrille, flotte, int_joueur, int_nbBateaux);
    }
  return int_retour;
}

/*!
  \fn validationFichier(char* filePath[50])
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Thu Jan 23 13:46:07 2020
  \brief permet de vérifier que le fichier possède bien l'extension .sav (qu'il est valide)
  \param char* filePath[50] : chemin d'accès au fichier
  \remarks
*/

int validationFichier(char* filePath) {
  int int_i;
  int int_retour = 1;
  char* str_tmp = malloc(sizeof(char)*4);
  strcpy(str_tmp,".sav");
  printf("%s strtmp lol \n", str_tmp);
  for (int_i = 0; int_i < 4; int_i++)
  {
    if (str_tmp[int_i] != filePath[((strlen(filePath)-4)+int_i)]) { // vérifie que l'extension est la bonne
        printf("Fichier invalide ! \n");
        int_retour = 0;
    }
  }
  printf("Fichier valide, ouverture ! \n");
  return (int_retour);
}

void askFilePath(char* filePath) {
  do
  {
    printf("Merci de préciser le chemin d'accès à votre fichier. \n");
    system("ls -l saves/"); // affiches les fichiers dans le dossier
    printf(" il doit être de la forme \"./saves/GAMESAVE-XXXXX.sav\" ! \n");
    fflush(stdin);
    scanf("%s", filePath);
    fflush(stdin);
  } while (validationFichier(filePath) != 1);
}

FILE* openFile(char* filePath) {
  FILE *fichierSav = NULL;
  fichierSav = fopen(filePath, "r");
  if (fichierSav == NULL)
  {
    fprintf(stderr, "Erreur d'ouverture du fichier");
    exit(ERREUR_OUVERTURE);
  } else {
    printf("Opened successfully !\n");
  }
  return (fichierSav);
}


int getIntFromSave(FILE* fichierSav) {
  int int_retour =0;
  char buf[bufSize];
  if(fgets(buf, sizeof(buf), fichierSav) != NULL)
  {
    buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
  }
  int_retour = atoi(buf);
  return (int_retour);
}

batostruc* getFlotteFromSave(FILE* fichierSav, int int_nombreBateaux, batostruc* flotteUtilisee) {
  char buf[bufSize];
  int int_dieseCounter = 0;
  int int_i =0;
  char strtmp[2];
  char strtmptmp[2];
  flotteUtilisee = malloc(sizeof(batostruc)*int_nombreBateaux);
  fseek(fichierSav,5,SEEK_SET);
  if(fgets(buf, sizeof(buf), fichierSav) != NULL)
  {
    buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
    printf("buf : %s\n", buf);
    while (int_dieseCounter != int_nombreBateaux) {
      while(int_i < strlen(buf))
      {
        if (buf[int_i] == '#') {
          int_dieseCounter++;
          int_i++;
          while(buf[int_i] != ';') {
            sprintf(strtmp,"%c",buf[int_i]); // on stocke chaque char converti depuis un int dans une string
            strncat(flotteUtilisee[int_dieseCounter-1].nom,strtmp,1); // on concatène ce char avec le  reste de la string
            int_i++;
            strtmp[0] = '\0';
          }
          int_i++;
          while (buf[int_i] != ';') {
            sprintf(strtmp,"%c",buf[int_i]);  // on converti l'int en char et on le stocke dans une string
            strcat(strtmptmp,strtmp); // on concatène cette string avec une autre contenant le chiffre complet
            int_i++;
            strtmp[0] = '\0';
          }
          flotteUtilisee[int_dieseCounter-1].taille = atoi(strtmptmp); // on converti ensuite le chiffre complet et on le copie dans l'emplacement adéquat
          strtmptmp[0] = '\0';
          int_i++;
          while (buf[int_i] != ';') {
            sprintf(strtmp,"%c",buf[int_i]); // pareil qu'au dessus
            strcat(strtmptmp,strtmp);
            int_i++;
            strtmp[0] = '\0';
            }
          flotteUtilisee[int_dieseCounter-1].statut = atoi(strtmptmp);
          strtmptmp[0] = '\0';
          int_i++;
        }
      }
    }
  }
  //printf("flotte : %s : %d : %d \n",flotteUtilisee[int_dieseCounter-1].nom,flotteUtilisee[int_dieseCounter-1].taille,flotteUtilisee[int_dieseCounter-1].statut);
  return (flotteUtilisee);
}

/*!
  \fn void getTabFromSave(int** GrilleJ1, int** GrilleJ2, int int_tailleGrille)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Fri Jan 24 14:46:42 2020
  \brief permet de récupérer la grille depuis la sauvegarde
  \param int** GrilleJ1 : grille du joueur 1
  \param int** GrilleJ2 : grille de joueur 2 (ou de l'IA)
  \param int int_tailleGrille : taille de la grille en entrée
  \remarks
*/
void getTabFromSave(FILE* fichierSav,int** GrilleJ1, int** GrilleJ2, int int_tailleGrille) {
  char buf[bufSize];
  int int_i = 0;
  int int_k = 0;
  char strtmp[2];
  strtmp[0] = '\0';
  while (int_i < int_tailleGrille) {
    if(fgets(buf, sizeof(buf), fichierSav) != NULL)
    {
      buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
      printf("buf : %s\n", buf);
      for (int_k = 0; int_k < int_tailleGrille; int_k++)
      {
        sprintf(strtmp,"%c",buf[int_k]);
        printf("%s \n",strtmp);
        GrilleJ1[int_i][int_k] = atoi(strtmp)-1;
      }
      int_i++;
    }
  }
  int_i = 0;
  while (int_i < int_tailleGrille) {
    if(fgets(buf, sizeof(buf), fichierSav) != NULL)
    {
      buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
      printf("buf : %s\n", buf);
      for (int_k = 0; int_k < int_tailleGrille; int_k++)
      {
        sprintf(strtmp,"%c",buf[int_k]);
        printf("%s \n", strtmp);
        GrilleJ2[int_i][int_k] = atoi(strtmp)-1;
      }
      int_i++;
    }
  }
  printf("Chargement des grilles terminée !\n");
}
