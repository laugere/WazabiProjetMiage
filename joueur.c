// Sélectionne un joueur parmis la liste des joueurs de la partie
// Affiche tous les joueurs sauf le joueur courant.
joueur *selectionJoueur(joueur *joueurCourant, listeJoueurs *listeJoueurs)
{
    // Lexique
    joueur *aux;
    joueur *joueurRetour;
    char entry;

    // Début
    aux = listeJoueurs->debut;
    while (aux != NULL)
    {
        if (aux != joueurCourant)
        {
            printf("\n\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("%s \n", aux->pseudo);
            printf("--------------------------------------------------------------------------------\n");
            printf("Choisir ce joueur ? [s] \n");
            printf("[q]<-- Prec - Suivante -->[d] \n");
            do
            {
                entry = getchar();
            } while (entry != 'd' && entry != 'q' && entry != 's');
            switch (entry)
            {
            case 'q':
                aux = aux->precedent;
                break;
            case 'd':
                aux = aux->suivant;
                break;
            case 's':
                joueurRetour = aux;
                aux = NULL;
                break;
            }
        }
        else
        {
            aux = aux->suivant;
        }
    }

    return joueurRetour;
    // Fin
}