//  Affichage.c

#include "Affichage.h"

int AffichageTableau(tableau tabContraintes, int tabnbparligne[40], int nbligne, int a, int w){
    int debut = 1;
    int fin = nbligne+1;
    if (a == 1){
        debut = 0;
    }
    if (w == 1){
        fin = 0;
    }
    for (int i=debut ; i<fin ; i++){
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

int AffichageMatrice(matrice matrice, tableau tabContraintes, int nbligne, int a, int w){
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
        else if (tabContraintes[i][0] < 10){
            printf (" "); // espace pour garder l'alignement
            printf("%d", tabContraintes[i][0]); // Affichage du numéro de sommet
        }
        else{
            printf("%d", tabContraintes[i][0]); // Affichage du numéro de sommet
        }
        for (int j=debut ; j<fin ; j++){
            printf (" "); // espace entre les valeurs
            if (matrice[i][j] < 10){
                printf (" "); // espace pour garder l'alignement
            }
            if (matrice[i][j] == 0){
                printf("."); // Le '.' correspond à '0' pour plus de lisibilité.
            }
            else{
                printf("%d", matrice[i][j]); // Affichage de la valeur
            }
        }
        printf("\n");
    }
    return 0;
}
