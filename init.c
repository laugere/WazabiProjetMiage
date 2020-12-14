//////////////////////////////////////////////////
/////   GESTION INITIALISATION  //////////////////
//////////////////////////////////////////////////

// Intialise la partie en demandant le nombre de joueurs (2 - 6)
// Puis instancie le nombre de joueurs dans la liste
// Enfin, il lance la méthode ajouterJoueur pour ajouter des joueurs à la liste
void initPartie(listeJoueurs *listeJoueurs, pileCartes *pioche)
{
    int nbJ = 0;
    int ajoute = 0;

    do
    {
        printf("Combien de joueurs pour cette partie ?\n");
        scanf("%d", &nbJ);
        viderBuffer();
        if (nbJ < 2 || nbJ > 6)
        {
            printf("Le Wazabi ne peut être joue que de 2 a 6 joueurs.\n");
        }

        //int i = 'a';
        //printf("%d\n",i); <-- retourne 97 (ascii de a)
        // -48 pour convertir en int

    } while (nbJ < 2 || nbJ > 6);

    listeJoueurs->nb = nbJ;

    //initialise les joueurs et leur dés
    while (ajoute != nbJ)
    {
        ajouterJoueur(listeJoueurs, pioche, ajoute);
        ajoute++;
    }
}

// Détermine le premier joueur qui va joueur le premier tour
// Tous les joueurs vont effectuer un lancé et celui qui obtiens le plus de wazabi
// Commence (wazabi = 1 en valeur de face de dé)
joueur *determinePremierJoueur(listeJoueurs *listeJoueurs, int nbJ, dice de)
{
    // Lexique
    int iterator;
    int avantDernierW;
    int maxW;
    int wCourant;
    joueur *ptrJoueur;
    joueur *joueurRetour;

    // Début
    maxW = 0;
    ptrJoueur = listeJoueurs->debut;
    while (maxW == 0)
    {
        for (iterator = 0; iterator < nbJ; iterator++)
        {
            lancerDe(de, ptrJoueur->des, ptrJoueur->pseudo);
            wCourant = retourneSommeWazabi(ptrJoueur->des);
            if (wCourant > maxW)
            {
                maxW = wCourant;
                joueurRetour = ptrJoueur;
            }
            ptrJoueur = ptrJoueur->suivant;
        }
        if(maxW == avantDernierW){
            maxW = 0;
        }
    }

    printf("Le joueur %s commence.\n", joueurRetour->pseudo);

    return joueurRetour;
    // Fin
}

// Permet d'initaliser l'objet dé en lui indiquant toutes les faces que celui-ci peut avoir
void initDe(dice *de)
{
    (*de).faces[0] = 1;
    (*de).faces[1] = 1;
    (*de).faces[2] = 1;
    (*de).faces[3] = 2;
    (*de).faces[4] = 2;
    (*de).faces[5] = 3;
}

// Ajoute un joueur dans la liste de joueurs donnée en paramètre
// On demandera le pseudo de celui-ci (max 25 caractères)
void ajouterJoueur(listeJoueurs *listeJoueurs, pileCartes *pioche, int ajoute)
{
    int numJ = ajoute + 1;
    joueur *ptrAux = listeJoueurs->debut;
    joueur *ptrPrec = ptrAux;
    char pseudo[25];
    int tailleListe = 0;
    int nbJ = listeJoueurs->nb;

    joueur *tmpJoueur = (joueur *)malloc(sizeof(joueur));

    if (ptrAux == NULL)
    {
        printf("Quel est le pseudo du joueur %d ?\n", numJ);

        scanfByRomeo(pseudo, 25);
        //initialise le pseudo
        for (int i = 0; i < 25; i++)
        {
            tmpJoueur->pseudo[i] = pseudo[i];
        }

        //initialise les dés
        for (int i = 0; i < 24; i++)
        {
            if (i <= 3)
            {
                tmpJoueur->des[i] = 1;
            }
            else
            {
                tmpJoueur->des[i] = 0;
            }
        }

        tmpJoueur->suivant = NULL;
        listeJoueurs->debut = tmpJoueur;
    }
    else
    {
        int ajoute = 0;
        while (ajoute != 1)
        {
            ptrPrec = ptrAux;
            if (ptrAux->suivant == NULL)
            {
                printf("Quel est le pseudo du joueur %d ?\n", numJ);
                scanfByRomeo(pseudo, 25);
                //initialise le pseudo
                for (int i = 0; i < 25; i++)
                {
                    tmpJoueur->pseudo[i] = pseudo[i];
                }
                //initialise les dés
                for (int i = 0; i < 24; i++)
                {
                    if (i <= 3)
                    {
                        tmpJoueur->des[i] = 1;
                    }
                    else
                    {
                        tmpJoueur->des[i] = 0;
                    }
                }
                tmpJoueur->suivant = NULL;

                ptrAux->suivant = tmpJoueur;
                ptrAux->suivant->precedent = ptrPrec;
                ajoute = 1;
            }
            ptrAux = ptrAux->suivant;
        }
    }

    // Initie la liste de cartes du joueur
    initListeCarte(tmpJoueur, pioche);

    //lie le premier et le dernier joueur

    joueur *firstPlayer = listeJoueurs->debut;
    joueur *lastPlayer = listeJoueurs->debut;
    joueur *ptrJoueurCourant = listeJoueurs->debut;
    int trouve = 0;

    while (trouve != 1)
    {
        if (ptrJoueurCourant->suivant == NULL)
        {
            lastPlayer = ptrJoueurCourant;
            trouve = 1;
        }
        ptrJoueurCourant = ptrJoueurCourant->suivant;
        tailleListe++;
    }

    if (tailleListe == nbJ)
    {
        firstPlayer->precedent = lastPlayer;
        lastPlayer->suivant = firstPlayer;
    }
}

