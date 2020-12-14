//////////////////////////////////////////////////
/////   GESTION DÉ  //////////////////////////////
//////////////////////////////////////////////////

// Effectue le lancé de dé
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

// Affiche la face correspondant à l'index envoyé en paramètre.
void afficherDe(int face)
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

// Ajoute un dé dans la liste des dés du joueur
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

// Supprime un dé  dans la liste des dés du joueur
void supprimerDe(int deJoueur[])
{
    // Lexique
    int index;

    // Début
    index = 0;
    while (deJoueur[index] != 0)
    {
        index++;
    }
    deJoueur[index - 1] = 0;
    // Fin
}

// Utilise SupprimeDe et AjouterDe pour effectuer un transfert de dé d'un joueur à l'autre
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

// Compte le nombre de dés dans la liste de dés du joueur
// Si une valeur dans le tableau est à 0 alors le dé  n'existe pas.
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