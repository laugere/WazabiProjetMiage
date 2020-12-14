/*********************************************************************************************************
                                            GESTION DES CARTES
**********************************************************************************************************/

/*********************************************************************************************************
Méthode "selectionCarte"
Méthode de gestion des cartes jouables par le joueur courant                                        
Elle est séparé de la méthode utilisation carte, pour simplifier son utilisation dans des contextes différents
Le paramètre cache, permet à un adversaire de piocher dans le jeu du joueur, et donc de 
présenter les cartes cachées (elles sont tout de même correctement indexés)
**********************************************************************************************************/
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
        printf("--------------------------------------------------------------------------------\n");
        if (cache)
        {
            printf("carte numero : %d \n", aux->nCarte);
        }
        else
        {
            printf("%s \n", aux->titre);
            printf("%s \n", aux->effet);
            printf("Cette carte coute %d wazabi(s) \n", aux->cout);
        }
        printf("--------------------------------------------------------------------------------\n");
        printf("Choisir cette carte ? [s] \n");
        printf("Annuler et ne choisir aucune carte [z] \n");
        printf("[q]<-- Prec - Suivante -->[d] \n");
        printf("--------------------------------------------------------------------------------\n");
        do
        {
            entry = getchar();
        } while (entry != 'd' && entry != 'q' && entry != 's' && entry != 'z');
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
        case 'z':
            vRetour = NULL;
            aux = NULL;
            break;
        }
    }
    return vRetour;
    // Fin
}
/*********************************************************************************************************
Méthode "utilisationCarte"
Méthode qui rend effectif l'effet d'une carte
**********************************************************************************************************/
void utilisationCarte(joueur *joueur, pileCartes *pioche, listeJoueurs *listeJoueurs, int sens, pileCartes *defausse, int nbWJoueur)
{
    // Lexique
    int index;
    carte *carte;

    // Début
    do
    {
        carte = selectionCarte(joueur, false);
        if (carte == NULL)
        {
            break;
        }
    } while (carte->cout > nbWJoueur);
    if (carte != NULL)
    {
        index = carte->index;
        switch (index)
        {
        case 0:
            ChangementSens(sens);
            break;
        case 1:
            supprimer2Des(joueur);
            break;
        case 2:
            donner1De(joueur, listeJoueurs);
            break;
        case 3:
            joueur1Carte(listeJoueurs, defausse, joueur);
            break;
        case 4:
            piochez3Cartes(joueur, pioche);
            break;
        case 5:
            supprimer1De(joueur);
            break;
        case 6:
            switchDes(listeJoueurs);
            break;
        case 7:
            prendre1Carte(listeJoueurs, joueur);
            break;
        case 8:
            supprimerJoueur2Cartes(listeJoueurs, joueur, defausse);
            break;
        case 9:
            skipJoueur(joueur);
            break;
        }
        transfertCarteDefausse(&joueur->listecartes, defausse, carte->nCarte);
    }
    else
    {
        printf("Vous avez choisi de n'utiliser aucune carte. \n");
    }
    // Fin
}
/*********************************************************************************************************
Méthode de la carte "ChangementSens"
1 : sens inversé
0 : sens classique
**********************************************************************************************************/
void ChangementSens(int sens)
{
    if (sens == 0)
    {
        sens = 1; 
    }
    else
    {
        sens = 0;
    }
}

/*********************************************************************************************************
Méthode qui permet de piocher une carte
Permet de piocher une carte dans la pioche. Si celle-ci est vide, aucune carte n'est ajouté au deck courant
**********************************************************************************************************/
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
/*********************************************************************************************************
Méthode qui permet d'augmenter la taille de la listeCarte courante, et d'ajouter la carte courante
**********************************************************************************************************/
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

/*********************************************************************************************************
Méthode de la carte "Piochez 3 cartes"
Appel 3x la méthode "ajoutCarteJoueur" qui ajoute une carte dans le deck du joueur courant
**********************************************************************************************************/
void piochez3Cartes(joueur *joueur, pileCartes *pioche)
{

    for (int i = 0; i < 3; i++)
    {
        ajoutCarteJoueur(&joueur->listecartes, piocheCarte(pioche));
    }
}

/*********************************************************************************************************
Méthode "Empile carte"
Méthode qui empile une carte sur une pile, que ce soit la pioche ou la défausse
**********************************************************************************************************/
void empileCarte(pileCartes *pioche, int cout, int index, char effet[], char titre[], int nCarte)
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
    nouvelleCarte->nCarte = nCarte;
    strcpy(nouvelleCarte->effet, effet);
    strcpy(nouvelleCarte->titre, titre);
    nouvelleCarte->suivant = pioche->premier;
    pioche->premier = nouvelleCarte;
    // Fin
}

/*********************************************************************************************************
Méthode "transfertCarteDefausse"
Méthode qui transfert une carte courante dans la défausse de la partie
**********************************************************************************************************/
void transfertCarteDefausse(listeCartes *listeCartes, pileCartes *defausse, int nCarte)
{
    // Lexique
    carte *ptrCarte;
    carte *ptrPrec;
    carte *ptrSuiv;

    // Début
    ptrCarte = listeCartes->premier;

    while (ptrCarte->nCarte != nCarte)
    {
        ptrPrec = ptrCarte->precedent;
        ptrSuiv = ptrCarte->suivant;
        ptrCarte = ptrCarte->suivant;
    }

    ptrPrec->suivant = ptrSuiv;
    ptrSuiv->precedent = ptrPrec;

    empileCarte(defausse, ptrCarte->cout, ptrCarte->index, ptrCarte->effet, ptrCarte->titre, ptrCarte->nCarte);
    // Fin
}

