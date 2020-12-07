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
    int nb;
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

//////////////////////
////// Méthodes //////
//////////////////////
// Méthodes initialization
void initDe(dice *de);
void initPartie(listeJoueurs *listeJoueurs, pileCartes *pioche);
void initPioche(pileCartes *pioche);
void initListeCarte(joueur *joueur, pileCartes *pioche);
void ajoutFirstCarteJoueur(listeCartes *listecarte, pileCartes *pioche);

// Méthode tour
void tour();

// Méthodes Dé
void lancerDe(dice de, int des[24]);
void afficherDe(int face);
void ajouterDe(int deJoueur[]);

// Méthodes Cartes
void utilisationCarte(joueur *joueur, pileCartes *pioche, listeJoueurs *listeJoueurs, int sens, pileCartes *defausse, int nbWJoueur);
void empileCarte(pileCartes *pioche, int cout, int index, char effet[], char titre[]);
void selectCarteEmpiler(int index, pileCartes *pioche);
void ajoutCarteJoueur(listeCartes *listecarte, carte *carte);
void transfertCarteJoueur(listeCartes *listecarteEmetteur, listeCartes *listecarteRecepteur, int index);
void transfertCarteDefausse(listeCartes *listeCartes, pileCartes *defausse, int index);
void ChangementSens(int sens);
void piochez3Cartes(joueur *joueur, pileCartes *pioche);

// Méthodes Joueurs
void ajouterJoueur(listeJoueurs *listeJoueurs, pileCartes *pioche);
void afficherJoueurs(listeJoueurs *listeJoueurs);

// Effets de cartes
// Suppression de dés
void supprimerDe(int deJoueur[]);
void supprimer1De(int deJoueur[]);
void supprimer2Des(int deJoueur[]);
// Donne De
void donner1De(joueur *joueur, listeJoueurs *listeJoueurs);
void transfertDe(int deJoueurEmetteur[], listeJoueurs *listeJoueurs);
// Switch Dés
void switchDes(listeJoueurs *listeJoueurs);
// Joueur 1 carte
void joueur1Carte(listeJoueurs *listeJoueurs, pileCartes *defausse);
// Prendre 1 carte
void prendre1Carte(listeJoueurs *listeJoueurs, joueur *joueur);
// Supprimer Joueur 2 cartes
void supprimerJoueur2Cartes(listeJoueurs *listeJoueurs, joueur *joueurCourant, pileCartes *defausse);
// Skip Joueur
void skipJoueur(joueur * joueurCourant);

// Méthodes générales
void viderBuffer();

/////////////////////////
/////// Fonctions ///////
/////////////////////////
// Fonctions Dé
int retourneSommeWazabi(int des[24]);
int retourneSommePioche(int des[24]);
int retourneSommeDonneDe(int des[24]);

// Fonctions Cartes
carte *selectionCarte(joueur *joueur, bool cache);
carte *piocheCarte(pileCartes *pioche);

// Fonctions générales
int scanfByRomeo(char *chaine, int taille);
int countDe(int des[24]);
bool verifFin(joueur *joueur);
joueur *selectionJoueur(listeJoueurs *listeJoueurs);