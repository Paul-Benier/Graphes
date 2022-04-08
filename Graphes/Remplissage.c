//  Remplissage.c

#include "Remplissage.h"

int RemplissageMatrice(matrice matrice, tableau tabContraintes, int tabnbparligne[40], int nbligne, int choix){ // Choix 1 : Adjacence, Choix 2 : Valeurs
    for (int i=0 ; i<nbligne ; i++){
        if (tabnbparligne[i+1] > 2){
            for (int j=2 ; j<tabnbparligne[i+1] ; j++){
                int rang = tabContraintes[i+1][0]; // numéro de sommet
                int ligne = tabContraintes[i+1][j]; // prédécesseur du sommet
                if (choix == 1){
                    matrice[ligne][rang] = 1;
                }
                else if (choix == 2){
                    matrice[ligne][rang] = tabContraintes[ligne][1]; // = valeur de l'arete
                }
            }
        }
    }
    return 0;
}

int CorrectionMatrice(matrice matrice, tableau tabContraintes, int tabnbparligne[40], int nbligne, int choix, int tabEntree[nbligne+2], int tabSortie[nbligne+2]){ // Choix 1 : Adjacence, Choix 2 : Valeurs
    for (int i=1 ; i<nbligne+1 ; i++){
        if (tabSortie[i] == 0){
            if (choix == 1){
                matrice[0][i] = 1;
            }
            else{
                matrice[0][i] = 0;
            }
        }
        if (tabEntree[i] == 0){
            if (choix == 1){
                matrice[i][nbligne+1] = 1;
            }
            else{
                matrice[i][nbligne+1] = tabContraintes[i-1][1];
            }
        }
    }
    return 0;
}


int CorrectionTab(matrice matriceAdj, tableau tabContraintes, int tabnbparligne[40], int nbligne, int a, int w){
    int debut = 1;
    int fin = nbligne+1;
    if (a == 1){
        debut = 0;
        tabContraintes[0][0] = 'a';
        tabContraintes[0][1] = 0;
        tabnbparligne[0] = 2;
    }
    if (w == 1){
        fin = nbligne+2;
        tabContraintes[nbligne+1][0] = 'w';
        tabContraintes[nbligne+1][1] = 0;
        tabnbparligne[nbligne+1] = 2;
    }
    if (a == 1) {
        for (int i=debut ; i<fin ; i++){
            if (matriceAdj[0][i] == 1){
                tabnbparligne[i] += 1;
                tabContraintes[i][tabnbparligne[i]-1] = 'a';
            }
        }
    }
    if (w == 1){
        for (int i=debut ; i<fin ; i++){
            if (matriceAdj[i][nbligne+1] == 1){
                tabContraintes[nbligne+1][tabnbparligne[nbligne+1]] = i;
                tabnbparligne[nbligne+1] += 1;
            }
        }
    }
    return 0;
}
