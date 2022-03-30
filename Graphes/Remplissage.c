//  Remplissage.c

#include "Remplissage.h"

int RemplissageMatrice(matrice matrice, tableau tabContraintes, int tabnbparligne[30], int nbligne, int choix){ // Choix 1 : Adjacence, Choix 2 : Valeurs
    for (int i=0 ; i<nbligne ; i++){
        if (tabnbparligne[i] > 2){
            for (int j=2 ; j<tabnbparligne[i] ; j++){
                int rang = tabContraintes[i][0]; // numéro de sommet
                int ligne = tabContraintes[i][j]; // prédécesseur du sommet
                if (choix == 1){
                    matrice[ligne][rang] = 1;
                }
                else if (choix == 2){
                    matrice[ligne][rang] = tabContraintes[i][1]; // = valeur de l'arete
                }
            }
        }
    }
    return 0;
}
