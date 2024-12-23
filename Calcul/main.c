#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
	
	int resultat = 0;
	int a = 5;
	int b = 3;
	printf("**************************** Addition *********************************\n");
	resultat = a + b;
	printf("5 + 3 = %d\n", resultat);

	printf("**************************** Multiplication *********************************\n");
	int resultat2 = a * b;
	printf("5 * 3 = %d\n", resultat2);

	printf("**************************** Division *********************************\n");
	int resultat3 = a / b;
	printf("5 / 3 = %d\n", resultat3);

	printf("**************************** Soustraction *********************************\n");
	int resultat4 = a - b;
	printf("5 - 3 = %d\n", resultat4);

	printf("**************************** Modulo *********************************\n");
	int resultat5 = a % b;
	printf("5 %% 3 = %d\n", resultat5);

	printf("**************************** Division avec nombres décimaux *********************************\n");

	double resultat6 = 5.0 / 2.0;
	printf("5.0 / 2.0 = %f\n", resultat6);

	printf("**************************** Calculatrice *********************************\n");
	int x, y;

	printf("Entrez deux nombres entiers x et y: \n");
	scanf_s("%d %d", &x, &y);

	printf("La sommes de deux entiers : %d + %d = %d\n", x, y, x + y);

	printf("******************************************** Raccourci des opérations ***********************************\n");
	int nombre = 2;

	nombre += 4; // nombre vaut 6...
	nombre -= 3; // ... nombre vaut maintenant 3
	nombre *= 5; // ... nombre vaut 15
	nombre /= 3; // ... nombre vaut 5
	nombre %= 3; // ... nombre vaut 2 (car 5 = 1 * 3 + 2)

	printf("Le nombre final est : %d\n", nombre); // Affiche 2


	printf("******************************************** Utilisation des fonctions des bibliotéques math.h ***********************************\n");

	double racine = sqrt(16);
	printf("La racine carrée de 16 est : %f\n", racine);
	
	int puissance = pow(2, 3);
	printf("2 puissance 3 est : %d\n", puissance);

	printf("******************************************** Incrémentation et Décrémentation ***********************************\n");
	int i = 0;
	i++; // i vaut maintenant 1
	printf("La valeur de i est : %d\n", i);

	i--; // i vaut maintenant 0
	printf("La valeur de i est : %d\n", i);
	
	return 0;
}