//  Initialisation.c

#include "Initialisation.h"

int Initialisation(matrice matriceAdjacence, int nbligne){
    for (int i=0 ; i<nbligne+2 ; i++){ // +2 si besoin de alpha et omega
        for (int j=0 ; j<nbligne+2 ; j++){
            matriceAdjacence[i][j] = 0; // Initialisation de la matrice à 0
        }
    }
    return 0;
}

int InitialisationTab(int tab[], int taille){
    for (int i=0 ; i<taille ; i++) {
        tab[i] = 1;
    }
    return 0;
}
