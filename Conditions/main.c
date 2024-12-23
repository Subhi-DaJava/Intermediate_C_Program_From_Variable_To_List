#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int age = 18;

	age = 10;

	age = 5;

	age = 2;

	age = -1; 

	if (age >= 18) {

		printf("Vous êtes bien majeur !\n");
	}

	else if (age <= 10 && age >= 5) {

		printf("Vous êtes un enfant !\n");
	}

	else if (age < 5 && age >= 0) {

		printf("Vous êtes un bébé !\n");
	}

	else if (age < 0) {

		printf("L'age doit être plus grand que zéro !\n");
	}

	else {

		printf("Ops,vous êtes mineur !\n");
	}

	printf("******************************************** Testez plusieurs conditions à la fois ********************************************************\n");

	int age1 = 18;
	int argent = 10000;
	age1 = 17; // voir la ligne de code int autorisation = (age1 >= 18) ? 1 : 0;

	if (age1 >= 18 || argent >= 10000) {
		printf("Bienvenu chez LCL\n");
	}
	else {
		printf("Vous n'êtes pas le bienvenu chez LCL\n");
	}


	if (!(age1 > 18) && argent >= 20000) {
		printf("Bienvenu chez BNP\n");
	}
	else {
		printf("Vous n'êtes pas le bienvenu chez BNP\n");
	}

	if (!(age1 < 18)) { // Cela pourrait se traduire par « si la personne n'est pas mineure ».
		printf("Vous êtes majeur\n"); 
	}
	else {
		printf("Vous êtes mineur\n");
	}

	int majeur = 18;

	majeur = majeur >= majeur;

	printf("majeur = %d\n", majeur); // majeur = 1

	printf("********************************** Construisez un Switch ***************************************************\n");

	switch (age1)
	{
	case 2:
		printf("Salut bebe !");
		break;
	case 6:
		printf("Salut gamin !");
		break;
	case 12:
		printf("Salut jeune !");
		break;
	case 16:
		printf("Salut ado !");
		break;
	case 18:
		printf("Salut adulte !");
		break;
	case 68:
		printf("Salut papy !");
		break;
	default:
		printf("Je n'ai aucune reponse pour ton age");
		break;
	}


	printf("********************************************* Travail Pratique***********************************************\n");

	int choixMenu = 0;

	printf("=== Menu ===\n");
	printf("1. Royal Cheese\n");
	printf("2. Mc Deluxe\n");
	printf("3. Mc Bacon\n");
	printf("4. Big Mac\n");
	printf("\nVotre choix ?\n");

	scanf_s("%d", &choixMenu);

	switch (choixMenu)
	{
	case 1:
		printf("Tu as choisi le menu Royal Cheese !\n");
		break;
	case 2:
		printf("Tu as choisi le menu Mc Deluxe !\n");
		break;
	case 3:
		printf("Tu as choisi le menu Mc Bacon !\n");
		break;
	case 4:
		printf("Tu as choisi le menu Big Mac !\n");
		break;
	default:			
		printf("Je n'ai pas compris votre choix, saisir entre 1 et 4\n");
		break; // Le break est facultatif pour le dernier cas
	}

	printf("********************************************* Expression Ternaire ***********************************************\n");

	int autorisation = (age1 >= 18) ? 1 : 0;
	printf("autorisation = %d, parce que l'age égale %d", autorisation, age1);

	return 0;
}