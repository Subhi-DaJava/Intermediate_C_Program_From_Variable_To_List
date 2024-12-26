#include <stdio.h>
#include <stdlib.h>
#include "ListChainee.h"

int main() {

	// 1. On crée une liste, on l'initialise et on l'affiche.
	printf("\n\tCreation d'une liste, l'initialisation et l'affichage : \n");
	Liste *maListe = initialisation();

	insertion(maListe, 4);
	insertion(maListe, 8);
	insertion(maListe, 15);
	insertion(maListe, 16);
	insertion(maListe, 23);

	suppression(maListe);

	afficherListe(maListe); // Attendu : 16 -> 15 -> 8 -> 4 -> 0 -> NULL

	//2. On crée une liste, on l'initialise et on l'affiche avec insertion, suppression en milieu de liste, la taille de la liste et la suppression toute la liste.
	printf("\n\tCreation d'une liste, l'initialisation et l'affichage avec insertion, suppression en milieu de liste, la taille de la liste et la suppression toute la liste : \n");
	
	Liste *maListe2 = initialisation();
	insertion(maListe2, 4);
	insertion(maListe2, 8); // 8 -> 4 -> 0 ->  NULL
	
	printf("\t1. Taille de la liste : %d\n", maListe2 -> nbElements); // Attendu : 3
	afficherListe(maListe2); // Attendu : 8 -> 4 -> 0 -> NULL

	Element *position2 = maListe2 -> premier -> suivant;

	insertionMilieu(maListe2, 10, position2); // Attendu 8 -> 10 -> 4 -> 0 -> NULL
	printf("\t2. Taille de la liste : %d\n", maListe2 -> nbElements); // Attendu : 4
	afficherListe(maListe2); // Attendu : 8 -> 10 -> 4 -> 0 -> NULL

	insertion(maListe2, 16); // Attendu : 0 -> 16 -> 8 -> 10 -> 4 -> NULL
	afficherListe(maListe2);
	printf("\t3. Taille de la liste : %d\n", maListe2 -> nbElements); // Attendu : 5

	suppression(maListe2); // Attendu : 8 -> 10 -> 4 -> 0 -> NULL
	afficherListe(maListe2);
	printf("\t4. Taille de la liste : %d\n", maListe2 -> nbElements); // Attendu : 4

	insertion(maListe2, 23); // Attendu : 23 -> 8 -> 10 -> 4 -> 0 -> NULL
	afficherListe(maListe2);

	Element *position3 = maListe2 -> premier -> suivant -> suivant; 
	printf("\t4-1, avant de supprimer : Position 3 : la taille de liste2: %d\n", maListe2 -> nbElements); // Attendu :5
	afficherListe(maListe2); // Attendu : 23 -> 8 -> 10 -> 4 -> 0 -> NULL

	suppressionMilieu(maListe2, position3); // Attendu : 23 -> 8 -> 10 -> 0 -> NULL
	printf("\t4-2, apres supprimer : Position 3 : la taille de liste2:  %d\n", maListe2 -> nbElements); // Attendu : 4
	afficherListe(maListe2); // Attendu : 23 -> 8 -> 10 -> 0 -> NULL
	printf("\t4-3, apres avoir supprime : Position 3 : la taille de liste2:  %d\n", maListe2->nbElements); // Attendu : 4
	
	printf("\t5. Taille de la liste : %d\n", maListe2 -> nbElements); // Attendu : 3

	destructionListe(maListe2);

	if ((maListe2 -> premier == NULL) && (maListe2 -> nbElements == 0))
	{
		printf("\tLa liste a ete detruite.\n");
	}
	else
	{
		printf("\t6. La taille de lsite %d\n", maListe2 -> nbElements);
		printf("\t6-1. La liste n'a pas ete detruite.\n");
	}	

	free(maListe2); // Libérer la mémoire allouée pour la structure Liste

	return 0;
}