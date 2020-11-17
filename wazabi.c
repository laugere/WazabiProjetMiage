#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Déclaration des types
typedef struct joueur joueur;
struct joueur
{
    char pseudo[25];
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
    char faces[6];
};

// Déclaration des méthodes / fonctions

int main()
{
    srand(time(NULL));

    initPartie();

    return 0;
}