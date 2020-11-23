#include <wazabi.c>
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

    for(int i = 0; i< nb;i++){
        joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));

        if(i = 0){
            for(int j = 0; j<25;j++){
                tmpJoueur->pseudo[j] = pseudo[j];
            }
        }else{
            //tmpJoueur->pseudo = ""
        }
        
    }
    

}