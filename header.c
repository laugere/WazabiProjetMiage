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
    carte *courante;
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
void initPartie(listeJoueurs *listeJoueur);
void initPioche(pileCartes *pioche);
// Méthodes Dé
void afficherDe(int face);
// Méthodes Cartes
void selectionCarte(joueur *joueur, pileCartes *pioche);
void utilisationCarte(carte *carte, joueur *joueur, pileCartes *pioche);
void empileCarte(pileCartes *pioche, int cout, int index, char effet[], char titre[]);
void selectCarteEmpiler(int index, pileCartes *pioche);
// Méthodes Joueurs
void ajouterJoueur(listeJoueurs *listeJoueurs, int nbJ);
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
int lancerDe(dice de);
int retourneSommeWazabi(int face, int pointwazabi);

// Fonctions générales
int scanfByRomeo(char *chaine, int taille);
void viderBuffer();