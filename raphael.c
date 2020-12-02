int lancerDe(dice de, int des[24])
{
    //Lexique
    int index;
    int face;
    int nbDe = 0;
    int compteurnbde = 0;
    int compteurWazabi = 0;

    //Debut
    printf("combien voulez-vous lancer de de ? ");
    scanf("%i", &nbDe);

    while (compteurnbde < nbDe) // tant que le nombre de dé est plus petit que le nombre de dé du joueur
    {
        index = rand() % 6 + 1; // l'index du tableau prend une valeur aléatoir en 1 et 6
        face = de.faces[index]; // récupère la face en fonction de l'index aléatoire
        compteurWazabi = retourneSommeWazabi(face, compteurWazabi);

        afficherDe(face);

        printf("\n\n");
        compteurnbde = compteurnbde + 1;
    }
    printf("\n");
    printf("point wazabi : %i ", compteurWazabi);

    return de.faces[index];
}

void afficherDe(int face) // affichage de la face en fonction de l'index du dé
{
    if (face == 1)
    {
        printf("Wazabi");
    }
    else
    {
        if (face == 2)
        {
            printf("Pioche");
        }
        else
        {
            printf("Donne un de");
        }
    }
}

int retourneSommeWazabi(int face, int compteurWazabi)
{

    if (face == 1) // Si la face est un wazabi on compte le nombre de wazabi
    {
        compteurWazabi = compteurWazabi + 1;
    }
    return compteurWazabi;
}