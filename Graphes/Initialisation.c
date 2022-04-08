//  Initialisation.c

#include "Initialisation.h"

int Initialisation(matrice matrice, int nbligne, int nb){
    for (int i=0 ; i<nbligne+2 ; i++){ // +2 si besoin de alpha et omega
        for (int j=0 ; j<nbligne+2 ; j++){
            matrice[i][j] = nb; // Initialisation de la matrice à nb
        }
    }
    return 0;
}

int InitialisationTabContraintes(tableau tabContraintes, int nbligne, int nb){
    for (int i=0 ; i<nbligne ; i++){
        for (int j=0 ; j<nbligne ; j++){
            tabContraintes[i][j] = nb; // Initialisation de la matrice à nb
        }
    }
    return 0;
}

int CopieTabContraintes(tableau tabContraintes, tableau tabContraintesBis, int nblignes, int tabnbparligne[40]){
    for (int i=0 ; i<nblignes+2 ; i++) {
        for (int j=0 ; j<tabnbparligne[i] ; j++) {
            tabContraintesBis[i][j] = tabContraintes[i][j];
        }
    }
    return 0;
}

int InitialisationTab(int tab[], int taille, int nb){
    for (int i=0 ; i<taille ; i++) {
        tab[i] = nb;
    }
    return 0;
}

int CopieTab(int tabnbparligne[40], int tabnbparlignebis[40], int nblignes){
    for (int i=0 ; i<nblignes+2 ; i++) {
        tabnbparlignebis[i] = tabnbparligne[i];
    }
    return 0;
}
