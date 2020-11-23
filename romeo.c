#include <wazabi.c>
// Init game
void initPartie(joueur *joueurs)
{
    int nb;
    char pseudo[25];
    joueur *aux = joueurs;
    joueur *prec = joueurs;
    int nbJ;
    int ajoute = 0;
    do
    {
        printf("Combien de joueurs pour cette partie ?");
        scanf("%d", &nb);
        printf("\n");
    } while (nbJ < 2 && nbJ > 6);
    // la condition prend en compte le joueur courant

    while (ajoute != nbJ)
    {
        joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));
        if (aux == NULL)
        {
            printf("Quel est le pseudo ?");
            scanf("%s", &pseudo);
            for (int i = 0; i < 25; i++)
            {
                tmpJoueur->pseudo[i] = pseudo[i];
            }
            tmpJoueur->suivant = NULL;
            *tmpJoueur->de = NULL;
            ajoute = ajoute + 1;
            prec = aux;
            
        }
        else
        {
            tmpJoueur->precedent = prec;
            printf("Quel est le pseudo ?");
            scanf("%s", &pseudo);
            for (int i = 0; i < 25; i++)
            {
                tmpJoueur->pseudo[i] = pseudo[i];
            }
            tmpJoueur->suivant = NULL;
            *tmpJoueur->de = NULL;
            ajoute = ajoute + 1;
        }
        aux = aux->suivant;        
    }
}

void piocheCarte(carte *lesCartes)
{
}

initPioche()
{
}