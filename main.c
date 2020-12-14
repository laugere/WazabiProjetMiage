#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "header.c"
#include "annexe.c"
#include "init.c"
#include "joueur.c"
#include "carte.c"
#include "de.c"

int main(int argc, char *argv[])
{
    // Initialisation de srand
    srand(time(NULL));

    // Lancement des tours
    tour();

    return 0;
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
    initPartie(&listeJoueur, &pioche);
    fin = false;
    initDe(&de);
    ptrJoueur = NULL;
    ptrJoueur = determinePremierJoueur(&listeJoueur, listeJoueur.nb, de);
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

    printf("Partie Finie !!");
    printf("Le joueur %s a gagné", ptrJoueur->pseudo);
    // Fin
}