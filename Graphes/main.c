// main.c

#include "main.h"
#include "Lecture.h"
#include "Affichage.h"
#include "Initialisation.h"
#include "Remplissage.h"
#include "Verifications.h"

int main(int argc, const char * argv[]) {
    int utilisateur = 1;
    while (utilisateur == 1){
        
        //  ########################################
        //  | LECTURE ET RANGEMENT DANS LA MEMOIRE |
        //  ########################################
        
        tableau tabContraintes;
        char nomFichier[100] = "/Users/paul/Théorie des graphes/Graphes/C01.txt";
        int tabnbparligne[40]; // Tableau permettant de connaitre le nombre de nombre de chaque ligne
        InitialisationTab(tabnbparligne, 40, 0);
        int nbligne = 0; // Variable permettant de connaitre le nombre de ligne
        int a = 0; // variable alpha si besoin
        int w = 0; // variable omega si besoin
        
        
        LectureFichier(tabContraintes, nomFichier, tabnbparligne, &nbligne);
    
        //  #######################################
        //  | AFFICHAGE DU TABLEAU DE CONTRAINTES |
        //  #######################################
        
        printf("\nTableau de contraintes :\n");
        AffichageTableau(tabContraintes, tabnbparligne, nbligne, a, w);

        //  ########################################################
        //  | CREATION ET INITIALISATION DE LA MATRICE D'ADJACENCE |
        //  ########################################################

        matrice matriceAdjacence;
        Initialisation(matriceAdjacence, nbligne, 0);

        //  #########################################
        //  | REMPLISSAGE DE LA MATRICE D'ADJACENCE |
        //  #########################################

        RemplissageMatrice(matriceAdjacence, tabContraintes, tabnbparligne, nbligne, 1); // 1 : Adjacence

        //  #######################################
        //  | AFFICHAGE DE LA MATRICE D'ADJACENCE |
        //  #######################################

        printf("\nMatrice d'Adjacence :\n");
        AffichageMatrice(matriceAdjacence, tabContraintes, nbligne, a, w);

        //  #######################################################
        //  | CREATION ET INITIALISATION DE LA MATRICE DE VALEURS |
        //  #######################################################

        matrice matriceValeurs; // Création de la matrice des valeurs
        Initialisation(matriceValeurs, nbligne, 0);

        //  ########################################
        //  | REMPLISSAGE DE LA MATRICE DE VALEURS |
        //  ########################################

        RemplissageMatrice(matriceValeurs, tabContraintes, tabnbparligne, nbligne, 2); // 2 : Valeurs

        //  ######################################
        //  | AFFICHAGE DE LA MATRICE DE VALEURS |
        //  ######################################

        printf("\nMatrice des Valeurs :\n");
        AffichageMatrice(matriceValeurs, tabContraintes, nbligne, a, w);

        //  ###########################
        //  | VERIFICATIONS DU GRAPHE |
        //  ###########################

        /* Vérifications à faire :
            --> "Un seul point d’entrée"
            --> "Un seul point de sortie"
            --> "Pas de circuit"
            --> "Valeurs identiques pour tous les arcs incidents vers l’extérieur à un sommet"
            --> "Arcs incidents vers l’extérieur au point d’entrée ont une valeur nulle"
            --> "Pas d’arcs à valeur négative"
        */

        int verifValIdentique = 1; // "Valeurs identiques pour tous les arcs incidents vers l’extérieur à un sommet" Obligatoirement correct par rapport à ce que l'on nous donne
        int verifArcsIncidents = 1; // "Arcs incidents vers l’extérieur au point d’entrée ont une valeur nulle" Obligatoirement correct par rapport à ce que l'on nous donne car nous allons les créer en respectant ces règles si besoin
        int verifArcsNegatif = 1; // "Pas d’arcs à valeur négative"
        int verifPe = 1; // "Un seul point d’entrée"
        int verifPs = 1; // "Un seul point de sortie"
        int verifCircuit = 1; // "Pas de circuit"
        // 1 (Valide) et 0 (Non valide)
        int tabEntree[nbligne+2];
        int tabSortie[nbligne+2];
        

        // Vérification : "Valeurs identiques pour tous les arcs incidents vers l’extérieur à un sommet"
        printf("\nValeurs identiques pour tous les arcs incidents vers l’extérieur à un sommet : ");
        if (verifValIdentique == 0){
            printf("NON VALIDE ! ! !\n");
        }
        else{
            printf("VALIDE\n");
        }

        // Vérification : "Arcs incidents vers l’extérieur au point d’entrée ont une valeur nulle"
        printf("\nArcs incidents vers l’extérieur au point d’entrée ont une valeur nulle : ");
        if (verifArcsIncidents == 0){
            printf("NON VALIDE ! ! !\n");
        }
        else{
            printf("VALIDE\n");
        }

        // Vérification : "Pas d’arcs à valeur négative"
        verifArcsNegatif = VerifArcNegatif(tabContraintes, nbligne);
        printf("\nPas d’arcs à valeur négative : ");
        if (verifArcsNegatif == 0){
            printf("NON VALIDE ! ! !\n");
        }
        else{
            printf("VALIDE\n");
        }

        // Vérification : "Un seul point d’entrée"
        verifPe = VerifPointEntree(matriceAdjacence, nbligne, tabEntree, a, w);
        printf("\nUn seul point d’entrée : ");
        if (verifPe == 0){
            printf("NON VALIDE ! ! !\n");
            a = 1;
        }
        else{
            printf("VALIDE\n");
        }

        // Vérification : "Un seul point de sortie"
        verifPs = VerifPointSortie(matriceAdjacence, nbligne, tabSortie, a, w);
        printf("\nUn seul point de sortie : ");
        if (verifPs == 0){
            printf("NON VALIDE ! ! !\n");
            w = 1;
        }
        else{
            printf("VALIDE\n");
        }
        
        if (verifPe == 0 || verifPs == 0){
            printf("\nCorrection des matrices :\n");
            Correction(matriceAdjacence, tabContraintes, tabnbparligne, nbligne, 1, tabEntree, tabSortie, a, w);
            Correction(matriceValeurs, tabContraintes, tabnbparligne, nbligne, 2, tabEntree, tabSortie, a, w);
            
            printf("\nMatrice d'Adjacence avec a et w :\n");
            AffichageMatrice(matriceAdjacence, tabContraintes, nbligne, a, w);
            printf("\nMatrice des Valeurs avec a et w :\n");
            AffichageMatrice(matriceValeurs, tabContraintes, nbligne, a, w);
            
            // Vérification : "Un seul point d’entrée"
            verifPe = VerifPointEntree(matriceAdjacence, nbligne, tabEntree, a, w);
            printf("\nUn seul point d’entrée : ");
            if (verifPe == 0){
                printf("NON VALIDE ! ! !\n");
                a = 1;
            }
            else{
                printf("VALIDE\n");
            }

            // Vérification : "Un seul point de sortie"
            verifPs = VerifPointSortie(matriceAdjacence, nbligne, tabSortie, a, w);
            printf("\nUn seul point de sortie : ");
            if (verifPs == 0){
                printf("NON VALIDE ! ! !\n");
                w = 1;
            }
            else{
                printf("VALIDE\n");
            }
        }
        
        // Vérification : "Pas de circuit"
        verifCircuit = VerifCircuit(tabContraintes, nbligne, tabnbparligne);
        printf("\nPas de circuit : ");
        if (verifCircuit == 0){
            printf("NON VALIDE ! ! !\n");
        }
        else{
            printf("VALIDE\n");
        }
        
        printf("\n\n\n");
        printf("tabEntree : ");
        for (int i=0 ; i<nbligne+2 ; i++) {
            printf("%d ", tabEntree[i]);
        }
        printf("\n\n");
        printf("tabSortie : ");
        for (int i=0 ; i<nbligne+2 ; i++) {
            printf("%d ", tabSortie[i]);
        }
        printf("\n\n\n");

        printf("\n");
        //printf("Voulez-vous continuer ? Tapez 1 pour continuer : ");
        //scanf("%d", &utilisateur);
        utilisateur = 0;
    }
    //printf("\n\n");
    //printf("  ------------------------------\n");
    //printf("  | Le programme est terminé ! |\n");
    //printf("  ------------------------------\n\n");
    return 0;
}
