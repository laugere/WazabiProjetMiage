#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "header.c"
#include "romeo.c"
#include "martin.c"
#include "raphael.c"

int main(int argc, char *argv[])
{
    // Initialisation de srand
    srand(time(NULL));

    // Création de la liste de joueur
    listeJoueurs listeJoueur;

    listeJoueur.debut = NULL;

    // Initialisation de la partie
    initPartie(&listeJoueur);

    // Lancement des tours
    tour(&listeJoueur);

    return 0;
}

// To initialize the dice tab
void initDe(dice *de)
{
    (*de).faces[0] = 1;
    (*de).faces[1] = 1;
    (*de).faces[2] = 1;
    (*de).faces[3] = 2;
    (*de).faces[4] = 2;
    (*de).faces[5] = 3;
}

void tour(listeJoueurs *listeJoueur) {
    // Lexique
    dice de;
    pileCartes pioche;
    pileCartes defausse;
    bool fin;

    // Début
    initDe(&de);
    fin = false;
    do {

    } while (!fin);
    // Fin
}
