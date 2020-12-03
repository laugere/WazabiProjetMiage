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

    // Lancement des tours
    tour();

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

void tour()
{
    // Lexique
    listeJoueurs listeJoueur;
    dice de;
    pileCartes pioche;
    bool fin;

    joueur *ptrJoueur;
    int nbWJoueur;

    // Début
    listeJoueur.debut = NULL;

    // Initialisation de la partie
    initPioche(&pioche);
    initPartie(&listeJoueur, &pioche);
    fin = false;
    initDe(&de);
    ptrJoueur = listeJoueur.debut;
    do
    {
        // Lancement des dés
        printf("--------------------\n");
        lancerDe(de, ptrJoueur->des);
        printf("--------------------\n");
        nbWJoueur = retourneSommeWazabi(ptrJoueur->des);
        printf("Vous avez %d Wazabi\n", nbWJoueur);
        selectionCarte(ptrJoueur, &pioche);
        fin=verifFin(ptrJoueur);
        ptrJoueur = ptrJoueur->suivant;
    } while (!fin);
    // Fin
}
