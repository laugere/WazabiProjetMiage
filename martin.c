#include <wazabi.c>

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
            printf("Cette carte coute %d wazabi(s)", aux->cout);
            printf("[q]<-- Prec - Suivante -->[d]");
            scanf("%c", entry);
        } while (entry != 'q' || entry != 'd');
        if (entry == 'q')
        {
            
        }
        else
        {
            
        }
    }
    // Fin
}