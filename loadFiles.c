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

void supprSave(char* filePath) {
  char command[53] = "rm ";
  if (strlen(filePath) != 0)
  {
    strcat(command,filePath); // permet de supprimer le fichier de save
    system(command);
  }
}

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
  strftime(strDate, DATE_LENGTH,"%d_%m_%Y-%H:%M:%S.sav",timeinfo);
  if (fileName == NULL) {
    fprintf(stderr, "Erreur de reallocation : %d \n",errno); // verification entrée
      exit(ERREUR_ALLOC);
  }
  strcat(fileName,strDate);
  fichierSav = fopen(fileName,"w+"); // ouverture fichier
  if (fichierSav == NULL)
  {
    printf("Création du fichier !\n");
    fichierSav = fopen(fileName,"w+"); // creation fichier
    if (fichierSav == NULL) {
      printf("Erreur d'ouverture \n");
      exit(ERREUR_OUVERTURE);
    }
  }
  printf("Sauvegarde en cours ! \n");
  fprintf(fichierSav, "%d\n", int_tailleGrille); // écriture taille de la grille
  fprintf(fichierSav, "%d\n", int_nbBateaux); // écriture taille flotte
  for (int_k = 0; int_k < int_nbBateaux; int_k++)
  {
    fprintf(fichierSav, "#%s;", flotte[int_k].nom); // nom bateau
    fprintf(fichierSav, "%d;", flotte[int_k].taille); // taille bateau
    fprintf(fichierSav, "%d;", flotte[int_k].statut); // statut bateau
  }
  fprintf(fichierSav, "%s", "\n");
  for (int_i = 0; int_i < int_tailleGrille; int_i++)
  {
    for (int_j = 0; int_j < int_tailleGrille; int_j++)
    {
      fprintf(fichierSav, "%d", GrilleJ1[int_i][int_j]+1); // ajoute la coordonnée de la grille +1 (pour ne pas store des -1 et avoir 2 chars)
    }
    fprintf(fichierSav, "%s", "\n");
  }
  for (int_i = 0; int_i < int_tailleGrille; int_i++)
  {
    for (int_j = 0; int_j < int_tailleGrille; int_j++)
    {
      fprintf(fichierSav, "%d", GrilleJ2[int_i][int_j]+1); // ajoute la coordonnée de la grille +1 (pour ne pas store des -1 et avoir 2 chars)
    }
    fprintf(fichierSav, "%s", "\n");
  }
  fprintf(fichierSav, "%d\n", int_joueur);
  fclose(fichierSav); // ferme le fichier
  printf("Partie sauvegardée sous : %s - Merci d'avoir joué! \n",fileName);
  return (int_retour);
  free(fileName);
}

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

int validationFichier(char* filePath) {
  int int_i;
  int int_retour = 1;
  char* str_tmp = malloc(sizeof(char)*4);
  strcpy(str_tmp,".sav");
  for (int_i = 0; int_i < 4; int_i++)
  {
    if (str_tmp[int_i] != filePath[((strlen(filePath)-4)+int_i)]) { // vérifie que l'extension est la bonne

        int_retour = 0;
    }
  }
  if (int_retour == 0) {
    printf("Fichier invalide ! \n");
  } else {
    printf("Fichier valide, ouverture ! \n");
  }
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
  return (flotteUtilisee);
}

void getTabFromSave(FILE* fichierSav,int** GrilleJ1, int** GrilleJ2, int int_tailleGrille) {
  char buf[bufSize];
  int int_i = 0;
  int int_k = 0;
  char strtmp[2];
  strtmp[0] = '\0';
  while (int_i < int_tailleGrille) {
    if(fgets(buf, sizeof(buf), fichierSav) != NULL)
    {
      buf[strlen(buf) - 1] = '\0'; // récupère le \0 que fgets stocke
      printf("buf : %s\n", buf);
      for (int_k = 0; int_k < int_tailleGrille; int_k++)
      {
        sprintf(strtmp,"%c",buf[int_k]); // convertit l'élement de la string dans un string séparé
        GrilleJ1[int_i][int_k] = atoi(strtmp)-1;  // converti la stirng en int
      }
      int_i++;
    }
  }
  int_i = 0;
  while (int_i < int_tailleGrille) {
    if(fgets(buf, sizeof(buf), fichierSav) != NULL)
    {
      buf[strlen(buf) - 1] = '\0'; // récupère le \0 que fgets stocke
      printf("buf : %s\n", buf);
      for (int_k = 0; int_k < int_tailleGrille; int_k++)
      {
        sprintf(strtmp,"%c",buf[int_k]); // convertit l'élement de la string dans un string séparé
        GrilleJ2[int_i][int_k] = atoi(strtmp)-1; // converti la stirng en int
      }
      int_i++;
    }
  }
  printf("Chargement des grilles terminée !\n");
}
