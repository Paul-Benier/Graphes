//  Initialisation.h

#ifndef Initialisation_h
#define Initialisation_h

#include "main.h"
int Initialisation(matrice matriceAdjacence, int nbligne, int nb);
int InitialisationTabContraintes(tableau tabContraintes, int nbligne, int nb);
int CopieTabContraintes(tableau tabContraintes, tableau tabContraintesBis, int nblignes, int tabnbparligne[40]);
int InitialisationTab(int tab[], int taille, int nb);
int CopieTab(int tabnbparligne[40], int tabnbparlignebis[40], int nblignes);

#endif /* Initialisation_h */
