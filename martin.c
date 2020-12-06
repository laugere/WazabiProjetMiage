carte *selectionCarte(joueur *joueur, bool cache)
{
    // Lexique
    carte *vRetour;
    carte *aux;
    char entry;

    // Début
    aux = joueur->listecartes.premier;
    while (aux != NULL)
    {
        printf("\n\n");
        printf("----------------------------------------\n");
        if (cache)
        {
            printf("carte numero : %d", aux->index);
        }
        else
        {
            printf("%s \n", aux->titre);
            printf("%s", aux->effet);
            printf("Cette carte coute %d wazabi(s) \n", aux->cout);
        }
        printf("----------------------------------------\n");
        printf("Choisir cette carte ? [s] \n");
        printf("[q]<-- Prec - Suivante -->[d]");
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
            vRetour = aux;
            aux = NULL;
            break;
        }
    }

    return vRetour;
    // Fin
}

void utilisationCarte(joueur *joueur, pileCartes *pioche, listeJoueurs *listeJoueurs, int sens, pileCartes *defausse)
{
    // Lexique
    int index;
    carte *carte;

    // Début
    carte = selectionCarte(joueur, false);
    index = carte->index;
    switch (index)
    {
    case 0:
        ChangementSens(sens);
        break;
    case 1:
        supprimer2Des(joueur->des);
        break;
    case 2:
        donner1De(joueur, listeJoueurs);
        break;
    case 3:
        joueur1Carte(listeJoueurs, defausse);
        break;
    case 4:
        piochez3Cartes(joueur, pioche);
        break;
    case 5:
        supprimer1De(joueur->des);
        break;
    case 6:
        switchDes(listeJoueurs);
        break;
    case 7:
        prendre1Carte(listeJoueurs, joueur);
        break;
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
    deJoueur[index + 1] = 1;
    // Fin
}

void supprimerDe(int deJoueur[])
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

void donner1De(joueur *joueur, listeJoueurs *listeJoueurs)
{
    // Lexique

    // Début
    printf("Vous avez choisi de donner un dé ...");
    transfertDe(joueur->des, listeJoueurs);
    printf("Le de a ete donne.");
    // Fin
}

void transfertDe(int deJoueurEmetteur[], listeJoueurs *listeJoueurs)
{
    // Lexique
    joueur *JoueurRecepteur;

    // Début
    JoueurRecepteur = selectionJoueur(listeJoueurs);
    supprimer1De(deJoueurEmetteur);
    ajouterDe(JoueurRecepteur->des);
    // Fin
}

joueur *selectionJoueur(listeJoueurs *listeJoueurs)
{
    // Lexique
    joueur *aux;
    joueur *joueurRetour;
    char entry;

    // Début
    aux = listeJoueurs->debut;
    while (aux != NULL)
    {
        printf("\n\n");
        printf("----------------------------------------\n");
        printf("%s \n", aux->pseudo);
        printf("----------------------------------------\n");
        printf("Choisir ce joueur ? [s] \n");
        printf("[q]<-- Prec - Suivante -->[d]");
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

    return joueurRetour;
    // Fin
}

void supprimer1De(int deJoueur[])
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 1 de...\n");
    supprimerDe(deJoueur);
    printf("Le de a ete supprime.");
    // Fin
}

void supprimer2Des(int deJoueur[])
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 2 des...\n");
    supprimerDe(deJoueur);
    supprimerDe(deJoueur);
    printf("Les des ont ete supprimes.");
    // Fin
}

