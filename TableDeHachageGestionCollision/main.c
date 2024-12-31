#include <stdio.h>
#include <stdlib.h>
#include "eleveGestionCollision1.h"

/*
Quand la fonction de hachage renvoie le même nombre pour deux clés différentes, on dit qu'il y a collision.
Dans notre cas, si nous avions un anagramme de Luc Doncieux qui s'appelle Luc Doncueix, 
la somme des lettres est la même, donc le résultat de la fonction de hachage sera le même !
1. La fonction de hachage n'est pas très performante. 
2. Le tableau dans lequel on stocke nos données est trop petit

Si une collision survient, pas de panique ! Deux solutions s'offrent à vous, au choix :
1. L'adressage ouvert.

2. Et le chaînage.

*/

int main() {

	TableHachage *table1 = malloc(sizeof(TableHachage));

	if (table1 == NULL) {
		exit(1);
	}

	initialiserTableHachage(table1);

	// Création des élèves
	printf("1. Creation des eleves: \n");
	Eleve *eleve1 = creerEleve("Julien", "Lefebvre", 21, "M", 14);
	Eleve *eleve2 = creerEleve("Aurelie", "Bassoll", 20, "F", 15);
	Eleve *eleve3 = creerEleve("Yann", "Martinez", 18, "M", 17);
	Eleve *eleve4 = creerEleve("Luc", "Doncieux", 18, "M", 11);
	Eleve *eleve5 = creerEleve("Marie", "Lefevre", 19, "F", 16);
	Eleve *eleve6 = creerEleve("Jean", "Dupont", 20, "M", 13);
	Eleve *eleve7 = creerEleve("Marie", "Dupont", 20, "F", 13);
	
	// Ajout des élèves dans la table de hachage de taille 10
	printf("1.1. Ajout des eleves dans la table de hachage de taille 10 : \n");
	Eleve *eleve8 = creerEleve("Luc", "Donciuex", 20, "M", 13);
	Eleve *eleve9 = creerEleve("Anna", "Jaures", 20, "F", 15);
	Eleve *eleve10 = creerEleve("Sophie", "Bernard", 19, "F", 18);
	Eleve *eleve11 = creerEleve("Onze", "TROP", 21, "M", 11);

	// Ajout des élèves dans la table de hachage
	printf("2. Ajout des eleves dans la table de hachage\n");
	ajouterEleve(table1, eleve1);
	ajouterEleve(table1, eleve2);
	ajouterEleve(table1, eleve3);
	ajouterEleve(table1, eleve4);
	ajouterEleve(table1, eleve5);
	ajouterEleve(table1, eleve6);
	ajouterEleve(table1, eleve7);

	// Recherche d'un élève dans la table de hachage
	printf("3. Recherche d'un eleve dans la table de hachage\n");

	Eleve *eleveRechercheNo1 = rechercherTableHachage(table1, "Julien Lefebvre");
	printf("4. Afficher eleve Julien Lefebvre : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo1 -> nom, eleveRechercheNo1 -> prenom, eleveRechercheNo1 -> age,
		eleveRechercheNo1 -> sexe, eleveRechercheNo1 -> moyenne);

	Eleve *eleveRechercheNo7 = rechercherTableHachage(table1, "Marie Dupont");
	printf("5. Afficher eleve Marie Dupont : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo7 -> nom, eleveRechercheNo7 -> prenom, eleveRechercheNo7 -> age,
		eleveRechercheNo7 -> sexe, eleveRechercheNo7 -> moyenne);

	Eleve *eleveRechercheNo8 = rechercherTableHachage(table1, "Luc Doncieux");
	printf("6. Afficher eleve Luc Doncieux : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo8 -> nom, eleveRechercheNo8 -> prenom, eleveRechercheNo8 -> age,
		eleveRechercheNo8 -> sexe, eleveRechercheNo8 -> moyenne);

	// Recherche d'un élève qui n'existe pas dans la table de hachage
	printf("7. Recherche d'un eleve qui n'existe pas dans la table de hachage\n");
	Eleve *eleveRechercheNo9 = rechercherTableHachage(table1, "Luc DoncieuxNotExisting");

	//RAJOUTER L'ELEVE 8 Luc Donciuex
	ajouterEleve(table1, eleve8);
	Eleve *eleveRechercheNo8Bis = rechercherTableHachage(table1, "Luc Donciuex");
	printf("8. Afficher eleve Luc Donciuex : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo8Bis -> nom, eleveRechercheNo8Bis -> prenom, eleveRechercheNo8Bis -> age,
		eleveRechercheNo8Bis -> sexe, eleveRechercheNo8Bis -> moyenne);

	//RAJOUTER L'ELEVE 9 Anna Jaures
	ajouterEleve(table1, eleve9);
	Eleve* eleveRechercheNo9Bis = rechercherTableHachage(table1, "Anna Jaures");
	printf("9. Afficher eleve Anna Jaures : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo9Bis -> nom, eleveRechercheNo9Bis -> prenom, eleveRechercheNo9Bis -> age,
		eleveRechercheNo9Bis -> sexe, eleveRechercheNo9Bis -> moyenne);

	//RAJOUTER L'ELEVE 10 Sophie Bernard
	ajouterEleve(table1, eleve10);
	Eleve* eleveRechercheNo10Bis = rechercherTableHachage(table1, "Sophie Bernard");
	printf("10. Afficher eleve Sophie Bernard : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo10Bis -> nom, eleveRechercheNo10Bis -> prenom, eleveRechercheNo10Bis -> age,
		eleveRechercheNo10Bis -> sexe, eleveRechercheNo10Bis -> moyenne);

	//RAJOUTER L'ELEVE 11 Onze TROP
	ajouterEleve(table1, eleve11); // Erreur : La table de hachage est complète, impossible d'ajouter l'élève.

	ajouterEleve(table1, eleve11); // Erreur : La table de hachage est complète, impossible d'ajouter l'élève.

	// Libérer la mémoire allouée
	for (int i = 0; i < TAILLE; i++)
	{
		if (table1 -> table[i] != NULL) {
			free(table1 -> table[i]);
		}
	}

	free(table1);

	return 0;
}