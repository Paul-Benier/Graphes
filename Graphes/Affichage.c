//  Affichage.c

#include "Affichage.h"

int AffichageTableau(tableau tabContraintes, int tabnbparligne[30], int *nbligne){
    for (int i=0 ; i<*nbligne ; i++){
        for (int j=0 ; j<tabnbparligne[i] ; j++){
            if (tabContraintes[i][j] < 10){
                printf(" "); // espace pour garder l'alignement
            }
            printf("%d ", tabContraintes[i][j]); // on affiche le nombre
        }
        printf("\n");
    }
    return 0;
}

int AffichageMatrice(matrice matriceAdjacence, tableau tabContraintes, int nbligne, int a, int w){
    printf ("   "); // espace pour garder l'alignement
    int debut = 1;
    if (a == 1){
        debut = 0;
        printf(" a ");
    }
    int fin = nbligne+1;
    if (w == 1){
        fin = nbligne+2;
    }
    for (int i=1 ; i<nbligne+1 ; i++){
        if (i<10){
            printf (" "); // espace pour garder l'alignement
        }
        printf ("%d", i);
        printf (" "); // espace entre les valeurs
    }
    if (w == 1){
        printf(" w");
    }
    printf("\n");
    // Affichage des lignes suivantes
    for (int i=debut ; i<fin ; i++){
        if (i == 0){
            printf (" a");
        }
        else if (i == nbligne+1){
            printf (" w");
        }
        else if (tabContraintes[i-1][0] < 10){
            printf (" "); // espace pour garder l'alignement
            printf("%d", tabContraintes[i-1][0]); // Affichage du numéro de sommet
        }
        else{
            printf("%d", tabContraintes[i-1][0]); // Affichage du numéro de sommet
        }
        for (int j=debut ; j<fin ; j++){
            printf (" "); // espace entre les valeurs
            if (matriceAdjacence[i][j] < 10){
                printf (" "); // espace pour garder l'alignement
            }
            if (matriceAdjacence[i][j] == 0){
                printf("."); // Le '.' correspond à '0' pour plus de lisibilité.
            }
            else{
                printf("%d", matriceAdjacence[i][j]); // Affichage de la valeur
            }
        }
        printf("\n");
    }
    return 0;
}
