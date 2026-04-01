#ifndef PLATEAU_H
#define PLATEAU_H

// plateau.h – Déclaration de la classe plateau (échiquier)
// La classe gère un plateau de jeu 8x8 et fournit des méthodes pour
// valider les déplacements des pièces d'échecs.
//
// Encodage des pièces dans plat[ligne][colonne] :
//   0   = case vide
//   Pièces blanches (valeurs positives) :
//     TOUR_B    = 1
//     CAVALIER_B= 2
//     FOU_B     = 3
//     DAME_B    = 4
//     ROI_B     = 5
//     PION_B    = 6
//   Pièces noires (valeurs négatives) :
//     TOUR_N    = -1
//     CAVALIER_N= -2
//     FOU_N     = -3
//     DAME_N    = -4
//     ROI_N     = -5
//     PION_N    = -6

// Pièces blanches
static const int TOUR_B     =  1;
static const int CAVALIER_B =  2;
static const int FOU_B      =  3;
static const int DAME_B     =  4;
static const int ROI_B      =  5;
static const int PION_B     =  6;

// Pièces noires
static const int TOUR_N     = -1;
static const int CAVALIER_N = -2;
static const int FOU_N      = -3;
static const int DAME_N     = -4;
static const int ROI_N      = -5;
static const int PION_N     = -6;

class plateau {
public:
    // Constructeur : initialise toutes les cases à 0 (vides)
    plateau();

    // Initialise le plateau dans la position de départ standard
    void initialiser();

    // Affiche le plateau dans la console
    void afficher() const;

    // Évalue si le déplacement d'une tour est valide.
    //
    // Une tour se déplace en ligne droite : horizontalement ou verticalement.
    // Elle ne peut pas sauter par-dessus d'autres pièces.
    //
    // Paramètres :
    //   ld – ligne  de départ  (0 à 7)
    //   cd – colonne de départ (0 à 7)
    //   la – ligne  d'arrivée  (0 à 7)
    //   ca – colonne d'arrivée (0 à 7)
    //
    // Retourne :
    //   1  si le chemin est libre (déplacement légal)
    //   0  si le chemin est bloqué ou si le déplacement n'est pas en ligne droite
    int evalTour(int ld, int cd, int la, int ca);

private:
    // Représentation du plateau : plat[ligne][colonne]
    // 0 = case vide, valeur non-nulle = pièce présente
    int plat[8][8];
};

#endif // PLATEAU_H
