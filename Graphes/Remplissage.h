//  Remplissage.h

#ifndef Remplissage_h
#define Remplissage_h

#include "main.h"
int RemplissageMatrice(matrice matriceAdjacence, tableau tabContraintes, int tabnbparligne[40], int nbligne, int choix);
int CorrectionMatrice(matrice matrice, tableau tabContraintes, int tabnbparligne[40], int nbligne, int choix, int tabEntree[nbligne+2], int tabSortie[nbligne+2]);
int CorrectionTab(matrice matriceAdj, tableau tabContraintes, int tabnbparligne[40], int nbligne, int a, int w);

#endif /* Remplissage_h */
