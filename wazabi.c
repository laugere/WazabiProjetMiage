#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

///////////////////////////////////////
//////// Déclaration des types ////////
///////////////////////////////////////

typedef struct joueur joueur;
struct joueur
{
    char pseudo[25];
    int de[24];
    carte cartes;
    joueur *suivant;
};

typedef struct carte carte;
struct carte
{
    int index;
    int cout;
    char titre[255];
    char effet[255];
    carte *suivant;
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
// FOR TEST
void test();

// Fonctions
int lancerDe(de de);

int main(int argc, char *argv[])
{
    // Initialisation de srand
    srand(time(NULL));

    // Création de la liste de joueur
    joueur listeJoueur;

    // Initialisation de la partie
    initPartie(&listeJoueur);

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

// Roll dice randomly and return
// index of the face
// 1 = Wazabi
// 2 = Pioche
// 3 = Donne dé
int lancerDe(de de)
{
    int index;
    int face;

    index = rand() % 6 + 1;

    face = de.faces[index];
    afficherDe(face);

    return de.faces[index];
}

// Show the face value
void afficherDe(int face)
{
    if (face == 1)
    {
        printf("Wazabi");
    }
    else
    {
        if (face == 2)
        {
            printf("Pioche");
        }
        else
        {
            printf("Donne un de");
        }
    }
}

////////////////////////////////////
//////// Gestion des cartes ////////
////////////////////////////////////

void selectionCarte(joueur *joueur)
{
    // Lexique
    carte *aux;
    carte *prec;
    char entry;

    // Début
    *aux = joueur->cartes;
    while (aux != NULL)
    {
        do
        {
            printf("%s \n", aux->titre);
            printf("%s", aux->effet);
            printf("Cette carte coute %d wazabi(s)", aux->cout);
            printf("[q]<-- Prec - Suivante -->[d]");
            scanf("%c", entry);
        } while (entry != 'q' || entry != 'd');
        if (entry == 'q')
        {

        }
        else
        {
            
        }
    }
    // Fin
}