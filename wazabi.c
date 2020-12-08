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
    pileCartes defausse;
    bool fin;
    int sens = 0;
    joueur *ptrJoueur;
    int nbWJoueur;
    int nbDJoueur;
    int nbPJoueur;
    int iterator;
    int jterator;

    // Début
    listeJoueur.debut = NULL;

    // Initialisation de la partie
    initPioche(&pioche);
    joueur firstPlayer = initPartie(&listeJoueur, &pioche);
    fin = false;
    initDe(&de);
    ptrJoueur = NULL;
    *ptrJoueur = firstPlayer;
    do
    {
        // Lancement des dés
        printf("--------------------------------------------------------------------------------\n");
        lancerDe(de, ptrJoueur->des, ptrJoueur->pseudo);
        printf("--------------------------------------------------------------------------------\n");
        nbWJoueur = retourneSommeWazabi(ptrJoueur->des);
        nbDJoueur = retourneSommeDonneDe(ptrJoueur->des);
        nbPJoueur = retourneSommePioche(ptrJoueur->des);
        printf("Vous avez %d Wazabi\n", nbWJoueur);
        for (iterator = 0; iterator < nbDJoueur; iterator++)
        {
            donner1De(ptrJoueur, &listeJoueur);
        }
        for (jterator = 0; jterator < nbPJoueur; jterator++)
        {
            ajoutCarteJoueur(&ptrJoueur->listecartes, piocheCarte(&pioche));
        }

        utilisationCarte(ptrJoueur, &pioche, &listeJoueur, sens, &defausse, nbWJoueur);

        // Vérification si le joueur courant a encore des dés
        fin = verifFin(ptrJoueur);
        // Changement de sens si sens = 0 sens normal (gauche) si sens = 1 sens inversé (droite)
        if (sens == 0)
        {
            ptrJoueur = ptrJoueur->suivant;
        }
        else
        {
            ptrJoueur = ptrJoueur->precedent;
        }

    } while (!fin);
    // Fin
}
