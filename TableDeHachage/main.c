#include <stdio.h>
#include <stdlib.h>
#include "eleve.h"

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
		eleveRechercheNo8 -> sexe, eleveRechercheNo8->moyenne);

	// Recherche d'un élève qui n'existe pas dans la table de hachage
	printf("7. Recherche d'un eleve qui n'existe pas dans la table de hachage\n");
	Eleve *eleveRechercheNo9 = rechercherTableHachage(table1, "Luc DoncieuxNotExisting");

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