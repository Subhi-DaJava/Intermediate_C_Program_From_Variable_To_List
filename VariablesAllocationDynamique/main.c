#include <stdio.h>
#include <stdlib.h>
#include "coordonnees.h"


int main() {
	//  1. Afficher la taille des types de données suivants : char, int, float, double

	printf("Taille de char : %d octets\n", sizeof(char));
	printf("Taille de int : %d octets\n", sizeof(int));
	printf("Taille de float : %d octets\n", sizeof(float));
	printf("Taille de double : %d octets\n", sizeof(double));


	//  2. Déclarer une variable de type Coordonnees et l'initialiser avec les valeurs x=3 et y=4

	Coordonnees c;
	c.x = 3;
	c.y = 4;

	printf("\nCoordonnees : x=%d, y=%d, taille: %d\n", c.x, c.y, sizeof(c));

	// 3. Creer une variable qui alloue la mémoire manuellement ( l’allocation dynamique)

	int *memoireAllouee = malloc(sizeof(int));

	if (memoireAllouee == NULL) {
		printf("Erreur lors de l'allocation de mémoire\n");
		exit(0);
	}

	printf("\n\nQuel age avez-vous ? \n");
	scanf_s("%d", memoireAllouee);

	printf("Vous avez %d ans\n", *memoireAllouee);

	free(memoireAllouee);

	// 4. La meme fonction qu on cree une variable

	int age = 0;

	printf("\n\nQuel age avez-vous ? \n");
	scanf_s("%d", &age);

	printf("Vous avez %d ans\n", age);

	// 5. Creer un tableau dont la taille est définie par une variable allocée dynamiquement en mémoire

	int nombres = 0;

	int *nombreAmis = NULL;

	nombreAmis = malloc(nombres * sizeof(int));

	if (nombreAmis == NULL) {
		printf("Erreur lors de l'allocation de mémoire\n");
		exit(0);
	}

	printf("Combien d'amis avez-vous ? \n");
	scanf_s("%d", &nombres);

	for (int i = 0; i < nombres; i++) {
		printf("Quel age a votre ami %d ? \n", i + 1);
		scanf_s("%d", &nombreAmis[i]);
	}

	for (int i = 0; i < nombres; i++) {
		printf("Votre ami %d a %d ans\n", i + 1, nombreAmis[i]);
	}

	//free(nombreAmis);

	// 6. Creer un tableau dont la taille est définie par une variable

	int nombreDAmis = 0, i = 0;
	int *ageAmis = NULL; // Ce pointeur va servir de tableau après l'appel du malloc

	// On demande le nombre d'amis à l'utilisateur
	printf("Combien d'amis avez-vous ? ");
	scanf_s("%d", &nombreDAmis);

	if (nombreDAmis > 0) // Il faut qu'il ait au moins un ami (je le plains un peu sinon :p)
	{
		ageAmis = malloc(nombreDAmis * sizeof(int)); // On alloue de la mémoire pour le tableau
		if (ageAmis == NULL) // On vérifie si l'allocation a marché ou non
		{
			exit(0); // On arrête tout
		}

		// On demande l'âge des amis un à un
		for (i = 0; i < nombreDAmis; i++)
		{
			printf("Quel age a l'ami numero %d ? ", i + 1);
			scanf_s("%d", &ageAmis[i]);
		}

		// On affiche les âges stockés un à un
		printf("\n\nVos amis ont les ages suivants :\n");
		for (i = 0; i < nombreDAmis; i++)
		{
			printf("%d ans\n", ageAmis[i]);
		}

		// On libère la mémoire allouée avec malloc, on n'en a plus besoin
		free(ageAmis);
	}

	return 0;

}