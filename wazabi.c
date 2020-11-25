#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

///////////////////////////////////////
//////// Déclaration des types ////////
///////////////////////////////////////

typedef struct carte carte;
struct carte
{
    int index;
    int cout;
    char titre[255];
    char effet[255];
    carte *suivant;
    carte *precedent;
};

typedef struct joueur joueur;
struct joueur
{
    char pseudo[25];
    int des[24];
    carte cartes;
    joueur *suivant;
    joueur *precedent;
};

typedef struct de de;
struct de
{
    int faces[6];
};

//////////////////////////////////////////////////////
//////// Déclaration des méthodes / fonctions ////////
//////////////////////////////////////////////////////
// Méthodes
void initDe(de *de);
void initPartie(joueur *joueurs);
void afficherDe(int face);
void selectionCarte(joueur *joueur);
void utilisationCarte(carte *carte, joueur *joueur);
// FOR TEST
void test();

// Effets de cartes
void supprimerDe(char *deJoueur[]);

// Fonctions
int lancerDe(de de);

int main(int argc, char *argv[])
{
    // Initialisation de srand
    srand(time(NULL));

    // Création de la liste de joueur
    joueur listeJoueur;

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
    de de;
    joueur joueurCourant;

    // Début
    // initialisation de l'objet dé
    initDe(&de);

    // lancer dé
    lancerDe(de);

    // Sélection carte
    selectionCarte(&joueurCourant);
    // Fin
}

///////////////////////////////////////
//////// Initialisation Partie ////////
///////////////////////////////////////

// To initialize the dice tab
void initDe(de *de)
{
    (*de).faces[0] = 1;
    (*de).faces[1] = 1;
    (*de).faces[2] = 1;
    (*de).faces[3] = 2;
    (*de).faces[4] = 2;
    (*de).faces[5] = 3;
}

/////////////////////////////////
//////// Gestion des dés ////////
/////////////////////////////////


////////////////////////////////////
//////// Gestion des cartes ////////
////////////////////////////////////
