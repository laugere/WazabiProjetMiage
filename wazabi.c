#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

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
void initDe(de *de);
void initPartie(joueur *joueurs);
void lancerDes(de de);

int main(int argc, char *argv[])
{
    // Initialisation de srand
    srand(time(NULL));

    // Création de la liste de joueur
    joueur listeJoueur;

    // Création objet dé
    de de;
    initDe(&de);

    // Initialisation de la partie
    initPartie(&listeJoueur);

    // lancer dé
    lancerDes(de);

    return 0;
}

void initDe(de *de) {
    (*de).faces[0] = 1;
    (*de).faces[1] = 1;
    (*de).faces[2] = 1;
    (*de).faces[3] = 2;
    (*de).faces[4] = 2;
    (*de).faces[5] = 3;
}

void initPartie(joueur *joueurs)
{
    int nb;

    printf("Combien d'adversaires souhaitez-vous ?");
    scanf("%d", &nb);
    do
    {

    } while (nb < 2 && nb > 8);

    for (int i = 0; i < nb; i++)
    {
        joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));
    }
}