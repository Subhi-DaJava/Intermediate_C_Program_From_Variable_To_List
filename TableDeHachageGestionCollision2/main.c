#include <stdio.h>
#include <stdlib.h>
#include "eleveGestionCollision2.h"

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
	Eleve *eleve1 = creerEleve("Julien", "Lefebvre", 21, "M", 14); // index 8
	Eleve *eleve2 = creerEleve("Aurelie", "Bassoll", 20, "F", 15); // index 3
	Eleve *eleve3 = creerEleve("Yann", "Martinez", 18, "M", 17); // index 0
	Eleve *eleve4 = creerEleve("Luc", "Doncieux", 18, "M", 11); // index 5
	Eleve *eleve5 = creerEleve("Marie", "Lefevre", 19, "F", 16); // index 9
	Eleve *eleve6 = creerEleve("Jean", "Dupont", 20, "M", 13); // index 8		
	Eleve *eleve7 = creerEleve("Marie", "Dupont", 20, "F", 13); // index 9

	// Ajout des élèves dans la table de hachage de taille 10
	printf("1.1. Ajout des eleves dans la table de hachage de taille 10 : \n");
	Eleve *eleve8 = creerEleve("Luc", "Donciuex", 20, "M", 13); // index 5
	Eleve *eleve9 = creerEleve("Anna", "Jaures", 20, "F", 15); // index 2
	Eleve * eleve10 = creerEleve("Sophie", "Bernard", 19, "F", 18); // index 0
	Eleve *eleve11 = creerEleve("Onze", "TROP", 21, "M", 11); // index 9
	Eleve *eleve12 = creerEleve("Bob", "MARTIN", 22, "M", 16); // index 6
	Eleve *eleve13 = creerEleve("Julien", "MORICE", 20, "M", 14); // index 4
	Eleve *eleve14 = creerEleve("Anaice", "THOMAS", 17, "F", 17); // index 9
	Eleve *eleve15 = creerEleve("Alice", "Martin", 18, "F", 18); // index 9
	Eleve *eleve16 = creerEleve("Claire", "Dubois", 19, "F", 19); // index 8

	// Depassement de la taille de la table de hachage, mais on peut ajouter l'eleve 17 dans la liste chainee à l'index 8
	Eleve *eleve17 = creerEleve("Claire", "CHAZELLE", 20, "F", 20); // index 8

	
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
	Eleve *eleveRechercheNo9Bis = rechercherTableHachage(table1, "Anna Jaures");
	printf("9. Afficher eleve Anna Jaures : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo9Bis -> nom, eleveRechercheNo9Bis -> prenom, eleveRechercheNo9Bis -> age,
		eleveRechercheNo9Bis -> sexe, eleveRechercheNo9Bis -> moyenne);

	//RAJOUTER L'ELEVE 10 Sophie Bernard
	ajouterEleve(table1, eleve10);
	Eleve *eleveRechercheNo10Bis = rechercherTableHachage(table1, "Sophie Bernard");
	printf("10. Afficher eleve Sophie Bernard : \n");
	printf("\t Nom: %s, Prenom: %s, Age: %d, Sexe: %s, Moyenne: %.2f\n",
		eleveRechercheNo10Bis -> nom, eleveRechercheNo10Bis -> prenom, eleveRechercheNo10Bis -> age,
		eleveRechercheNo10Bis -> sexe, eleveRechercheNo10Bis -> moyenne);

	//RAJOUTER L'ELEVE 11 
	printf("11. Test d'Ajout de l'eleve qui depasse la taille de la table de hachage: \n");
	ajouterEleve(table1, eleve11); 
	printf("11.1 La taille de la table de hachage: %d\n", table1 -> taille);
	
	printf("12. Test d'Ajout de l'eleve qui depasse la taille de la table de hachage: \n");
	ajouterEleve(table1, eleve12);
	printf("12.1 La taille de la table de hachage: %d\n", table1 -> taille);

	printf("13. Test d'Ajout de l'eleve qui depasse la taille de la table de hachage : \n");	
	ajouterEleve(table1, eleve13);
	printf("13.1 La taille de la table de hachage: %d\n", table1 -> taille);

	printf("14. Test d'Ajout de l'eleve qui depasse la taille de la table de hachage : \n");
	ajouterEleve(table1, eleve14);
	printf("14.1 La taille de la table de hachage: %d\n", table1 -> taille);

	printf("15. Test d'Ajout de l'eleve qui depasse la taille de la table de hachage : \n");
	ajouterEleve(table1, eleve15);
	printf("15.1 La taille de la table de hachage: %d\n", table1 -> taille);

	printf("16. Test d'Ajout de l'eleve qui depasse la taille de la table de hachage : \n");
	ajouterEleve(table1, eleve16);
	printf("16.1 La taille de la table de hachage: %d\n", table1 -> taille);

	int index1 = hachage("Julien Lefebvre");
	int index2 = hachage("Aurelie Bassoll");
	int index3 = hachage("Yann Martinez");
	int index4 = hachage("Luc Doncieux");
	int index5 = hachage("Marie Lefevre");
	int index6 = hachage("Jean Dupont");
	int index7 = hachage("Marie Dupont");
	int index8 = hachage("Luc Donciuex");
	int index9 = hachage("Anna Jaures");
	int index10 = hachage("Sophie Bernard");
	int index11 = hachage("Onze TROP");
	int index12 = hachage("Bob MARTIN");
	int index13 = hachage("Julien MORICE");
	int index14 = hachage("Anaice THOMAS");

	index1 = hachage("Julien Lefebvre");
	index2 = hachage("Aurelie Bassoll");
	index3 = hachage("Yann Martinez");
	index4 = hachage("Luc Doncieux");
	index5 = hachage("Marie Lefevre");
	index6 = hachage("Jean Dupont");
	index7 = hachage("Marie Dupont");
	index8 = hachage("Luc Donciuex");
	index9 = hachage("Anna Jaures");
	index10 = hachage("Sophie Bernard");
	index11 = hachage("Onze TROP");
	index12 = hachage("Bob MARTIN");
	index13 = hachage("Julien MORICE");
	index14 = hachage("Anaice THOMAS");

	printf("\n 15. Test de la fonction de hachage: \n");
	printf("\t15.1. Index de Julien Lefebvre: %d\n", index1);
	printf("\t15.2. Index de Aurelie Bassoll: %d\n", index2);
	printf("\t15.3. Index de Yann Martinez: %d\n", index3);
	printf("\t15.4. Index de Luc Doncieux: %d\n", index4);
	printf("\t15.5. Index de Marie Lefevre: %d\n", index5);
	printf("\t15.6. Index de Jean Dupont: %d\n", index6);
	printf("\t15.7. Index de Marie Dupont: %d\n", index7);
	printf("\t15.8. Index de Luc Donciuex: %d\n", index8);
	printf("\t15.9. Index de Anna Jaures: %d\n", index9);
	printf("\t15.10. Index de Sophie Bernard: %d\n", index10);
	printf("\t15.11. Index de Onze TROP: %d\n", index11);
	printf("\t15.12. Index de Bob MARTIN: %d\n", index12);
	printf("\t15.13. Index de Julien MORICE: %d\n", index13);
	printf("\t15.14. Index de Anaice THOMAS: %d\n", index14);

	printf("17. Test d'Ajout de l'eleve qui depasse la taille de la table de hachage, eleve17 sera rajoute dans l'index 8 : \n");
	ajouterEleve(table1, eleve17);
	printf("17.1 La taille de la table de hachage: %d\n", table1 -> taille);

	int index15 = hachage("Alice Martin");
	int index16 = hachage("Claire Dubois");
	int index17 = hachage("Claire CHAZELLE");

	printf("\t15. Index de Alice Martin: %d\n", index15); // index 9
	printf("\t16. Index de Claire Dubois: %d\n", index16); // index 8
	printf("\t17. Index de Claire CHAZELLE: %d\n", index17); // index 8

	// Libérer la mémoire allouée
	for (int i = 0; i < TAILLE; i++)
	{	
		Eleve *courant = table1 -> table[i];

		while (courant != NULL) {
			Eleve *temp = courant;
			courant = courant -> suivant;
			free(temp);
		}
	}

	free(table1);

	return 0;
}
