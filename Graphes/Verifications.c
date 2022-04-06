//  Verifications.c

#include "Verifications.h"
#include "Initialisation.h"
#include "Affichage.h"


int VerifCircuit (tableau tabContraintes, int nbligne, int tabnbparligne[40]){
    tableau tabContraintesBis;
    InitialisationTabContraintes(tabContraintesBis, 40, 0);
    CopieTabContraintes(tabContraintes, tabContraintesBis, nbligne, tabnbparligne);
    AffichageTableau(tabContraintesBis, tabnbparligne, nbligne, 0, 0);
    return 0;
}

int VerifArcNegatif (tableau tabContraintes, int nbligne){
    int verifArcs = 1; // Initialisation à 1
    for (int i=0; i<nbligne; i++) {
        if (tabContraintes[i][1] < 0){
            verifArcs = 0; // 0 : Le graphe a donc au moins un arc négatif.
        }
    }
    return verifArcs;
}


int VerifPointEntree(matrice matrice, int nbligne, int tabEntree[nbligne+2], int a, int w){
    InitialisationTab(tabEntree, nbligne+2, 0);
    int verifPe = 0;
    int debut = 1;
    int fin = nbligne+1;
    if (a == 1){
        debut = 0;
    }
    if (w == 1){
        fin = nbligne+2;
    }
    for (int rang=debut ; rang<fin ; rang++){
        int verifColonne = 0; // Variable de vérification pour chaque colonne
        for (int ligne=debut ; ligne<fin ; ligne++){
            if (matrice[ligne][rang] != 0){
                verifColonne += 1; // On incrémente quand une colonne a un prédécesseur (= pas entrée)
                tabEntree[ligne] += 1;
            }
        }
        if (verifColonne == 0){ // Cette colonne est une entrée
            verifPe += 1;
        }
    }
    if (verifPe > 1){
        verifPe = 0; // à plus d'une entrée donc NON VALIDE
    }
    return verifPe;
}


int VerifPointSortie(matrice matrice, int nbligne, int tabSortie[nbligne+2], int a, int w){
    InitialisationTab(tabSortie, nbligne+2, 0);
    int verifPs = 0;
    int debut = 1;
    int fin = nbligne+1;
    if (a == 1){
        debut = 0;
    }
    if (w == 1){
        fin = nbligne+2;
    }
    for (int ligne=debut ; ligne<fin ; ligne++){
        int verifLigne = 0; // Variable de vérification pour chaque ligne
        for (int rang=debut ; rang<fin ; rang++){
            if (matrice[ligne][rang] != 0){
                verifLigne += 1; // On incrémente quand une ligne a un successeur (= pas de sortie)
                tabSortie[rang] += 1;
            }
        }
        if (verifLigne == 0){ // Cette colonne est une sortie
            verifPs += 1;
        }
    }
    if (verifPs > 1){
        verifPs = 0; // à plus d'une sortie donc NON VALIDE
    }
    return verifPs;
}
