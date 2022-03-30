//  Lecture.c

#include "Lecture.h"

int LectureFichier(tableau tabContraintes, char nomFichier[100], int tabnbparligne[30], int *nbligne){
    FILE* fichier = NULL;
    int caractereActuel = 0;
    fichier = fopen(nomFichier, "r"); // On ouvre le fichier contenant le tableau de contraintes
    if (fichier != NULL){
        int nbparligne = 0; // Variable permettant de connaitre le nombre de nombre de chaque ligne
        caractereActuel = fgetc(fichier); // Lecture du premier caractère
        while (caractereActuel != EOF){ // EOF : caractère de fin de fichier
            if (caractereActuel == '\n'){ // Si le caractère lu est '\n' (un retour à la ligne)
                tabnbparligne[*nbligne] = nbparligne; // On entre le nombre de nombre de la ligne
                *nbligne += 1;
                nbparligne = 0;
                caractereActuel = fgetc(fichier); // Lecture du caractère suivant
            }
            else if (caractereActuel == ' '){ // Si le caractère lu est ' ' (un espace)
                caractereActuel = fgetc(fichier); // On l'ignore donc on lit le caractère suivant
            }
            else {
                int cara = caractereActuel - '0'; // Correction pour char --> int
                caractereActuel = fgetc(fichier); // Lecture du caractère suivant pour vérifier si c'est un chiffre ou un nombre
                while (caractereActuel != ' ' && caractereActuel != '\n' && caractereActuel != EOF){
                    cara = cara * 10 + (caractereActuel - '0'); // On prend les n chiffres que l'on concatène avec une opération mathématique
                    caractereActuel = fgetc(fichier); // Lecture du caractère suivant
                }
                tabContraintes[*nbligne][nbparligne] = cara; // On rentre le chiffre ou nombre à la suite
                nbparligne += 1;
            }
        }
        tabnbparligne[*nbligne] = nbparligne;
        *nbligne += 1;
     
        fclose(fichier);
    }
    return 0;
}
