//  Verifications.h

#ifndef Verifications_h
#define Verifications_h

#include "main.h"
int VerifCircuit(tableau tabContraintes, int nbligne, int tabnbparligne[40], int a, int w);
int VerifArcNegatif (tableau tabContraintes, int nbligne);
int VerifPointEntree(matrice matrice, int nbligne, int tabEntree[nbligne+2], int a, int w);
int VerifPointSortie(matrice matrice, int nbligne, int tabSortie[nbligne+2], int a, int w);

#endif /* Verifications_h */
