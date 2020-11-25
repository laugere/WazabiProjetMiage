#include <wazabi.c>
// Init game
void initPartie(listeJoueurs *listeJoueurs)
{
    int nb;
    int nbJ;
    int ajoute = 0;

    do
    {
        printf("Combien de joueurs pour cette partie ?");
        scanf("%d", &nb);
        printf("\n");
    } while (nbJ < 2 && nbJ > 6);

    //initialise les joueurs et leur dés
    while (ajoute != nbJ)
    {
        ajouterJoueur(listeJoueurs);
        ajoute++;
    }
}

void ajouterJoueur(listeJoueurs *listeJoueurs)
{
    joueur *ptrAux = listeJoueurs->debut;
    joueur *ptrPrec = ptrAux;
    char pseudo[25];

    joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));

    if (ptrAux == NULL)
    {
        printf("Quel est le pseudo ?");
        scanf("%s", &pseudo);
        for (int i = 0; i < 25; i++)
        {
            tmpJoueur->pseudo[i] = pseudo[i];
            if (i < 3)
            {
                tmpJoueur->des[i] = 1;
            }
        }
        tmpJoueur->suivant = NULL;
    }
    else
    {
        int ajoute = 0;
        while (ajoute != 1)
        {
            if (ptrAux->suivant == NULL)
            {
                printf("Quel est le pseudo ?");
                scanf("%s", &pseudo);
                for (int i = 0; i < 25; i++)
                {
                    tmpJoueur->pseudo[i] = pseudo[i];
                    if (i < 3)
                    {
                        tmpJoueur->des[i] = 1;
                    }
                }
                //tmpJoueur->suivant = tmpJoueur;

                ptrAux->suivant = tmpJoueur;
            }
            ptrAux = ptrAux->suivant;
        }
    }
    afficherJoueurs(&listeJoueurs);
}

afficherJoueurs(listeJoueurs *listeJoueurs){
    joueur *ptrAux = listeJoueurs->debut;

    while(ptrAux != NULL){
        printf("%s", ptrAux->pseudo);
        ptrAux = ptrAux->suivant;
    }
}