#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Déclaration des types
typedef struct joueur joueur;
struct joueur
{
    char pseudo[25];
    int de[24];
    joueur *suivant;
};

typedef struct carte carte;
struct carte
{
    int index;
    int cout;
    char effet[255];
    carte *suivant;
};

typedef struct de de;
struct de
{
    int faces[6];
};

// Déclaration des méthodes / fonctions

int main(int argc, char *argv[])
{
    // Initialisation de srand
    srand(time(NULL));

    // Création de la liste de joueur
    joueur listeJoueur;

    // Création objet dé
    de de;
    de.faces = {1, 1, 1, 2, 2, 3};

    // Initialisation de la partie
    initPartie(&listeJoueur);

    // lancer dé
    lancerDes(de);

    return 0;
}