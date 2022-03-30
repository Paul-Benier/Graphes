//  Verifications.c

#include "Verifications.h"

int VerifArcNegatif (tableau tabContraintes, int nbligne){
    int verifArcs = 1; // Initialisation à 1
    for (int i=0; i<nbligne; i++) {
        if (tabContraintes[i][1] < 0){
            verifArcs = 0; // 0 : Le graphe a donc au moins un arc négatif.
        }
    }
    return verifArcs;
}


int VerifPointEntree(matrice matrice, int nbligne, int tabEntree[nbligne+2]){
    int verifPe = 1;
    for (int rang=1 ; rang<nbligne+1 ; rang++){
        int verifColonne = 0; // Variable de vérification pour chaque colonne
        for (int ligne=1 ; ligne<nbligne+1 ; ligne++){
            if (matrice[ligne][rang] != 0){
                verifColonne += 1; // On incrémente quand une colonne a un prédécesseur (= pas entrée)
                tabEntree[ligne] = 0;
            }
        }
        if (verifColonne == 0){ // Cette colonne est une entrée
            verifPe += 1;
        }
    }
    if (verifPe != 1){
        verifPe = 0; // à plus ou moins d'une entrée donc NON VALIDE
    }
    return verifPe;
}


int VerifPointSortie(matrice matrice, int nbligne, int tabSortie[nbligne+2]){
    int verifPs = 1;
    for (int ligne=1 ; ligne<nbligne+1 ; ligne++){
        int verifLigne = 0; // Variable de vérification pour chaque ligne
        for (int rang=1 ; rang<nbligne+1 ; rang++){
            if (matrice[ligne][rang] != 0){
                verifLigne += 1; // On incrémente quand une ligne a un successeur (= pas de sortie)
                tabSortie[rang] = 0;
            }
        }
        if (verifLigne == 0){ // Cette colonne est une sortie
            verifPs += 1;
        }
    }
    if (verifPs != 1){
        verifPs = 0; // à plus ou moins d'une sortie donc NON VALIDE
    }
    return verifPs;
}
