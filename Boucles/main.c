#include<stdio.h>
#include<stdlib.h>

// Crée une méthode de taper un nombre entier tant que le nombre est 147, elle demande à l'utilisateur de rentrer/taper ce nombre précis
int main()
{
	printf("Bonjour, bienvenue dans le programme de test de la boucle while !\n\n");


	int nombre = 0;
	int compteur = 0;

	while (nombre != 147 && compteur < 5)
	{	
		compteur++;
		printf("Entrez le nombre 147 : \n");
		scanf_s("%d", &nombre);
	}

	if(compteur == 5) {
		printf("Vous avez échoué à rentrer le nombre 147 5 fois de suite !\n");
		return 1;
	}
	printf("Bravo, vous avez rentré le nombre 147 ! \n\n\t Vous avez réussi %d ème fois !\n\n", compteur);

	int compteur1 = 0;

	while (compteur1 < 10)
	{
		printf("La variable compteur vaut %d\n", compteur1);
		compteur1++;
	}

	printf("************************************************* Do while **************************************!\n");

	int compteur2 = 0;
	do {
		printf("La variable compteur vaut %d\n", compteur2);
		compteur2++;
	} while (compteur2 > 10);

	printf("************************************************* For **************************************!\n");

	for (int i = 0; i < 10; i++) {
		printf("La variable i vaut %d\n", i);
	}	

	return 0;
}