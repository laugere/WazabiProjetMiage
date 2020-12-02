#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.c"
#include "romeo.c"
#include "martin.c"

int main(int argc, char *argv[])
{
    // Initialisation de srand
    srand(time(NULL));

    // Création de la liste de joueur
    listeJoueurs listeJoueur;
    pileCartes pioche;
    pileCartes defausse;

    // Initialisation de la partie
    //initPartie(&listeJoueur);

    //////////////////////
    //////// TEST ////////
    //////////////////////
    // Méthode de test
    test();

    return 0;
}

/////////////////////////////////
//////// Méthode de test ////////
/////////////////////////////////

void test()
{
    // Lexique
    dice de;
    joueur joueurCourant;

    // Début
    // initialisation de l'objet dé
    initDe(&de);
    // Fin
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
