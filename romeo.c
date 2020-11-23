#include <wazabi.c>
// Init game
void initPartie(joueur *joueurs)
{
    int nb;
    char pseudo[25];
    joueur *aux = joueurs;
    joueur *prec = joueurs;
    int nb;
    int longueurChaine = 0;
    int ajoute = 0;
    do
    {
        printf("Combien d'adversaires souhaitez-vous ?");
        scanf("%d", &nb);
        printf("\n");
    } while (nb < 1 && nb > 5);
    // la condition prend en compte le joueur courant

    while(ajoute != nb)
    {
        if(aux == NULL){
           joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));
           printf("Quel est le pseudo ?");
           scanf("%s", &pseudo); 
           ajoute = ajoute + 1;
           tmpJoueur->suivant = NULL;
           aux = aux->suivant;
        }else{
            aux = aux->suivant;
        }
    }
}