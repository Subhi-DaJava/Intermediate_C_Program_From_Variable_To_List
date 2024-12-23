#include<stdio.h>
#include<stdlib.h>

// Prototype de la fonction
void afficherTableau(int* tableau, int tailleTableau);
void affiche(int tableau[], int tailleTableau);
int sommeTableau(int tableau[], int tailleTableau);
double moyenneTableau(int tableau[], int tailleTableau);

int main()
{
	// // Il existe une autre façon d'initialiser un tableau un peu plus automatisée en C. Elle consiste à écrire tableau[4] = {valeur1, valeur2, valeur3, valeur4}
	int tableau[6] = { 10, 20, 30, 40, 50, 60 }; 

	printf("tableau = %d\n", tableau); // Affiche l'adresse du tableau

	printf("tableau[0] = %d, addresses = %p, valeur[0]= %d\n", tableau[0], &tableau[0], *tableau); // Affiche la valeur de la première case du tableau

	printf("tableau addresse = %d\n", tableau);

	printf("tableau[1] = %d, addresses = %p, valeur[1]= %d\n", tableau[1], &tableau[1], *(tableau + 1)); // Affiche la valeur de la deuxième case du tableau

	printf("******************************** Afficher les elements du tableau avec for *******************************************\n");

	for (int i = 0; i < 6; i++)
	{
		printf("tableau[%d] = %d, addresses = %p, valeur[%d]= %d, addresse tableau=%d\n", i, tableau[i], &tableau[i], i, *(tableau + i), tableau);
	}

	printf("******************************** Initialisez un tableau *******************************************\n");

	int tableau2[6];

	for (int i = 0; i < 6; i++)
	{
		tableau2[i] = 0;
	}

	for ( int i = 0;  i < 6; i++)
	{
		printf("%d ", tableau2[i]);
	}

	printf("***************************************************** Initialiser un tableau automatise ******************************************************************\n"); 

	int tableau3[6] = {10, 23 };

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", tableau3[i]);
	}

	printf("***************************************************** Initialiser un tableau automatise, 0 ******************************************************************\n");

	int tableau4[6] = { 0 };
	
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", tableau4[i]);
	}

	printf("***************************************************** Declarer un tableau sans le nombre de taille ******************************************************************\n");

	int tableau5[] = { 10, 20, 30, 40, 50, 60 };

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", tableau5[i]);
	}

	printf("\n***************************************************** 1. Ecrivez une fonction pour afficher le contenu dun tableau (pointeur) ******************************************************************\n");

	afficherTableau(tableau5, 6);

	printf("\n***************************************************** 2. Ecrivez une fonction pour afficher le contenu dun tableau ******************************************************************\n");

	affiche(tableau5, 6);

	printf("\n***************************************************** TP: 1. some Tableau ******************************************************************\n");

	int tableau6[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("La somme du tableau6 est: %d\n", sommeTableau(tableau6, 10));

	printf("\n***************************************************** TP: 2. Moyenne Tableau ******************************************************************\n");

	printf("La moyenne du tableau6 est: %f\n", moyenneTableau(tableau6, 10));

	return 0;
}

void afficherTableau(int* tableau, int tailleTableau)
{
	for (int i = 0; i < tailleTableau; i++)
	{
		printf("%d ", tableau[i]);
	}
}

void affiche(int tableau[], int tailleTableau)
{
	for (int i = 0; i < tailleTableau; i++)
	{
		printf("%d ", tableau[i]);
	}
}
int sommeTableau(int tableau[], int tailleTableau) {
	int somme = 0;
	for (int i = 0; i < tailleTableau; i++) {
		somme += tableau[i];
	}
	return somme;
}

double moyenneTableau(int tableau[], int tailleTableau) {
	double somme = 0;
	for (int i = 0; i < tailleTableau; i++) {
		somme += tableau[i];
	}
	return (double)somme / (double)tailleTableau;
}