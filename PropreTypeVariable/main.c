#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coordonnees.h"
#include "personne.h"
#include "initialiserCoordonnees.h"
#include "volume.h"

int main() {
	
	//struct Personne person;
	Personne person;
	
	//struct Coordonnes point;
	Coordonnees point = { 0, 0 };

	// en lui donnant une abscisse de 10 et une ordonnée de 20. 
	point.x = 10;
	point.y = 20;

	printf("Les coordonnées du point sont : (x:%d, y:%d)\n", point.x, point.y);

	printf("\n**************************************** 1. Person ********************************************* ");

	printf("\nEntrez votre nom : ");
	scanf_s("%s", person.nom, (unsigned)_countof(person.nom));
	//scanf_s("%s", person.nom);

	printf("\nEntrez votre prenom : ");
	scanf_s("%s", person.prenom, (unsigned)_countof(person.prenom));
	//scanf_s("%s", person.prenom);

	printf("\nEntrez votre age : ");
	scanf_s("%d", &person.age);

	printf("\nEntrez votre sexe : ");
	scanf_s(" %c", &person.sexe, 1);

	printf("\nEtes-vous etudiant ? (1 pour oui, 0 pour non) : ");
	scanf_s("%d", &person.etudiant);

	printf("\nVous vous appelez %s %s, vous avez %d ans, vous etes de sexe %c et vous etes %s\n", person.nom, person.prenom, person.age, person.sexe, person.etudiant ? "etudiant" : "non etudiant");

	printf("\n**************************************** 2. Envoyer le variable personnalise dans la fonction initialiserCoordonnees ********************************************* ");
	
	Coordonnees point2;

	initialiserCoordonnees(&point2);

	printf("Les coordonnees du point sont : (x:%d, y:%d)\n", point2.x, point2.y);

	printf("\n**************************************** 3. Differences entre Raccourci et * sur un Pointeur de Structure ********************************************* ");

	Coordonnees monPoint;
	Coordonnees *monPointeurSurMonPoint = &monPoint;

	monPoint.x = 10;
	monPointeurSurMonPoint->y = 20;
	monPointeurSurMonPoint->x = 30;

	printf("Les coordonnees du point sont : (x:%d, y:%d)\n", monPoint.x, monPointeurSurMonPoint->y); // 30, 20

	printf("\n**************************************** 4. Declaration enumeration et assignation *********************************************\n ");

	//Volume volume = MOYEN;
	Volume volume = FORT;

	switch (volume) {

	case FAIBLE:
		printf("Le volume est faible\n");
		break;
		
	case MOYEN:
		printf("Le volume est moyen\n");
		break;
	
	case FORT: 
		printf("Le volume est fort\n");
		break;
	
	default:
		printf("Le volume est inconnu\n");
		break;
	}
	return 0;
}