// Initie la pioche en y ajoutant toutes les cartes du jeu (36 cartes)
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
        selectCarteEmpiler(carte, pioche, iterator);
    }
    // Fin
}

// Appelle la fonction qui empile la carte correspondant à l'index dans la pioche
void selectCarteEmpiler(int index, pileCartes *pioche, int nCarte)
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
                    "Rejouez et changement de sens",
                    nCarte);
        break;
    case 1:
        //// Supprimez 2 de vos dés ////
        empileCarte(pioche,
                    3,
                    1,
                    "Les des sont retires de la partie.",
                    "Supprimez 2 de vos des",
                    nCarte);
        break;
    case 2:
        //// Donnez 1 de vos dés au joueur de votre choix ////
        empileCarte(pioche,
                    3,
                    2,
                    "L effet est independant des des que vous avez peut-etre deja donnes avec la ou les figure(s).",
                    "Donnez 1 de vos des au joueur de votre choix",
                    nCarte);
        break;
    case 3:
        //// Le joueur de votre choix n’a plus qu’1 carte ////
        empileCarte(pioche,
                    1,
                    3,
                    "Le joueur choisi doit avoir au moins 2 cartes en main. Il choisit alors la carte qu il souhaite conserver et se defausse des autres.",
                    "Le joueur de votre choix n a plus qu 1 carte",
                    nCarte);
        break;
    case 4:
        //// Piochez 3 cartes supplémentaires ////
        empileCarte(pioche,
                    1,
                    4,
                    "L effet est independant des cartes que vous avez peut etre obtenues avec la ou les figure(s).",
                    "Piochez 3 cartes supplementaires",
                    nCarte);
        break;
    case 5:
        //// Supprimez 1 de vos des ////
        empileCarte(pioche,
                    1,
                    5,
                    "Le de est retire de la partie. On ne peut pas jouer cette carte si on obtient dans le meme tour 2 figures (Donne de) ou plus avec ses des.",
                    "Supprimez 1 de vos des",
                    nCarte);
        break;
    case 6:
        //// Tous les joueurs donnent leurs dés à leur voisin de droite ou de gauche ////
        empileCarte(pioche,
                    2,
                    6,
                    "Selon le choix du joueur qui pose la carte. (Il doit lui aussi donner ses des).",
                    "Tous les joueurs donnent leurs des a leur voisin de droite ou de gauche",
                    nCarte);
        break;
    case 7:
        //// Prenez 1 carte au joueur de votre choix ////
        empileCarte(pioche,
                    1,
                    7,
                    "Le joueur vous presente ses cartes en eventail faces cachees, prenez celle de votre choix. Si aucun joueur n a de carte prenez-en une dans la pioche.",
                    "Prenez 1 carte au joueur de votre choix",
                    nCarte);
        break;
    case 8:
        //// Tous les joueurs sauf vous n’ont plus que 2 cartes ////
        empileCarte(pioche,
                    2,
                    8,
                    "Les joueurs ayant plus de 2 cartes choisissent celles qu ils souhaitent conserver et se defaussent des autres.",
                    "Tous les joueurs sauf vous n ont plus que 2 cartes",
                    nCarte);
        break;
    case 9:
        //// Le joueur de votre choix passe son tour ////
        empileCarte(pioche,
                    0,
                    9,
                    "Posez la carte, face visible, devant le joueur choisi qui la conserve jusqu’à ce qu’il ait passe son tour puis la defausse. Plusieurs de ces cartes peuvent se cumuler devant le meme joueur.",
                    "Le joueur de votre choix passe son tour",
                    nCarte);
        break;
    default:
        break;
    }
    // Fin
}

// Initie la liste circulaire de cartes
// Liste circulaire (précédent de premier est dernier)
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

// Ajoute la première carte de la liste cirulaire de cartes
// Obligatoire pour une liste circulaire
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