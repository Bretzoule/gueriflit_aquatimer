/*!
*  \file jeu.c
*  \author Hugo POINTEREAU <pointereau@eisti.eu>
*  \version 0.1
*  \date 8/01/2020
*
*  \brief avec les fonctions de jeu
*
*/

/* Inclusion des entêtes de librairies */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "affichage.h"
#include "loadFiles.h"
#include "jeu.h"
#include "combat.h"
#include "bateau.h"
#include "ia.h"


int askGrille(void) {
  int int_tailleGrille = 0;
  printf("Quelle est la taille de votre grille (veuillez entrer 10 pour une grille par défaut)\n");
  int_tailleGrille = demandeValeur(int_tailleGrille);
  while ((int_tailleGrille < 7) || (int_tailleGrille > 26)) {
    printf("Vous n'allez pas jouer sur une grille aussi petite quand même (la valeur minimale acceptable est 7) !\n");
    int_tailleGrille = demandeValeur(int_tailleGrille);
  }
  return (int_tailleGrille);
}

int askFlotteCustom(void) {
  int int_modePerso = -1;
  printf("Souhaitez-vous jouer avec une flotte personnalisée ? (1 si oui, 0 si non)\n");
  int_modePerso = demandeValeur(int_modePerso);
  while ((int_modePerso != 0) && (int_modePerso != 1)) {
    printf("J'avais dit 1 ou 0....\n");
    int_modePerso = demandeValeur(int_modePerso);
  }
  return (int_modePerso);
}

void initTabJoueur(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur, int int_nombreBateaux) {
  int int_i;
  int int_okPosee;
  system("clear");
  printf("Initialisation grille pour le joueur %d ! \n",int_joueur);
  for (int_i = 0; int_i < int_nombreBateaux; int_i++)
  {
    afficherGrille(ppint_grille,int_tailleGrille);
    printf("Vous placez un %s, taille = %d \n",flotteUtilisee[int_i].nom, flotteUtilisee[int_i].taille);
     do
     {
       int_okPosee = ajouteBateau(ppint_grille,flotteUtilisee[int_i].taille,int_tailleGrille);
     } while (int_okPosee != 1);
  }
  afficherGrille(ppint_grille,int_tailleGrille);
}

void initTabIA(int** ppint_grille,int int_tailleGrille, batostruc* flotteUtilisee, int int_joueur, int int_nombreBateaux) {
  int int_i;
  int int_okPosee;
  for (int_i = 0; int_i < int_nombreBateaux; int_i++)
  {
     do
     {
       int_okPosee = ajouteBateauIA(ppint_grille,flotteUtilisee[int_i].taille,int_tailleGrille);
     } while (int_okPosee != 1);
  }
  afficherGrille(ppint_grille,int_tailleGrille);
}

void freeGrille(int*** ppint_matrice, int int_tailleGrille) {
  int int_i;
  for (int_i = 0; int_i < int_tailleGrille; int_i++)
  {
    free((*ppint_matrice)[int_i]); // libère la matrice
  }
  free(*ppint_matrice);
}

