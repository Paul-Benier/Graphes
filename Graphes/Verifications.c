//  Verifications.c

#include "Verifications.h"
#include "Initialisation.h"
#include "Affichage.h"


int VerifCircuit (tableau tabContraintes, int nbligne, int tabnbparligne[40], int a, int w){
    tableau tabContraintesBis;
    InitialisationTabContraintes(tabContraintesBis, 40, 0);
    CopieTabContraintes(tabContraintes, tabContraintesBis, nbligne, tabnbparligne);
    int tabnbparlignebis[40];
    InitialisationTab(tabnbparlignebis, 40, 0);
    CopieTab(tabnbparligne, tabnbparlignebis, nbligne);
    printf("\n");
    int debut = 1;
    int fin = nbligne+1;
    if (a == 1){
        debut = 0;
    }
    if (w == 1){
        fin = nbligne+2;
    }
    int nbRang = nbligne+3;
    while (nbRang > 0){
        int nblignemax = 0;
        for (int i=debut ; i<fin ; i++){
            if (tabnbparlignebis[i] == 2){
                for (int j=debut ; j<fin ; j++){
                    for (int k=2 ; k<fin ; k++){
                        if (tabContraintesBis[j][k] == tabContraintesBis[i][0]) {
                            if (tabnbparlignebis[j] == 3){
                                if (tabContraintesBis[i][0] == 97){
                                    printf("Ligne %d rang %d j'ai trouvé 'a' que je 'supprime'\n", j, k);
                                }
                                else {
                                    printf("Ligne %d rang %d j'ai trouvé %d que je 'supprime'\n", j, k, tabContraintesBis[i][0]);
                                }
                                tabContraintesBis[j][k] = 0;
                                tabnbparlignebis[j]--;
                            }
                            else if (tabnbparlignebis[j] > 3){
                                printf("Ligne %d rang %d j'ai trouvé %d que je 'remplace' par la dernière valeur de la ligne %d\n", j, k, tabContraintesBis[i][0], tabContraintesBis[j][tabnbparlignebis[j]-1]);
                                tabContraintesBis[j][k] = tabContraintesBis[j][tabnbparlignebis[j]-1];
                                tabContraintesBis[j][tabnbparlignebis[j-1]] = 0;
                                tabnbparlignebis[j]--;
                            }
                        }
                    }
                }
            }
            else{
                nblignemax++;
            }
        }
        nbRang--;
        if (nblignemax == 0){
            nbRang = 0;
            return 1;
        }
    }
    AffichageTableau(tabContraintesBis, tabnbparlignebis, nbligne, a, w);
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