/*********************************************************************************************************
Méthode "transfertCarteJoueur"
Méthode qui transfert une carte du deck d'un joueur dans le deck d'un autre joueur
**********************************************************************************************************/
void transfertCarteJoueur(listeCartes *listecarteEmetteur, listeCartes *listecarteRecepteur, int nCarte)
{
    // Lexique
    carte *ptrCarte;
    carte *ptrPrec;
    carte *ptrSuiv;

    // Début
    ptrCarte = listecarteEmetteur->premier;

    while (ptrCarte->nCarte != nCarte)
    {
        ptrPrec = ptrCarte->precedent;
        ptrSuiv = ptrCarte->suivant;
        ptrCarte = ptrCarte->suivant;
    }

    ptrPrec->suivant = ptrSuiv;
    ptrSuiv->precedent = ptrPrec;
    ajoutCarteJoueur(listecarteRecepteur, ptrCarte);
    // Fin
}

/*********************************************************************************************************
Méthode "switchDes"
Méthode qui échange les dés entre les joueurs
**********************************************************************************************************/
void switchDes(listeJoueurs *listeJoueurs)
{
    // Lexique
    char entry;
    int iterator;
    joueur *ptrJoueur;

    // Début
    printf("Dans quel sens voulez-vous effectuer la rotation des des ?\n");
    printf("[q]<-- Gauche - Droite -->[d]\n");
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
/*********************************************************************************************************
Méthode "joueur1Carte"
Méthode qui ne laisse qu'une seule carte dans le deck d'un joueur selectionné
**********************************************************************************************************/
void joueur1Carte(listeJoueurs *listeJoueurs, pileCartes *defausse, joueur *joueurCourant)
{
    // Lexique
    joueur *joueurCible;
    carte *carteChoisi;
    carte *carteSupp;
    int iterator;

    // Début
    joueurCible = selectionJoueur(joueurCourant, listeJoueurs);
    printf("%s choisi sa carte restante : \n", joueurCible->pseudo);
    carteChoisi = selectionCarte(joueurCible, false);
    carteSupp = joueurCible->listecartes.premier;
    for (iterator = 0; iterator < joueurCible->listecartes.taille; iterator++)
    {
        if (carteSupp != carteChoisi)
        {
            transfertCarteDefausse(&joueurCible->listecartes, defausse, carteSupp->nCarte);
        }
        carteSupp = carteSupp->suivant;
    }
    // Fin
}
/*********************************************************************************************************
Méthode "prendre1Carte"
Méthode qui prend une carte dans le deck d'un adversaire
**********************************************************************************************************/
void prendre1Carte(listeJoueurs *listeJoueurs, joueur *joueurCourant)
{
    // Lexique
    joueur *joueurCible;
    carte *carte;

    // Début
    joueurCible = selectionJoueur(joueurCourant, listeJoueurs);
    carte = selectionCarte(joueurCible, true);
    transfertCarteJoueur(&joueurCible->listecartes, &joueurCourant->listecartes, carte->nCarte);
    // Fin
}
/*********************************************************************************************************
Méthode "supprimerJoueur2Cartes"
Méthode qui supprime deux cartes dans le deck d'un joueur
**********************************************************************************************************/
void supprimerJoueur2Cartes(listeJoueurs *listeJoueurs, joueur *joueurCourant, pileCartes *defausse)
{
    // Lexique
    joueur *ptrJoueur;
    carte *ptrCartes;
    int iterator;
    int jterator;

    // Début
    ptrJoueur = listeJoueurs->debut;
    ptrCartes = ptrJoueur->listecartes.premier;
    for (iterator = 0; iterator < listeJoueurs->nb; iterator++)
    {
        if (ptrJoueur != joueurCourant)
        {
            for (jterator = 0; jterator < ptrJoueur->listecartes.taille - 2; jterator++)
            {
                transfertCarteDefausse(&ptrJoueur->listecartes, defausse, ptrCartes->nCarte);
                ptrCartes = ptrCartes->suivant;
            }
        }
        ptrJoueur = ptrJoueur->suivant;
    }
    // Fin
}
/*********************************************************************************************************
Méthode "skipJoueur"
Passe le tour du prochain joueur
**********************************************************************************************************/
void skipJoueur(joueur *joueurCourant)
{
    // Lexique

    // Début
    joueurCourant = joueurCourant->suivant;
    // Fin
}

/*********************************************************************************************************
                                            GESTION DES DES
**********************************************************************************************************/

/*********************************************************************************************************
Méthode de la carte "Donner un dé"
Appel la méthode qui permet de transferer un dé à un adversaire choisi par le joueur courant
**********************************************************************************************************/
void donner1De(joueur *joueur, listeJoueurs *listeJoueurs)
{
    // Lexique

    // Début
    printf("Vous avez choisi de donner un dé ...");
    transfertDe(joueur, listeJoueurs);
    printf("Le de a ete donne.");
    // Fin
}
/*********************************************************************************************************
Méthode de la carte "Supprimer un dé"
Appel la méthode "supprimerDe" qui supprime un dé de la liste de dé du joueur 
**********************************************************************************************************/
void supprimer1De(joueur *joueurCourant)
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 1 de...\n");
    supprimerDe(joueurCourant->des);
    printf("Le de a ete supprime. \n");
    // Fin
}
/*********************************************************************************************************
Méthode de la carte "Donner 2 dés"
Appel 2x la méthode "supprimerDe"
**********************************************************************************************************/
void supprimer2Des(joueur *joueurCourant)
{
    // Lexique

    // Début
    printf("Vous avez choisi de supprimer 2 des...\n");
    supprimerDe(joueurCourant->des);
    supprimerDe(joueurCourant->des);
    printf("Les des ont ete supprimes. \n");
    // Fin
}