void testToucheCoule(int int_valeurTouche, int int_tailleFlotte, int int_tailleGrille, batostruc* flotte, int int_joueur) {
  int int_Trouve = 0;
  int int_i = 0;
  if (int_valeurTouche > 0) {
    while ((int_Trouve != 1) && (int_i < int_tailleFlotte)) {
      if ((flotte[int_i].taille == int_valeurTouche) && (flotte[int_i].statut != int_joueur)) {
        int_Trouve = 1;
        flotte[int_i].statut += int_joueur;
        printf("\n");
        printf("                                                  \033[1;31m_.-^^---....,,--_       \033[0m\n");
        printf(" ██████╗  ██████╗  ██████╗ ███╗   ███╗ \033[0;31m██╗\033[0m    \033[0;31m_--                  --_   \033[0m\n");
        printf(" ██╔══██╗██╔═══██╗██╔═══██╗████╗ ████║ \033[0;31m██║\033[0m   \033[1;31m<                        >) \033[0m\n");
        printf(" ██████╔╝██║   ██║██║   ██║██╔████╔██║ \033[0;31m██║\033[0m   \033[0;31m|                         | \033[0m\n");
        printf(" ██╔══██╗██║   ██║██║   ██║██║╚██╔╝██║ \033[0;31m╚═╝\033[0m    \033[0;31m|._                   _./  \033[0m\n");
        printf(" ██████╔╝╚██████╔╝╚██████╔╝██║ ╚═╝ ██║ \033[0;31m██╗\033[0m       \033[1;31m```--. . , ; .--'''     \033[0m\n");
        printf(" ╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝ \033[0;31m╚═╝\033[0m              \033[0;31m| |   |          \033[0m\n");
        printf("                                                     \033[1;31m.-=\033[0;31m||  | |\033[1;31m=-.       \033[0m\n");
        printf("                                                    \033[1;31m `-=#$&@@$#=-'       \033[0m\n");
        printf("                    Ez                                  \033[0;31m| ;  :|          \033[0m\n");
        printf("                                               \033[0;31m_____.,-#&!$@$#@§~,._____ \033[0m\n");
        printf("Félicitations capitaine ! Vous venez de couler le %s ennemi !\n",flotte[int_i].nom);
      }
      int_i++;
    }
  } else {
    if (int_valeurTouche == (-int_tailleGrille-3)) {
      printf("\n");
      printf("███████╗██████╗ ██╗      █████╗ ███████╗██╗  ██╗  \033[1;34m██╗\033[0m  \033[1;36m    , \033[0m\n");
      printf("██╔════╝██╔══██╗██║     ██╔══██╗██╔════╝██║  ██║  \033[1;34m██║\033[0m  \033[1;36m    )\\ \033[0m\n");
      printf("███████╗██████╔╝██║     ███████║███████╗███████║  \033[1;34m██║\033[0m  \033[1;36m   /  \\ \033[0m\n");
      printf("╚════██║██╔═══╝ ██║     ██╔══██║╚════██║██╔══██║  \033[1;34m╚═╝\033[0m  \033[1;36m  '  ~ ' \033[0m\n");
      printf("███████║██║     ███████╗██║  ██║███████║██║  ██║  \033[1;34m██╗\033[0m  \033[1;36m  ',  ,'\033[0m\n");
      printf("╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝  \033[1;34m╚═╝\033[0m   \033[1;36m  `' \033[0m\n");
      printf("On ne vous a pas demandé de canarder les poissons capitaine ! Visez les ennemis un peu ! \n");
    } else {
      printf("\n");
      printf("██╗  ██╗██╗████████╗\033[33m██╗\033[0m          .                     \n");
      printf("██║  ██║██║╚══██╔══╝\033[33m██║\033[0m          _\\____                \n");
      printf("███████║██║   ██║   \033[33m██║\033[0m           |_===__`.        ==/ \n");
      printf("██╔══██║██║   ██║   \033[33m╚═╝\033[0m           /  '---'|_ _ _ _ _/  \n");
      printf("██║  ██║██║   ██║   \033[33m██╗\033[0m    \033[0;31m#~##\033[0m__/_\033[0;31mON FIRE\033[0m_/_|_|_|_|   \n");
      printf("╚═╝  ╚═╝╚═╝   ╚═╝   \033[33m╚═╝\033[0m   \033[0;31m_*-$#~#\033[0m---------------==.'  \n");
      printf("                           \033[0;31m|&@~#~#\033[0m_______________.'    \n");
      printf("Joli tir capitaine ! On dirait qu'on a endommagé quelque chose ! \n");
    }
  }
}

