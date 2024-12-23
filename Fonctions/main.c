#include<stdio.h>
#include<stdlib.h>


int triple(int x)
{
	return x * 3;
}

int addition(int x, int y)
{
	return x + y;
}

void print()
{
	printf("Hello C World!\n");
}

void punition(int nombreDeCopie) {
	
	for (int i = 0; i < nombreDeCopie; i++)
		printf("Je ne doit pas copier sur mon voisin, copie %d\n", i + 1);
}

void aireRectangle(double hauteur, double largeur) {
	double aire = hauteur * largeur;
	printf("Rectangle de largeur %f et hauteur %f. Aire = %f\n", largeur, hauteur, aire);
}

int menu() {

	int choix = 0;
	while (choix < 1 || choix > 4)
	{
		printf("Menu :\n");
		printf("1 : Poulet de dinde aux escargots rotis a la sauce bearnaise\n");
		printf("2 : Concombres sucres a la sauce de myrtilles enrobee de chocolat\n");
		printf("3 : Escalope de kangourou saignante et sa gelee aux fraises poivree\n");
		printf("4 : La surprise du Chef (j'en salive d'avance...)\n");
		printf("Votre choix ? ");
		scanf_s("%d", &choix);
	}

	return choix;
	
}



int main()
{
	int resulat = triple(5);
	printf("Result: %d\n", resulat);

	int resulat2 = addition(5, 5);
	printf("Result: %d\n", resulat2);

	print();
	
	int nombreEntre = 0, nombreTriple = 0;

	printf("Entrez un nombre... ");
	scanf_s("%d", &nombreEntre);

	nombreTriple = triple(nombreEntre);
	printf("Le triple de ce nombre est %d\n\n", nombreTriple);

	punition(10);

	aireRectangle(5.0, 10.0);
	aireRectangle(2.0, 3.0);
	aireRectangle(8.0, 4.0);


	printf("******************************************** Menu Fonction *********************************************************\n\n");

	switch (menu()) {
	case 1:
		printf("Vous avez choisi le Poulet de dinde aux escargots rotis a la sauce bearnaise\n");
		break;
	case 2:
		printf("Vous avez choisi les Concombres sucres a la sauce de myrtilles enrobee de chocolat\n");
		break;
	case 3:
		printf("Vous avez pris l'escalope\n");
		break;
	case 4:
		printf("Vous avez pris la surprise du Chef. Vous etes un sacre aventurier dites donc !\n");
		break;
	}
	
	return 0;
}