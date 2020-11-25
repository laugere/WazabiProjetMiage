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
    char *titre;
    char *effet;
    carte *suivant;
    carte *precedent;
};

typedef struct listeCartes listeCartes;
struct listeCartes
{
    carte *premier;
    carte *dernier;
    carte *courante;
};

typedef struct pileCartes pileCartes;
struct pileCartes
{
    carte *premier;
};

typedef struct joueur joueur;
struct joueur
{
    char pseudo[25];
    int des[24];
    listeCartes listecartes;
    joueur *suivant;
    joueur *precedent;
};

typedef struct listeJoueurs listeJoueurs;
struct listeJoueurs
{
    joueur *debut;
};

typedef struct dice dice;
struct dice
{
    int faces[6];
};

//////////////////////////////////////////////////////
//////// Déclaration des méthodes / fonctions ////////
//////////////////////////////////////////////////////
// Méthodes
void initDe(dice *de);
void initPartie(listeJoueurs *listeJoueur);
void initPioche(pileCartes *pioche);
void afficherDe(int face);
void selectionCarte(joueur *joueur, pileCartes *pioche);
void utilisationCarte(carte *carte, joueur *joueur, pileCartes *pioche);
void empileCarte(pileCartes *pioche, int cout, int index, char effet[], char titre[]);
void ajouterJoueur(listeJoueurs *listeJoueurs);
// FOR TEST
void test();

// Effets de cartes
// Suppression de dés
void supprimerDe(int *deJoueur[]);
void supprimer1De(int *deJoueur[]);
void supprimer2De(int *deJoueur[]);

// Fonctions
int lancerDe(dice de);
int retourneSommeWazabi(int face, int pointwazabi);

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
    //ajouterJoueur(&listeJoueur);
    initPioche(&pioche);
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

    // lancer dé
    //lancerDe(de);

    // Sélection carte
    //selectionCarte(&joueurCourant);
    // Fin
}

///////////////////////////////////////
//////// Initialisation Partie ////////
///////////////////////////////////////

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

/////////////////////////////////
//////// Gestion des dés ////////
/////////////////////////////////

////////////////////////////////////
//////// Gestion des cartes ////////
////////////////////////////////////
