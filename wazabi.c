#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    srand(time(NULL));


    return 0;
}