int joueJoueur(int** GrilleAttaque, int** GrilleDefense,int int_nombreBateaux,int int_tailleGrille,batostruc* flotteUtilisee,int int_joueur) {
  int int_condtir = 1;
  afficherEnmie(GrilleAttaque,int_tailleGrille);
  int_condtir = tir(GrilleAttaque,int_tailleGrille);
  afficherGrille(GrilleDefense,int_tailleGrille);
  afficherEnmie(GrilleAttaque,int_tailleGrille);
  testToucheCoule(int_condtir,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
  return (int_condtir);
}


void jeuSplitScreen(int int_loadGame) {
  batostruc* flotteUtilisee = NULL;
  int int_tailleGrille;
  int int_modePerso = 0;
  int** ppint_grille_J1 = NULL;
  int** ppint_grille_J2 = NULL;
  int int_joueur = 1;
  int int_condtir = 1;
  int int_nombreBateaux = 10;
  int int_finJ1 = 1;
  int int_finJ2 = 1;
  int int_leaveSave = 0;
  char filePath[100] = "";
  FILE *fichierSav = NULL;
  if (int_loadGame == 0) {
  int_tailleGrille = askGrille();
  int_modePerso = askFlotteCustom();
  if (int_modePerso == 1) {
    int_nombreBateaux = demandeNombreBateau(int_tailleGrille);
  }
  flotteUtilisee = constructionFlotteHumain(flotteUtilisee,int_tailleGrille,int_modePerso,int_nombreBateaux);
  init(&ppint_grille_J1, int_tailleGrille);
  initTabJoueur(ppint_grille_J1,int_tailleGrille,flotteUtilisee,1,int_nombreBateaux);
  init(&ppint_grille_J2, int_tailleGrille);
  initTabJoueur(ppint_grille_J2,int_tailleGrille,flotteUtilisee,2, int_nombreBateaux);
  system("clear");
  } else {
    askFilePath(filePath);
    fichierSav = openFile(filePath);
    int_tailleGrille = getIntFromSave(fichierSav);
    int_nombreBateaux = getIntFromSave(fichierSav);
    init(&ppint_grille_J1, int_tailleGrille);
    init(&ppint_grille_J2, int_tailleGrille);
    flotteUtilisee = getFlotteFromSave(fichierSav,int_nombreBateaux,flotteUtilisee);
    getTabFromSave(fichierSav,ppint_grille_J1,ppint_grille_J2,int_tailleGrille);
    int_joueur = getIntFromSave(fichierSav);
    fclose(fichierSav);
  }
  while((int_finJ1!=0) && (int_finJ2!=0) && (int_leaveSave != 1)) {
    if (int_joueur == 1) {
      int_condtir = 0;
      while ((int_condtir != (-int_tailleGrille-3)) && (int_finJ2!=0)) {
        printf("Au joueur %d de jouer !\n", int_joueur);
        int_condtir = joueJoueur(ppint_grille_J2,ppint_grille_J1,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
        int_finJ2 = fin(ppint_grille_J2,int_tailleGrille);
        sleep(5);
        system("clear");
      }
    } else {
      int_condtir =0;
      while ((int_condtir != (-int_tailleGrille-3))&& (int_finJ1!=0)) {
        printf("Au joueur %d de jouer !\n", int_joueur);
        int_condtir = joueJoueur(ppint_grille_J1,ppint_grille_J2,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
        int_finJ1 = fin(ppint_grille_J1,int_tailleGrille);
        sleep(5);
        system("clear");
      }
    }
    int_joueur = ((int_joueur)%2)+1;
    if ((int_finJ1!=0) && (int_finJ2!=0)) {
        int_leaveSave = askSave(filePath,ppint_grille_J1,ppint_grille_J2,int_tailleGrille,flotteUtilisee,int_joueur,int_nombreBateaux);

    }
  }
  if (int_leaveSave != 1) {
  if (fin(ppint_grille_J1,int_tailleGrille) == 0) {
    afficheVictoire();
    printf("            LE JOUEUR 2 REMPORTE LA PARTIE           \n");
    supprSave(filePath);
  } else {
    afficheVictoire();
    printf("            LE JOUEUR 1 REMPORTE LA PARTIE           \n");
    supprSave(filePath);
  }
  }
  freeGrille(&ppint_grille_J1,int_tailleGrille);
  freeGrille(&ppint_grille_J2,int_tailleGrille);
  free(flotteUtilisee);
}

/*!
  \fn void afficheVictoire(int int_joueur)
  \author LEFLOCH Thomas <leflochtho@eisti.eu>
  \version 0.1
  \date Tue Jan 21 13:57:22 2020
  \brief permet d'afficher le trophée
  \remarks
*/

void afficheVictoire() {
    printf("\033[1;33m              ___________		\033[0m \n");
    printf("\033[1;33m             '._==_==_=_.'       	\033[0m \n");
    printf("\033[1;33m             .-\\:      /-.      	\033[0m \n");
    printf("\033[1;33m            | (|:.     |) |      	\033[0m \n");
    printf("\033[1;33m             '-|:.     |-'       	\033[0m \n");
    printf("\033[1;33m               \\::.    /        	\033[0m \n");
    printf("\033[1;33m                '::. .'  		\033[0m \n");
    printf("\033[1;33m                  ) (    		\033[0m \n");
    printf("\033[1;33m                _.' '._  		\033[0m \n");
    printf("\033[1;33m               \"\"\"\"\"\"\"`      	\033[0m \n");
}

/*!
\fn void ()
\brief
\author Hugo POINTEREAU <pointereau@eisti.eu>
\version 0.1
\date
*/
void jeuIabateau(int int_loadGame) {
  batostruc* flotteUtilisee = NULL;
  int int_tailleGrille;
  int int_modePerso = 0;
  int** ppint_grille_J1 = NULL;
  int** ppint_grille_IA = NULL;
  int int_joueur = 1;
  int int_condtir = 0;
  int int_nombreBateaux = 10;
  int int_finJ1 = 1;
  int int_finIA = 1;
  int int_leaveSave = 0;
  char filePath[100] = "";
  FILE *fichierSav = NULL;
  if (int_loadGame == 0) {
  int_tailleGrille = askGrille();
  int_modePerso = askFlotteCustom();
  if (int_modePerso == 1) {
    int_nombreBateaux = demandeNombreBateau(int_tailleGrille);
  }
  flotteUtilisee = constructionFlotteHumain(flotteUtilisee,int_tailleGrille,int_modePerso,int_nombreBateaux);
  init(&ppint_grille_J1, int_tailleGrille);
  initTabJoueur(ppint_grille_J1,int_tailleGrille,flotteUtilisee,1,int_nombreBateaux);
  init(&ppint_grille_IA, int_tailleGrille);
  initTabIA(ppint_grille_IA,int_tailleGrille,flotteUtilisee,2, int_nombreBateaux);
  system("clear");
  } else {
    askFilePath(filePath);
    fichierSav = openFile(filePath);
    int_tailleGrille = getIntFromSave(fichierSav);
    int_nombreBateaux = getIntFromSave(fichierSav);
    init(&ppint_grille_IA, int_tailleGrille);
    init(&ppint_grille_J1, int_tailleGrille);
    flotteUtilisee = getFlotteFromSave(fichierSav,int_nombreBateaux,flotteUtilisee);
    getTabFromSave(fichierSav,ppint_grille_J1,ppint_grille_IA,int_tailleGrille);
    int_joueur = getIntFromSave(fichierSav);
    fclose(fichierSav);
  }
  while((int_finJ1!=0) && (int_finIA!=0) && (int_leaveSave != 1)) {
    if (int_joueur == 1) {
      int_condtir = 0;
      while ((int_condtir != (-int_tailleGrille-3)) && (int_finIA!=0)) {
        printf("Au joueur %d de jouer !\n", int_joueur);
        int_condtir = joueJoueur(ppint_grille_IA,ppint_grille_J1,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
        int_finIA = fin(ppint_grille_IA,int_tailleGrille);
        sleep(5);
        system("clear");
      }
    } else {
      int_condtir =0;
      while ((int_condtir != (-int_tailleGrille-3))&& (int_finJ1!=0)) {
        printf("L'IA joue !\n");
        int_condtir = tirIA(ppint_grille_J1,int_tailleGrille);
        testToucheCoule(int_condtir,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
        int_finJ1 = fin(ppint_grille_J1,int_tailleGrille);
      }
    }
    int_joueur = ((int_joueur)%2)+1;
    if ((int_finJ1!=0) && (int_finIA!=0)) {
    int_leaveSave = askSave(filePath,ppint_grille_J1,ppint_grille_IA,int_tailleGrille,flotteUtilisee,int_joueur,int_nombreBateaux);
    }
  }
  if (int_leaveSave != 1) {
  if (fin(ppint_grille_J1,int_tailleGrille) == 0) {
    afficheVictoire();
    printf("            L'IA REMPORTE LA PARTIE           \n");
    supprSave(filePath);
  } else {
    afficheVictoire();
    printf("            LE JOUEUR 1 REMPORTE LA PARTIE           \n");
    supprSave(filePath);
  }
  }
  freeGrille(&ppint_grille_J1,int_tailleGrille);
  freeGrille(&ppint_grille_IA,int_tailleGrille);
  free(flotteUtilisee);
}


void jeuIANRV(int int_loadGame) {
  batostruc* flotteUtilisee = NULL;
  int int_tailleGrille;
  int int_modePerso = 0;
  int int_leaveSave = 0;
  int** ppint_grille_J1 = NULL;
  int** ppint_grille_IA = NULL;
  int int_joueur = 1;
  int int_condtir = 0;
  int mode= 0;
  int int_nombreBateaux = 10;
  int int_finJ1 = 1;
  int int_finIA = 1;
  int int_coord_x;
  int int_coord_y;
  int int_test;
  char filePath[100] = "";
  FILE *fichierSav = NULL;
  if (int_loadGame == 0) {
  int_tailleGrille = askGrille();
  int_modePerso = askFlotteCustom();
  if (int_modePerso == 1) {
    int_nombreBateaux = demandeNombreBateau(int_tailleGrille);
  }
  flotteUtilisee = constructionFlotteHumain(flotteUtilisee,int_tailleGrille,int_modePerso,int_nombreBateaux);
  init(&ppint_grille_J1, int_tailleGrille);
  initTabJoueur(ppint_grille_J1,int_tailleGrille,flotteUtilisee,1,int_nombreBateaux);
  init(&ppint_grille_IA, int_tailleGrille);
  initTabIA(ppint_grille_IA,int_tailleGrille,flotteUtilisee,2, int_nombreBateaux);
  system("clear");
  } else {
    askFilePath(filePath);
    fichierSav = openFile(filePath);
    int_tailleGrille = getIntFromSave(fichierSav);
    int_nombreBateaux = getIntFromSave(fichierSav);
    init(&ppint_grille_IA, int_tailleGrille);
    init(&ppint_grille_J1, int_tailleGrille);
    flotteUtilisee = getFlotteFromSave(fichierSav,int_nombreBateaux,flotteUtilisee);
    getTabFromSave(fichierSav,ppint_grille_J1,ppint_grille_IA,int_tailleGrille);
    int_joueur = getIntFromSave(fichierSav);
    fclose(fichierSav);
  }
  while((int_finJ1!=0) && (int_finIA!=0) && (int_leaveSave != 1)) {
    if (int_joueur == 1) {
      int_condtir = 0;
      while ((int_condtir != (-int_tailleGrille-3)) && (int_finIA!=0)) {
        printf("Au joueur %d de jouer !\n", int_joueur);
        int_condtir = joueJoueur(ppint_grille_IA,ppint_grille_J1,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
        int_finIA = fin(ppint_grille_IA,int_tailleGrille);
        sleep(5);
        system("clear");
      }
    } else {
      int_condtir =0;
      while ((int_condtir != (-int_tailleGrille-3))&& (int_finJ1!=0)) {
        printf("L'IA joue !\n");
        if (mode ==0) {
          do {
            int_coord_y = coordIAY(int_tailleGrille);
            int_coord_x = coordIAX(int_tailleGrille);
            int_test = valitir(ppint_grille_J1,int_coord_x,int_coord_y);
          } while ((((int_coord_x < 0) || (int_coord_x > int_tailleGrille-1))||((int_coord_y < 0) || (int_coord_y > int_tailleGrille-1))) ||(int_test==1));
          int_condtir = tirIASC(ppint_grille_J1,int_tailleGrille,int_coord_x,int_coord_y);
          testToucheCoule(int_condtir,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
          int_finJ1 = fin(ppint_grille_J1,int_tailleGrille);
          if (int_condtir != (-int_tailleGrille-3)) {
            mode = 1;
          }
      }else {
        int_condtir = TirV2(ppint_grille_J1,int_coord_x,int_coord_y,int_tailleGrille);
        int_finJ1 = fin(ppint_grille_J1,int_tailleGrille);
        testToucheCoule(int_condtir,int_nombreBateaux,int_tailleGrille,flotteUtilisee,int_joueur);
        for (int i = 0; i < int_nombreBateaux; i++) {
            if (flotteUtilisee[i].taille == int_condtir) {
              mode =0;
            }
          }
        }
      }
    }
    int_joueur = ((int_joueur)%2)+1;
    if ((int_finJ1!=0) && (int_finIA!=0)) {
    int_leaveSave = askSave(filePath,ppint_grille_J1,ppint_grille_IA,int_tailleGrille,flotteUtilisee,int_joueur,int_nombreBateaux);
    }
}
  if (fin(ppint_grille_J1,int_tailleGrille) == 0) {
    afficheVictoire();
    printf("            L'IA REMPORTE LA PARTIE           \n");
    supprSave(filePath);
  } else {
    afficheVictoire();
    printf("            LE JOUEUR 1 REMPORTE LA PARTIE           \n");
    supprSave(filePath);
  }
  freeGrille(&ppint_grille_J1,int_tailleGrille);
  freeGrille(&ppint_grille_IA,int_tailleGrille);
  free(flotteUtilisee);
}
