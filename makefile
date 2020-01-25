CC=gcc
CFLAGS = -Wall
EEFLAGS = -lm
EXEC=gueriflit

all: $(EXEC)

gueriflit: menu.o loadFiles.o affichage.o combat.o ia.o bateau.o jeu.o main.o
	$(CC) -o gueriflit menu.o loadFiles.o affichage.o combat.o ia.o bateau.o jeu.o main.o $(EEFLAGS) && mkdir saves && echo "Compilation terminée !" && cat README.md

main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

jeu.o: jeu.c jeu.h
	$(CC) -o jeu.o -c jeu.c $(CFLAGS)

bateau.o: bateau.c bateau.h
	$(CC) -o bateau.o -c bateau.c $(CFLAGS)

ia.o: ia.c ia.h
	$(CC) -o ia.o -c ia.c $(CFLAGS)

combat.o: combat.c combat.h
	$(CC) -o combat.o -c combat.c $(CFLAGS)

affichage.o: affichage.c affichage.h
	$(CC) -o affichage.o -c affichage.c $(CFLAGS)

loadFiles.o: loadFiles.c loadFiles.h
	$(CC) -o loadFiles.o -c loadFiles.c $(CFLAGS)

menu.o: menu.c menu.h
	$(CC) -o menu.o -c menu.c $(CFLAGS)

clean:
	rm -f *.o core
mrproper:clean
	rm -f $(EXEC)

doxy:
	doxygen -g DoxyFile && doxygen DoxyFile
