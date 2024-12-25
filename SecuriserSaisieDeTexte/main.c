#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lire(char *chaine, int longueur);
int lireAvecViderBuffer(char *chaine, int longueur);
void viderBuffer();
long lireLong();
double lireDouble();

int main() {
	// 1. Declare une chaine de caracteres de taille 20 et saisissez une chaine de caracteres le nom: Jean Dupont avec un espace

	
	char nom[30];

	printf("Quel est votre nom ? \n");

	scanf_s("%s\n", nom, sizeof(nom));

	printf("Bonjour %s\n", nom); // Afficher le nom saisi: Jean mais sans Dupont car scanf s'arrete au premier espace

	// 2. Saisir et récuperer avec fgets une chaine de caracteres

	char prenom[20];

	printf("\nQuel est votre prenom ? \n");

	fgets(prenom, sizeof(prenom), stdin);

	printf("Bonjour %s !\n", prenom); // Afficher le prenom saisi: Jean Dupont

	// 3. Eliminer le caractere de retour a la ligne et remplacer par '\0'

	char name[20];

	printf("Quel est votre nom ? \n");

	
	lire(name, 20);

	printf("Bonjour %s !\n", name);


	// 4. Afficher le nom saisi: Jean Dupont plus long plus possible mais avec un buffer de 10
	char nomPlusLong[10];

	printf("Quel est votre nom ? \n");

	lire(nomPlusLong, 10);

	printf("Bonjour %s !\n", nomPlusLong);

	// 5. Afficher le nom resté dans la zone buffer: ont plus long plus possible mais avec un buffer de 10
	printf("Quel est votre nom ? \n");
	lire(nomPlusLong, 10);
	printf("Bonjour %s !\n", nomPlusLong);


	// 6. Saisir une chaine de caracteres avec fgets et vider le buffer 

	/*char nomPlusLongAvecViderBuffer[10];
	printf("Quel est votre nom ? \n");
	lireAvecViderBuffer(nomPlusLongAvecViderBuffer, 10);

	printf("Bonjour %s !\n", nomPlusLongAvecViderBuffer);
	
	printf("Quel est votre nom ? \n");
	lireAvecViderBuffer(nomPlusLongAvecViderBuffer, 10);*/

	// 7. Saisir un nombre entier avec fgets et convertir en long

	long age = 0;

	printf("Quel est votre age ? \n");
	age = lireLong();

	printf("Vous avez %d ans !\n", age);


	// 8. Saisir un nombre decimal avec fgets et convertir en double

	double taille = 0;

	printf("Quelle est votre taille ? \n");
	taille = lireDouble();

	printf("Vous mesurez %.3f m !\n", taille);


	return 0;
}

int lire(char *chaine, int longueur) {
	
	char *positionToucheEntree = NULL;

	if (fgets(chaine, longueur, stdin) != NULL) {

		positionToucheEntree = strchr(chaine, '\n');

		if (positionToucheEntree != NULL) {
			
			*positionToucheEntree = '\0';
		}
		return 1;
	}
	else
	{
		printf("Erreur: Buffer Overflow or other error !\n");
		return 0;
	}
}

int lireAvecViderBuffer(char *chaine, int longueur) {
	char* positionToucheEntree = NULL;

	if (fgets(chaine, longueur, stdin) != NULL) {

		positionToucheEntree = strchr(chaine, '\n');

		if (positionToucheEntree != NULL) {
			*positionToucheEntree = '\0';
		} 
		else
		{
			viderBuffer();
		}
		return 1;
	}
	else
	{
		printf("Erreur: Buffer Overflow or other error !\n");
		viderBuffer();
		return 0;
	}
}

void viderBuffer() {
	int c = 0;
	while (c != '\n' && c != EOF) {
		c = getchar();
	}
}

long lireLong() {

	char nombreTextes[100] = { 0 };

	if (lireAvecViderBuffer(nombreTextes,100)) {
		
		return strtol(nombreTextes, NULL, 10);
	}
	else
	{
		return 0;

	}

}

double lireDouble() {
	
	char *positionPoint = NULL;

	char nombreTextes[100] = { 0 };

	if (lireAvecViderBuffer(nombreTextes, 100)) {
	
		positionPoint = strchr(nombreTextes, ',');
		
		if (positionPoint != NULL)
		{
			*positionPoint = '.';
		}

		return strtod(nombreTextes, NULL);
	}
	else
	{
		return 0;
	}
}