// main.cpp – Démonstration de plateau::evalTour
//
// Compile : g++ -o demo main.cpp plateau.cpp
// Exécute : ./demo

#include "plateau.h"
#include <iostream>

int main()
{
    plateau p;

    std::cout << "=== Test evalTour sur un plateau vide ===\n\n";

    // ── Déplacements horizontaux ─────────────────────────────────────────────

    // Tour en (4,0) → (4,7) : chemin entièrement libre sur un plateau vide
    std::cout << "Horizontal libre  (4,0)→(4,7) : "
              << p.evalTour(4, 0, 4, 7) << "  (attendu : 1)\n";

    // ── Plateau initialisé (position de départ) ──────────────────────────────
    plateau standard;
    standard.initialiser();

    std::cout << "\n=== Plateau en position de départ ===\n\n";
    standard.afficher();
    std::cout << "\n";

    // La rangée 0 est entièrement occupée : la tour blanche (0,0) est bloquée
    // si elle essaie d'avancer vers (0,7).
    std::cout << "Horizontal bloqué (0,0)→(0,7) : "
              << standard.evalTour(0, 0, 0, 7)
              << "  (attendu : 0 — chemin bloqué par pièces en (0,1..6))\n";

    // Déplacement vertical : la tour (0,0) ne peut pas aller en (7,0) non plus.
    std::cout << "Vertical  bloqué  (0,0)→(7,0) : "
              << standard.evalTour(0, 0, 7, 0)
              << "  (attendu : 0 — chemin bloqué par pion en (1,0))\n";

    // Les rangées 2–5 sont vides : déplacement libre entre elles.
    std::cout << "Vertical  libre   (2,3)→(5,3) : "
              << standard.evalTour(2, 3, 5, 3)
              << "  (attendu : 1 — rangées 2-5 vides)\n";

    // Mouvement diagonal : toujours illégal pour une tour.
    std::cout << "Diagonal  illégal (3,3)→(5,5) : "
              << standard.evalTour(3, 3, 5, 5)
              << "  (attendu : 0 — une tour ne se déplace pas en diagonale)\n";

    return 0;
}
