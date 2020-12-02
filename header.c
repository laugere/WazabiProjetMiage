///////////////////////////////////////
//////// Déclaration des types ////////
///////////////////////////////////////
typedef struct carte carte;
struct carte
{
    int index;
    int cout;
    char titre[255];
    char effet[255];
    carte *suivant;
    carte *precedent;
};

typedef struct listeCartes listeCartes;
struct listeCartes
{
    carte *premier;
    carte *dernier;
    int taille;
};

typedef struct pileCartes pileCartes;
struct pileCartes
{
    carte *premier;
};

typedef struct joueur joueur;
struct joueur
{
    char pseudo[25];
    int des[24];
    listeCartes listecartes;
    joueur *suivant;
    joueur *precedent;
};

typedef struct listeJoueurs listeJoueurs;
struct listeJoueurs
{
    joueur *debut;
};

typedef struct dice dice;
struct dice
{
    int faces[6];
};

//////////////////////////////////////////////////////
//////// Déclaration des méthodes / fonctions ////////
//////////////////////////////////////////////////////
// Méthodes
// Initialization
void initDe(dice *de);
void initPartie(listeJoueurs *listeJoueurs, pileCartes *pioche);
void initPioche(pileCartes *pioche);
void initListeCarte(joueur *joueur, pileCartes *pioche);
void ajoutFirstCarteJoueur(joueur *joueur, pileCartes *pioche);
// Méthode tour
void tour();
// Méthodes Dé
void lancerDe(dice de, int des[24]);
void afficherDe(int face);
// Méthodes Cartes
void selectionCarte(joueur *joueur, pileCartes *pioche);
void utilisationCarte(carte *carte, joueur *joueur, pileCartes *pioche);
void empileCarte(pileCartes *pioche, int cout, int index, char effet[], char titre[]);
void selectCarteEmpiler(int index, pileCartes *pioche);
void ajoutCarteJoueur(joueur *joueur, pileCartes *pioche);
// Méthodes Joueurs
void ajouterJoueur(listeJoueurs *listeJoueurs, int nbJ, pileCartes *pioche);
void afficherJoueurs(listeJoueurs *listeJoueurs, int nbJ);
// FOR TEST
void test();

// Effets de cartes
// Suppression de dés
void supprimerDe(int *deJoueur[]);
void supprimer1De(int *deJoueur[]);
void supprimer2De(int *deJoueur[]);

// Fonctions
// Fonctions Dé
int retourneSommeWazabi(int des[24]);

// Fonctions générales
int scanfByRomeo(char *chaine, int taille);
void viderBuffer();