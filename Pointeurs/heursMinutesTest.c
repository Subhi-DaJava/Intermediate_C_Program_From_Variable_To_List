#include <stdio.h>
#include <stdlib.h>

void decoupeMinutes(int, int);

int main() {

	int	heures = 0, minutes = 90;

	decoupeMinutes(heures, minutes);

	printf("Heures : %d, minutes : %d\n", heures, minutes);  // Attendu : heures = 1, minutes = 30

	printf("\n********************************** Afficher addresse Variable ************************************\n");

	int age = 10;
	printf("L'adresse de la variable age est : %p\n", &age); //le p du mot « pointeur »
	printf("La valeur de la variable age est : %d\n", age);

	// créer une variable de pointeur pour age 
	printf("\n********************************** Créer et Assigner pointeur ************************************\n");
	
	int *pointeurSurAge = &age;
	// afficher l'adresse de la variable age
	printf("L'adresse de la variable age est : %d\n", *pointeurSurAge); // 10
	
	return 0;
}

void decoupeMinutes(int minutes, int heures) {
	heures = minutes / 60;  // 1
	minutes = minutes % 60; // 30
}