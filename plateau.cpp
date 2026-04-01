// plateau.cpp – Implémentation de la classe plateau

#include "plateau.h"
#include <iostream>

// ─────────────────────────────────────────────────────────────────────────────
// Constructeur
// ─────────────────────────────────────────────────────────────────────────────

plateau::plateau()
{
    // Vide toutes les cases au départ
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            plat[i][j] = 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// initialiser – Position de départ standard (simplifié)
// ─────────────────────────────────────────────────────────────────────────────

void plateau::initialiser()
{
    // Pièces blanches (rangée 0)
    plat[0][0] = TOUR_B;      // Tour  blanche gauche
    plat[0][1] = CAVALIER_B;  // Cavalier blanc gauche
    plat[0][2] = FOU_B;       // Fou   blanc gauche
    plat[0][3] = DAME_B;      // Dame  blanche
    plat[0][4] = ROI_B;       // Roi   blanc
    plat[0][5] = FOU_B;       // Fou   blanc droit
    plat[0][6] = CAVALIER_B;  // Cavalier blanc droit
    plat[0][7] = TOUR_B;      // Tour  blanche droite

    // Pions blancs (rangée 1)
    for (int j = 0; j < 8; j++)
        plat[1][j] = PION_B;

    // Cases vides (rangées 2 à 5)
    for (int i = 2; i <= 5; i++)
        for (int j = 0; j < 8; j++)
            plat[i][j] = 0;

    // Pions noirs (rangée 6)
    for (int j = 0; j < 8; j++)
        plat[6][j] = PION_N;

    // Pièces noires (rangée 7)
    plat[7][0] = TOUR_N;      // Tour  noire gauche
    plat[7][1] = CAVALIER_N;  // Cavalier noir gauche
    plat[7][2] = FOU_N;       // Fou   noir gauche
    plat[7][3] = DAME_N;      // Dame  noire
    plat[7][4] = ROI_N;       // Roi   noir
    plat[7][5] = FOU_N;       // Fou   noir droit
    plat[7][6] = CAVALIER_N;  // Cavalier noir droit
    plat[7][7] = TOUR_N;      // Tour  noire droite
}

// ─────────────────────────────────────────────────────────────────────────────
// afficher – Affichage textuel du plateau
// ─────────────────────────────────────────────────────────────────────────────

void plateau::afficher() const
{
    std::cout << "  0 1 2 3 4 5 6 7\n";
    for (int i = 7; i >= 0; i--)
    {
        std::cout << i << " ";
        for (int j = 0; j < 8; j++)
            std::cout << plat[i][j] << " ";
        std::cout << "\n";
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// evalTour – Validation du déplacement d'une tour
// ─────────────────────────────────────────────────────────────────────────────
//
// Une tour se déplace uniquement en ligne droite (même ligne OU même colonne).
// Elle ne peut pas sauter par-dessus d'autres pièces.
//
// Cas 1 – Déplacement horizontal (même ligne : ld == la)
//   On vérifie que toutes les cases situées ENTRE cd et ca sur la ligne ld
//   sont vides (plat[ld][j] == 0).
//
// Cas 2 – Déplacement vertical (même colonne : cd == ca)
//   On vérifie que toutes les cases situées ENTRE ld et la sur la colonne cd
//   sont vides (plat[i][cd] == 0).
//
// Tout autre déplacement (diagonal, en L…) est illégal → retourne 0.
//
// Retourne 1 si le déplacement est légal, 0 sinon.
// ─────────────────────────────────────────────────────────────────────────────

int plateau::evalTour(int ld, int cd, int la, int ca)
{
    // ── Cas 1 : déplacement horizontal ──────────────────────────────────────
    if (ld == la)
    {
        // min et max délimitent l'intervalle des colonnes à vérifier
        int min = cd < ca ? cd : ca;
        int max = cd > ca ? cd : ca;

        // On inspecte les cases intermédiaires (min+1 à max-1 inclus)
        for (int j = min + 1; j < max; j++)
            if (plat[ld][j] != 0) return 0; // chemin bloqué

        return 1; // chemin libre
    }

    // ── Cas 2 : déplacement vertical ────────────────────────────────────────
    else if (cd == ca)
    {
        // min et max délimitent l'intervalle des lignes à vérifier
        int min = ld < la ? ld : la;
        int max = ld > la ? ld : la;

        // On inspecte les cases intermédiaires (min+1 à max-1 inclus)
        for (int i = min + 1; i < max; i++)
            if (plat[i][cd] != 0) return 0; // chemin bloqué

        return 1; // chemin libre
    }

    // ── Cas 3 : déplacement ni horizontal ni vertical ───────────────────────
    // La tour ne peut pas se déplacer en diagonale ou autrement → illégal
    return 0;
}
