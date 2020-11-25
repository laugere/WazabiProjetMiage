#include "wazabi.c"

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
            printf("Cette carte coute %d wazabi(s) \n", aux->cout);
            printf("Utiliser cette carte ? [s] \n");
            printf("[q]<-- Prec - Suivante -->[d]");
            scanf("%c", &entry);
        } while (entry != 'q' || entry != 'd' || entry != 's');
        if (entry == 's')
        {
            utilisationCarte(aux, joueur);
        }
        else
        {
            if (entry == 'q')
            {
                aux = aux->precedent;
            }
            else
            {
                aux = aux->suivant;
            }
        }
    }
    // Fin
}


void utilisationCarte(carte *carte, joueur *joueur)
{
    // Lexique
    int index;

    // Début
    index = carte->index;
    switch (index)
    {
    case 0:
        // ChangementSens();
        break;
    case 1:
        supprimer2Des(&joueur->des);
        break;
    case 2:
        // Donnez1De();
        break;
    case 3:
        // Joueur1Carte();
        break;
    case 4:
        // piochez3Cartes();
        break;
    case 5:
        supprimer1De(&joueur->des);
        break;
    case 6:
        // SwitchDes();
        break;
    case 7:
        // Prendre1Carte();
        break;
    case 8:
        // SupprimerJoueurs2Cartes();
        break;
    case 9:
        // SkipJoueur();
        break;
    }
    // Fin
}


void supprimerDe(int *deJoueur[])
{
    // Lexique
    int i;

    // Début
    for (i = 0; deJoueur[i] != '\0'; i++)
    {
        if (deJoueur[i + 1] == '\0')
        {
            deJoueur[i] = '\0';
        }
    }
    // Fin
}


void supprimer1De(int *deJoueur[])
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 1 dé...");
    supprimerDe(deJoueur);
    printf("Le dé a été supprimé.");
    // Fin
}


void supprimer2De(int *deJoueur[])
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 2 dés...");
    supprimerDe(deJoueur);
    supprimerDe(deJoueur);
    printf("Les dés ont été supprimés.");
    // Fin
}

void piocheCarte()
{
    // Lexique

    // Début
    // Fin
}