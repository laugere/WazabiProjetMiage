// Init game
void initPartie(listeJoueurs *listeJoueurs, pileCartes *pioche)
{
    int nbJ = 0;
    int ajoute = 0;

    do
    {
        printf("Combien de joueurs pour cette partie ?\n");
        scanf("%d", &nbJ);
        viderBuffer();
        printf("\n");
        if(nbJ < 2 || nbJ > 6){
            prinft("Le Wazabi ne peut être joué que de 2 à 6 joueurs.\n");
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
    //afficherJoueurs(listeJoueurs);
}

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

        //scanf("%s", pseudo);
        scanfByRomeo(pseudo, 25);
        //
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
                //scanf("%s", pseudo);
                scanfByRomeo(pseudo, 25);
                //
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

int scanfByRomeo(char *chaine, int taille)
{
    char *positionEntree = NULL;

    if (fgets(chaine, taille, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void afficherJoueurs(listeJoueurs *listeJoueurs) //Méthode de test
{
    joueur *ptrAux = listeJoueurs->debut;
    int tailleListe = 0;
    int nbJ = listeJoueurs->nb;

    while (tailleListe != nbJ)
    {
        //Affiche le pseudo du joueur
        printf("~~~Le Joueur~~~\n");
        printf("Pseudo %s \n", ptrAux->pseudo);
        //Affiche les dés du joueur
        for (int i = 0; i <= 24; i++)
        {
            if (ptrAux->des[i] == 1)
            {
                printf("%d \n", ptrAux->des[i]);
            }
        }
        //Affiche le joueur précédent
        printf("Le joueur precedent : %s\n", ptrAux->precedent->pseudo);
        //Affiche le joueur suivant
        printf("Le joueur suivant : %s\n", ptrAux->suivant->pseudo);
        ptrAux = ptrAux->suivant;
        tailleListe++;
    }
}

void ChangementSens(int sens){
    if(sens == 0){
        sens = 1; //inverse le sens
    }else{
        sens = 0; //remet le sens normal
    }
}

void piochez3Cartes(joueur *joueur, pileCartes *pioche){

    for(int i = 0; i < 3 ; i++){
        ajoutCarteJoueur(&joueur->listecartes, piocheCarte(pioche));
  }
}