void initPioche(pileCartes *pioche)
{
    // Lexique
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

carte *piocheCarte(pileCartes *pioche)
{
    // Lexique
    carte *aux;
    carte *carteRetour;

    // Début
    if (pioche == NULL)
    {
        exit(EXIT_FAILURE);
    }

    aux = pioche->premier;

    if (pioche != NULL && pioche->premier != NULL)
    {
        carteRetour = aux;
        pioche->premier = aux->suivant;
    }

    return carteRetour;
    // Fin
}

void initListeCarte(joueur *joueur, pileCartes *pioche)
{
    // Lexique
    int iterator;

    // Début
    joueur->listecartes.dernier = NULL;
    joueur->listecartes.premier = NULL;
    joueur->listecartes.taille = 0;
    ajoutFirstCarteJoueur(&joueur->listecartes, pioche);
    for (iterator = 0; iterator < 2; iterator++)
    {
        ajoutCarteJoueur(&joueur->listecartes, piocheCarte(pioche));
    }
    // Fin
}

void ajoutFirstCarteJoueur(listeCartes *listecarte, pileCartes *pioche)
{
    // Lexique
    carte *newCarte;

    // Début
    newCarte = NULL;
    newCarte = piocheCarte(pioche);
    newCarte->suivant = newCarte;
    newCarte->precedent = newCarte;
    listecarte->premier = newCarte;
    listecarte->dernier = newCarte;
    listecarte->taille++;
    // Fin
}

void ajoutCarteJoueur(listeCartes *listecarte, carte *carte)
{
    // Lexique

    // Début
    carte->precedent = listecarte->dernier;
    carte->suivant = listecarte->dernier->suivant;
    listecarte->dernier->suivant = carte;
    listecarte->premier->precedent = carte;
    listecarte->dernier = carte;
    listecarte->taille++;
    // Fin
}

void transfertCarteDefausse(listeCartes *listeCartes, pileCartes *defausse, int index)
{
    // Lexique
    carte *ptrCarte;
    carte *ptrPrec;
    int iterator;

    // Début
    ptrCarte = listeCartes->premier;

    if (listeCartes->taille < index)
    {
        exit(EXIT_FAILURE);
    }

    for (iterator = 0; iterator < index; iterator++)
    {
        ptrPrec = ptrCarte;
        ptrCarte = ptrCarte->suivant;
    }

    ptrPrec->suivant = ptrCarte->suivant;
    ptrPrec->suivant->precedent = ptrPrec;
    empileCarte(defausse, ptrCarte->cout, ptrCarte->index, ptrCarte->effet, ptrCarte->titre);
    // Fin
}

void transfertCarteJoueur(listeCartes *listecarteEmetteur, listeCartes *listecarteRecepteur, int index)
{
    // Lexique
    carte *ptrCarte;
    carte *ptrPrec;
    int iterator;

    // Début
    ptrCarte = listecarteEmetteur->premier;

    if (listecarteEmetteur->taille < index)
    {
        exit(EXIT_FAILURE);
    }

    for (iterator = 0; iterator < index; iterator++)
    {
        ptrPrec = ptrCarte;
        ptrCarte = ptrCarte->suivant;
    }

    ptrPrec->suivant = ptrCarte->suivant;
    ptrPrec->suivant->precedent = ptrPrec;
    ajoutCarteJoueur(listecarteRecepteur, ptrCarte);
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

void switchDes(listeJoueurs *listeJoueurs)
{
    // Lexique
    char entry;
    int iterator;
    joueur *ptrJoueur;

    // Début
    printf("Dans quel sens voulez-vous effectuer la rotation des des ?");
    printf("[q]<-- Gauche - Droite -->[d]");
    do
    {
        entry = getchar();
    } while (entry != 'q' || entry != 'd');

    ptrJoueur = listeJoueurs->debut;

    for (iterator = 0; iterator < listeJoueurs->nb; iterator++)
    {
        if (entry == 'q')
            *ptrJoueur->suivant->des = *ptrJoueur->des;
        else if (entry == 'd')
            *ptrJoueur->precedent->des = *ptrJoueur->des;
    }
    // Fin
}

void joueur1Carte(listeJoueurs *listeJoueurs, pileCartes *defausse)
{
    // Lexique
    joueur *joueurCible;
    carte *carte;
    int iterator;

    // Début
    joueurCible = selectionJoueur(listeJoueurs);
    carte = selectionCarte(joueurCible, false);
    for (iterator = 0; iterator < joueurCible->listecartes.taille; iterator++)
    {
        if (iterator != carte->index)
        {
            transfertCarteDefausse(&joueurCible->listecartes, defausse, iterator);
        }
    }
    // Fin
}

void prendre1Carte(listeJoueurs *listeJoueurs, joueur *joueurCourant)
{
    // Lexique
    joueur *joueurCible;
    carte *carte;

    // Début
    joueurCible = selectionJoueur(listeJoueurs);
    carte = selectionCarte(joueurCible, true);
    transfertCarteJoueur(&joueurCible->listecartes, &joueurCourant->listecartes, carte->index);
    // Fin
}