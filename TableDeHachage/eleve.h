#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100

typedef struct Eleve Eleve;
struct Eleve {
	char prenom[50];
	char nom[50];
	int age;
	char sexe[50];
	double moyenne;
};

typedef struct TableHachage TableHachage;
struct TableHachage {
	int taille;
	Eleve* table[TAILLE];
};


int hachage(const char *chaine);
Eleve *creerEleve(const char *prenom, const char *nom, int age, const char *sexe, double moyenne);
void initialiserTableHachage(TableHachage *table);
void ajouterEleve(TableHachage *table, Eleve *eleve);
Eleve *rechercherTableHachage(TableHachage *tableau, char *chaine);




// Fonction de hachage
int hachage(const char *chaine) {
	
	int i = 0, nombreHache = 0;

	for (i = 0; chaine[i] != '\0'; i++) {
		nombreHache += chaine[i];
	}

	nombreHache %= 100;
	
	return nombreHache;
}

// Fonction pour créer un élève
Eleve *creerEleve(const char *prenom, const char *nom, int age, const char *sexe, double moyenne) {

	Eleve *eleve = malloc(sizeof(Eleve));

	if (eleve == NULL) {
		exit(1);
	}

	strcpy_s(eleve -> prenom, sizeof(eleve -> prenom), prenom);
	strcpy_s(eleve -> nom, sizeof(eleve -> nom), nom);
	eleve -> age = age;
	strcpy_s(eleve -> sexe, sizeof(eleve -> sexe), sexe);
	eleve -> moyenne = moyenne;

	return eleve;
}

// Fonction puor initialiser la table de hachage
void initialiserTableHachage(TableHachage *table) {
	table -> taille = TAILLE;
	for (int i = 0; i < TAILLE; i++) {
		table -> table[i] = NULL;
	}
}

// Fonction pour ajouter un élève dans la table de hachage
/*
* else {
		int i = 1;
		while (table -> table[index] != NULL) {
			index = (index + i) % TAILLE;
			i++;
		}
		table -> table[index] = eleve;
	}
Ce code est une implémentation de la gestion des collisions dans une table de hachage en utilisant la méthode du "probing linéaire".
*/
void ajouterEleve(TableHachage *table, Eleve *eleve) {

	char nomComplet[100];
	// Concaténer le prénom et le nom
	snprintf(nomComplet, sizeof(nomComplet), "%s %s", eleve -> prenom, eleve -> nom);
	
	int index = hachage(nomComplet);

	if (table -> table[index] == NULL) {
		table -> table[index] = eleve;
	} 
	else {
		int i = 1;
		while (table -> table[index] != NULL) {
			index = (index + i) % TAILLE;
			i++;
		}
		table -> table[index] = eleve;
	}
}

Eleve *rechercherTableHachage(TableHachage *tableau, char *chaine) {
	
	int index = hachage(chaine);
	
	if (tableau -> table[index] == NULL) {
		printf("\t Desole, Eleve dont le nom : {%s} non trouve.\n", chaine);
		return NULL;
	}
	
	return tableau -> table[index];;
}



