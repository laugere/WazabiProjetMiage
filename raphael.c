#include "wazabi.c"

int lancerDe(de de)
{
    int pointwazabi = 0;
    int index;
    int face;
    int nbDe = 0;
    int compteurnbde = 0;
    printf("combien voulez-vous lancer de de ? ");
    scanf("%i", &nbDe);

    while (compteurnbde < nbDe)
    {
        index = rand() % 6 + 1;
        face = de.faces[index];
        afficherDe(face);
        retourneSommeWazabi(face, pointwazabi);
        printf("\n\n");
        compteurnbde = compteurnbde + 1;
    }
    printf("\n");
    printf("point wazabi : %i ", pointwazabi);

    return de.faces[index];
}

void afficherDe(int face)
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

int retourneSommeWazabi(int face, int pointwazabi)
{

    if (face == 1)
    {
        pointwazabi = pointwazabi + 1;
        printf("pts wazabi : %i ", pointwazabi);
    }
    return pointwazabi;
}