void lancerDe(dice de, int *des[24])
{
    //Lexique
    int index;
    int indexDe;

    //Debut
    indexDe = 0;
    while (des[indexDe] != 0)
    {
        index = rand() % 6 + 1;
        afficherDe(index);
        *des[indexDe] = de.faces[index];
        indexDe++;
    }
    // Fin
}

void afficherDe(int face) // affichage de la face en fonction de l'index du dé
{
    // Début
    switch(face) {
        case 1:
            printf("Wazabi");
            break;
        case 2:
            printf("Pioche");
            break;
        case 3:
            printf("Donne un de");
        default:
            break;
    }
    // Fin
}

int retourneSommeWazabi(int des[24])
{
    // Lexique
    int indexDe;
    int vRetour;

    // Début
    indexDe = 0;
    vRetour = 0;
    while (des[indexDe] != 0)
    {
        if (des[indexDe] == 1)
        {
            vRetour++;
        }
        indexDe++;
    }
    return vRetour;
    // Fin
}