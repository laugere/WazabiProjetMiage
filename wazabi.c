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

//////////////////////////////////////////////////////
//////// Déclaration des méthodes / fonctions ////////
//////////////////////////////////////////////////////

void initDe(de *de);
void initPartie(joueur *joueurs);
void afficherDe(int face);
void selectionCarte();

int lancerDe(de de);

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

    //////////////////////
    //////// TEST ////////
    //////////////////////
    // lancer dé
    lancerDe(de);

    // Sélection carte
    selectionCarte();

    return 0;
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

// Init game
void initPartie(joueur *joueurs)
{

    int nb;
    char pseudo[25];
    joueur *aux = joueurs;

    int nb;

    do
    {
        printf("Combien d'adversaires souhaitez-vous ?");
        scanf("%d", &nb);
        printf("\n");
        printf("Quel est votre pseudo ?");
        scanf("%s", &pseudo);
    } while (nb < 1 && nb > 5);
    // la condition prend en compte le joueur courant

    joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));

    *tmpJoueur->pseudo = pseudo;
    tmpJoueur->suivant = NULL;
    joueurs = tmpJoueur;

    for (int i = 0; i <= nb; i++)
    {
        joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));
        if (aux != NULL)
        {
            aux = aux->suivant;
        }
    }
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