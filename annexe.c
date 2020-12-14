int scanfByRomeo(char *chaine, int taille)
{
    char *positionEntree = NULL;

    if (fgets(chaine, taille, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void afficherJoueurs(listeJoueurs *listeJoueurs) //Méthode de test
{
    joueur *ptrAux = listeJoueurs->debut;
    int tailleListe = 0;
    int nbJ = listeJoueurs->nb;

    while (tailleListe != nbJ)
    {
        //Affiche le pseudo du joueur
        printf("~~~Le Joueur~~~\n");
        printf("Pseudo %s \n", ptrAux->pseudo);
        //Affiche les dés du joueur
        for (int i = 0; i <= 24; i++)
        {
            if (ptrAux->des[i] == 1)
            {
                printf("%d \n", ptrAux->des[i]);
            }
        }
        //Affiche le joueur précédent
        printf("Le joueur precedent : %s\n", ptrAux->precedent->pseudo);
        //Affiche le joueur suivant
        printf("Le joueur suivant : %s\n", ptrAux->suivant->pseudo);
        ptrAux = ptrAux->suivant;
        tailleListe++;
    }
}

bool verifFin(joueur *joueur)
{
    // Lexique

    // Début
    if (countDe(joueur->des) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // Fin
}