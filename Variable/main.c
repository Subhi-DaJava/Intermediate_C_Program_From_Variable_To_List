#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int nombreDeVies, niveau, ageDuJoueur;

	nombreDeVies = 5; // Au départ, le joueur a 5 vies
	niveau = 1;
	ageDuJoueur = 17;

	const int NOMBRE_DE_VIES_INITIAL = 5;

	printf("Le joueur a %d vies et il est au niveau %d\n", nombreDeVies, niveau);
	printf("Le joueur a %d ans\n", ageDuJoueur);
	printf("Le joueur avait %d vies au debut du jeu\n", NOMBRE_DE_VIES_INITIAL);
		
	printf("******************************** Affichage  ***************************************** ****\n");

	printf("Vous avez %d vies\n", nombreDeVies);
	printf("**** B A M ****\n"); // Là il se prend un grand coup sur la tête
	nombreDeVies = 4; // Il vient de perdre une vie !
	printf("Ah desole, il ne vous reste plus que %d vies maintenant !\n\n", nombreDeVies);

	//NOMBRE_DE_VIES_INITIAL = 10; // Erreur de compilation

	printf("*********************************** Saisir  ******************************************\n");

	int age = 0;

	printf("Quel age avez-vous ? \n ");
	
	scanf_s("%d", &age);
	
	printf("Ah ! Vous avez donc %d ans\n\n", age);
	
	return 0;
}