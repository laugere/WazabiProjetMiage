void lancerDe(dice de, int des[24], char pseudo[25])
{
    //Lexique
    int index;
    int indexDe;

    //Debut
    indexDe = 0;
    printf("Voici le resultat de votre jet %s :", pseudo);
    printf("\n");
    while (des[indexDe] != 0)
    {
        index = rand() % (6 - 1) + 1;
        afficherDe(de.faces[index]);
        des[indexDe] = de.faces[index];
        indexDe++;
    }
    // Fin
}

void afficherDe(int face) // affichage de la face en fonction de l'index du dé
{
    // Début
    switch (face)
    {
    case 1:
        printf("Wazabi\n");
        break;
    case 2:
        printf("Pioche\n");
        break;
    case 3:
        printf("Donne un de\n");
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

int retourneSommePioche(int des[24])
{
    // Lexique
    int indexDe;
    int vRetour;

    // Début
    indexDe = 0;
    vRetour = 0;
    while (des[indexDe] != 0)
    {
        if (des[indexDe] == 2)
        {
            vRetour++;
        }
        indexDe++;
    }
    return vRetour;
    // Fin
}

int retourneSommeDonneDe(int des[24])
{
    // Lexique
    int indexDe;
    int vRetour;

    // Début
    indexDe = 0;
    vRetour = 0;
    while (des[indexDe] != 0)
    {
        if (des[indexDe] == 3)
        {
            vRetour++;
        }
        indexDe++;
    }
    return vRetour;
    // Fin
}

void ajouterDe(int deJoueur[])
{
    // Lexique
    int index;

    // Début
    index = 0;
    while (deJoueur[index] != 0)
    {
        index++;
    }
    deJoueur[index] = 1;
    // Fin
}

void supprimerDe(int deJoueur[])
{
    // Lexique
    int i;

    // Début
    for (i = 0; deJoueur[i] != 0; i++)
    {
        if (deJoueur[i + 1] == 0)
        {
            deJoueur[i] = 0;
        }
    }
    // Fin
}

void transfertDe(joueur *joueurCourant, listeJoueurs *listeJoueurs)
{
    // Lexique
    joueur *JoueurRecepteur;

    // Début
    JoueurRecepteur = selectionJoueur(joueurCourant, listeJoueurs);
    supprimerDe(joueurCourant->des);
    ajouterDe(JoueurRecepteur->des);
    // Fin
}

int countDe(int des[24])
{
    // Lexique
    int vRetour;

    // Début
    vRetour = 0;
    while (des[vRetour] != 0)
    {
        vRetour++;
    }

    return vRetour;
    // Fin
}