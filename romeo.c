#include <wazabi.c>
// Init game
void initPartie(joueur *joueurs)
{
    int nb;
    char pseudo[25];
    joueur *aux = joueurs;
    joueur *prec = joueurs;
    int nbAdv;
    int ajoute = 0;
    do
    {
        printf("Combien d'adversaires souhaitez-vous ?");
        scanf("%d", &nb);
        printf("\n");
    } while (nbAdv < 1 && nbAdv > 5);
    // la condition prend en compte le joueur courant
    

    while(ajoute != nb)
    {
        if(aux == NULL){
           joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));
           printf("Quel est le pseudo ?");
           scanf("%s", &pseudo); 
           for(int i = 0; i<25;i++){
               tmpJoueur->pseudo[i] = pseudo[i];
           }
           ajoute = ajoute + 1;
           tmpJoueur->suivant = NULL;
           tmpJoueur->suivant = NULL;
           
        }else{
            aux = aux->suivant;
        }
    }
}