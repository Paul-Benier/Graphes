//  Verifications.h

#ifndef Verifications_h
#define Verifications_h

#include "main.h"
int VerifArcNegatif (tableau tabContraintes, int nbligne);
int VerifPointEntree(matrice matrice, int nbligne, int tabEntree[nbligne+2]);
int VerifPointSortie(matrice matrice, int nbligne, int tabSortie[nbligne+2]);

#endif /* Verifications_h */
