#include "wazabi.c"

void selectionCarte(joueur *joueur, pileCartes *pioche)
{
    // Lexique
    carte *aux;
    carte *prec;
    char entry;

    // Début
    aux = joueur->listecartes.premier;
    while (aux != NULL)
    {
        do
        {
            printf("%s \n", aux->titre);
            printf("%s", aux->effet);
            printf("Cette carte coute %d wazabi(s) \n", aux->cout);
            printf("Utiliser cette carte ? [s] \n");
            printf("[q]<-- Prec - Suivante -->[d]");
            scanf("%c", &entry);
        } while (entry != 'q' || entry != 'd' || entry != 's');
        if (entry == 's')
        {
            utilisationCarte(aux, joueur, pioche);
        }
        else
        {
            if (entry == 'q')
            {
                aux = aux->precedent;
            }
            else
            {
                aux = aux->suivant;
            }
        }
    }
    // Fin
}

void utilisationCarte(carte *carte, joueur *joueur, pileCartes *pioche)
{
    // Lexique
    int index;

    // Début
    index = carte->index;
    switch (index)
    {
    case 0:
        // ChangementSens();
        // break;
    case 1:
        // supprimer2Des(&joueur->des);
        // break;
    case 2:
        // Donnez1De();
        // break;
    case 3:
        // Joueur1Carte();
        // break;
    case 4:
        // piochez3Cartes();
        // break;
    case 5:
        // supprimer1De(&joueur->des);
        // break;
    case 6:
        // SwitchDes();
        // break;
    case 7:
        // Prendre1Carte();
        // break;
    case 8:
        // SupprimerJoueurs2Cartes();
        // break;
    case 9:
        // SkipJoueur();
        // break;
    }
    // Fin
}

void supprimerDe(int *deJoueur[])
{
    // Lexique
    int i;

    // Début
    for (i = 0; deJoueur[i] != '\0'; i++)
    {
        if (deJoueur[i + 1] == '\0')
        {
            deJoueur[i] = '\0';
        }
    }
    // Fin
}

void supprimer1De(int *deJoueur[])
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 1 dé...");
    supprimerDe(deJoueur);
    printf("Le dé a été supprimé.");
    // Fin
}

void supprimer2De(int *deJoueur[])
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 2 dés...");
    supprimerDe(deJoueur);
    supprimerDe(deJoueur);
    printf("Les dés ont été supprimés.");
    // Fin
}

void initPioche(pileCartes *pioche)
{
    // Lexique
    carte *aux;
    int iterator;

    // Début
    //// Rejouez et changement de sens ////
    for (iterator = 0; iterator <= 2; iterator++)
    {
        empileCarte(pioche,
                    0,
                    0,
                    "Le joueur rejoue et la partie continue dans le sens inverse.",
                    "Rejouez et changement de sens");
    }
    //// Supprimez 2 de vos dés ////
    for (iterator = 0; iterator <= 5; iterator++)
    {
        empileCarte(pioche,
                    3,
                    1,
                    "Les des sont retires de la partie.",
                    "Supprimez 2 de vos des");
    }
    //// Donnez 1 de vos dés au joueur de votre choix ////
    for (iterator = 0; iterator <= 3; iterator++)
    {
        empileCarte(pioche,
                    3,
                    2,
                    "L'effet est independant des des que vous avez peut-etre deja donnes avec la ou les figure(s).",
                    "Donnez 1 de vos des au joueur de votre choix");
    }
    //// Le joueur de votre choix n’a plus qu’1 carte ////
    for (iterator = 0; iterator <= 4; iterator++)
    {
        empileCarte(pioche,
                    1,
                    3,
                    "Le joueur choisi doit avoir au moins 2 cartes en main. Il choisit alors la carte qu'il souhaite conserver et se defausse des autres.",
                    "Le joueur de votre choix n’a plus qu’1 carte");
    }
    //// Piochez 3 cartes supplémentaires ////
    for (iterator = 0; iterator <= 3; iterator++)
    {
        empileCarte(pioche,
                    1,
                    4,
                    "L’effet est independant des cartes que vous avez peut-etre obtenues avec la ou les figure(s).",
                    "Piochez 3 cartes supplémentaires");
    }
    //// Supprimez 1 de vos des ////
    for (iterator = 0; iterator <= 7; iterator++)
    {
        empileCarte(pioche,
                    1,
                    5,
                    "Le de est retire de la partie. On ne peut pas jouer cette carte si on obtient dans le meme tour 2 figures (Donne de) ou plus avec ses des.",
                    "Supprimez 1 de vos des");
    }
    //// Tous les joueurs donnent leurs dés à leur voisin de droite ou de gauche ////
    for (iterator = 0; iterator <= 3; iterator++)
    {
        empileCarte(pioche,
                    2,
                    6,
                    "Selon le choix du joueur qui pose la carte. (Il doit lui aussi donner ses dés).",
                    "Tous les joueurs donnent leurs dés à leur voisin de droite ou de gauche");
    }
    //// Prenez 1 carte au joueur de votre choix ////
    for (iterator = 0; iterator <= 3; iterator++)
    {
        empileCarte(pioche,
                    1,
                    7,
                    "Le joueur vous presente ses cartes en eventail faces cachees, prenez celle de votre choix. Si aucun joueur n’a de carte prenez-en une dans la pioche.",
                    "Prenez 1 carte au joueur de votre choix");
    }
    //// Tous les joueurs sauf vous n’ont plus que 2 cartes ////
    for (iterator = 0; iterator <= 4; iterator++)
    {
        empileCarte(pioche,
                    2,
                    8,
                    "Les joueurs ayant plus de 2 cartes choisissent celles qu’ils souhaitent conserver et se defaussent des autres.",
                    "Tous les joueurs sauf vous n’ont plus que 2 cartes");
    }
    //// Le joueur de votre choix passe son tour ////
    for (iterator = 0; iterator <= 2; iterator++)
    {
        empileCarte(pioche,
                    0,
                    9,
                    "Posez la carte, face visible, devant le joueur choisi qui la conserve jusqu’à ce qu’il ait passe son tour puis la defausse. Plusieurs de ces cartes peuvent se cumuler devant le meme joueur.",
                    "Le joueur de votre choix passe son tour");
    }
    // Fin
}

void empileCarte(pileCartes *pioche, int cout, int index, char effet[], char titre[])
{
    // Lexique
    carte *aux;

    // Début
    aux = pioche->premier;
    carte *nouvelleCarte = malloc(sizeof(*nouvelleCarte));
    if (pioche == NULL || nouvelleCarte == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouvelleCarte->cout = cout;
    nouvelleCarte->index = index;
    strcpy(nouvelleCarte->effet, effet);
    strcpy(nouvelleCarte->titre, titre);
    nouvelleCarte->suivant = aux;
    pioche->premier = nouvelleCarte;
    // Fin
}

void piocheCarte()
{
    // Lexique

    // Début

    // Fin
}