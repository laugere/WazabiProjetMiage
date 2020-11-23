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
        // Supprimer2Des();
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
        // supprimer1De(joueur->de);
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

void supprimer1De(char deJoueur[])
{
    // Lexique
    int p;
    int i;

    // Début
    for (i = 0; deJoueur[i] != '\0'; i++)
    {
        if (deJoueur[i] == deJoueur[0])
        {
            for (p = i; deJoueur[p] != 0; p++)
                deJoueur[p] = deJoueur[p + 1];
            i--;
        }
    }
    printf("%s", deJoueur);
    // Fin
}