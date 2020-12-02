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
        //supprimer2Des(&joueur->des);
        break;
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
        //supprimer1De(&joueur->des);
        break;
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
        printf("test");
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
    int carte;
    int tabCarte[10];

    // Début
    //// Init tabCarte
    tabCarte[0] = 2; //// Rejouez et changement de sens ////
    tabCarte[1] = 5; //// Supprimez 2 de vos dés ////
    tabCarte[2] = 3; //// Donnez 1 de vos dés au joueur de votre choix ////
    tabCarte[3] = 4; //// Le joueur de votre choix n’a plus qu’1 carte ////
    tabCarte[4] = 3; //// Piochez 3 cartes supplémentaires ////
    tabCarte[5] = 7; //// Supprimez 1 de vos des ////
    tabCarte[6] = 3; //// Tous les joueurs donnent leurs dés à leur voisin de droite ou de gauche ////
    tabCarte[7] = 3; //// Prenez 1 carte au joueur de votre choix ////
    tabCarte[8] = 4; //// Tous les joueurs sauf vous n’ont plus que 2 cartes ////
    tabCarte[9] = 2; //// Le joueur de votre choix passe son tour ////
    //// empileCarte
    for (iterator = 0; iterator < 36; iterator++)
    {
        do
        {
            carte = rand() % 10 + 0;
        } while (tabCarte[carte] == 0);
        tabCarte[carte] = tabCarte[carte] - 1;
        selectCarteEmpiler(carte, pioche);
    }
    // Fin
}

void selectCarteEmpiler(int index, pileCartes *pioche)
{
    // Lexique

    // Début
    switch (index)
    {
    case 0:
        //// Supprimez 2 de vos dés ////
        empileCarte(pioche,
                    0,
                    0,
                    "Le joueur rejoue et la partie continue dans le sens inverse.",
                    "Rejouez et changement de sens");
        break;
    case 1:
        //// Supprimez 2 de vos dés ////
        empileCarte(pioche,
                    3,
                    1,
                    "Les des sont retires de la partie.",
                    "Supprimez 2 de vos des");
        break;
    case 2:
        //// Donnez 1 de vos dés au joueur de votre choix ////
        empileCarte(pioche,
                    3,
                    2,
                    "L effet est independant des des que vous avez peut-etre deja donnes avec la ou les figure(s).",
                    "Donnez 1 de vos des au joueur de votre choix");
        break;
    case 3:
        //// Le joueur de votre choix n’a plus qu’1 carte ////
        empileCarte(pioche,
                    1,
                    3,
                    "Le joueur choisi doit avoir au moins 2 cartes en main. Il choisit alors la carte qu il souhaite conserver et se defausse des autres.",
                    "Le joueur de votre choix n a plus qu 1 carte");
        break;
    case 4:
        //// Piochez 3 cartes supplémentaires ////
        empileCarte(pioche,
                    1,
                    4,
                    "L effet est independant des cartes que vous avez peut etre obtenues avec la ou les figure(s).",
                    "Piochez 3 cartes supplementaires");
        break;
    case 5:
        //// Supprimez 1 de vos des ////
        empileCarte(pioche,
                    1,
                    5,
                    "Le de est retire de la partie. On ne peut pas jouer cette carte si on obtient dans le meme tour 2 figures (Donne de) ou plus avec ses des.",
                    "Supprimez 1 de vos des");
        break;
    case 6:
        //// Tous les joueurs donnent leurs dés à leur voisin de droite ou de gauche ////
        empileCarte(pioche,
                    2,
                    6,
                    "Selon le choix du joueur qui pose la carte. (Il doit lui aussi donner ses des).",
                    "Tous les joueurs donnent leurs des a leur voisin de droite ou de gauche");
        break;
    case 7:
        //// Prenez 1 carte au joueur de votre choix ////
        empileCarte(pioche,
                    1,
                    7,
                    "Le joueur vous presente ses cartes en eventail faces cachees, prenez celle de votre choix. Si aucun joueur n a de carte prenez-en une dans la pioche.",
                    "Prenez 1 carte au joueur de votre choix");
        break;
    case 8:
        //// Tous les joueurs sauf vous n’ont plus que 2 cartes ////
        empileCarte(pioche,
                    2,
                    8,
                    "Les joueurs ayant plus de 2 cartes choisissent celles qu ils souhaitent conserver et se defaussent des autres.",
                    "Tous les joueurs sauf vous n ont plus que 2 cartes");
        break;
    case 9:
        //// Le joueur de votre choix passe son tour ////
        empileCarte(pioche,
                    0,
                    9,
                    "Posez la carte, face visible, devant le joueur choisi qui la conserve jusqu’à ce qu’il ait passe son tour puis la defausse. Plusieurs de ces cartes peuvent se cumuler devant le meme joueur.",
                    "Le joueur de votre choix passe son tour");
        break;
    default:
        break;
    }
    // Fin
}

void empileCarte(pileCartes *pioche, int cout, int index, char effet[], char titre[])
{
    // Lexique

    // Début
    carte *nouvelleCarte = malloc(sizeof(*nouvelleCarte));
    if (pioche == NULL || nouvelleCarte == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouvelleCarte->cout = cout;
    nouvelleCarte->index = index;
    strcpy(nouvelleCarte->effet, effet);
    strcpy(nouvelleCarte->titre, titre);
    nouvelleCarte->suivant = pioche->premier;
    pioche->premier = nouvelleCarte;
    // Fin
}

carte piocheCarte(pileCartes *pioche)
{
    // Lexique
    carte *aux;
    carte carteRetour;

    // Début
    if (pioche == NULL)
    {
        exit(EXIT_FAILURE);
    }

    aux = pioche->premier;

    if (pioche != NULL && pioche->premier != NULL)
    {
        carteRetour = *aux;
        pioche->premier = aux->suivant;
    }

    return carteRetour;
    // Fin
}

void initListeCarte(joueur *joueur, pileCartes *pioche)
{
    // Lexique
    // Début
    joueur->listecartes.dernier = NULL;
    joueur->listecartes.premier = NULL;
    joueur->listecartes.taille = 0;
    ajoutFirstCarteJoueur(&joueur, &pioche);
    // Fin
}

void ajoutFirstCarteJoueur(joueur *joueur, pileCartes *pioche)
{
    // Lexique
    listeCartes listeCarte;
    carte *newCarte;
    int iterator;
    int ptrCarte;

    // Début
    listeCarte = joueur->listecartes;
    *newCarte = piocheCarte(&pioche);
    newCarte->suivant = newCarte;
    listeCarte.premier = newCarte;
    listeCarte.dernier = newCarte;
    listeCarte.taille++;
    // Fin
}

void ajoutCarteJoueur(joueur *joueur, pileCartes *pioche)
{
    // Lexique
    listeCartes listeCarte;
    carte *newCarte;
    carte *dernierCarte;
    int iterator;
    int ptrCarte;

    // Début
    listeCarte = joueur->listecartes;
    *newCarte = piocheCarte(&pioche);
    dernierCarte = listeCarte.dernier;
    newCarte->suivant = dernierCarte->suivant;
    dernierCarte->suivant = newCarte;
    listeCarte.dernier = newCarte;
    listeCarte.taille++;
    // Fin
}