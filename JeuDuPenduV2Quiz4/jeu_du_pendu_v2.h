#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAILLE_MOT 5

int tailleMot(char motSecret[]); // Prototype de la fonction tailleMot
void initTableau(int* lettreTrouvee, int tailleTableau); // Prototype de la fonction initTableau
int gagne(int* lettreTrouvee, int nombreLettres); // Prototype de la fonction gagne
char lireCaractere(); // Prototype de la fonction lireCaractere
int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee); // Prototype de la fonction rechercheLettre
void genererMotSecret(char* motSecret); // Prototype de la fonction genererMotSecret


/*
 * \brief Renvoie le nombre de lettres du mot
 * \param motSecret le mot dont on veut connaître le nombre de lettres
 * \return le nombre de lettres du mot
 */
int tailleMot(char motSecret[])
{
	/*int nombreLettres = 0;
	while (motSecret[nombreLettres] != '\0')
	{
		nombreLettres++;
	}
	return nombreLettres;*/

	int nombreLettres = 0;
	for (int i = 0; motSecret[i] != '\0'; i++)
	{
		nombreLettres++;
	}
	return nombreLettres;
}

/*
 * \brief Initialise un lettreTrouvee d'entiers à 0
 * \param lettreTrouvee le lettreTrouvee à initialiser
 * \param tailleTableau la taille du lettreTrouvee
 */
void initTableau(int* tableau, int tailleTableau)
{
	int i = 0;
	for (i = 0; i < tailleTableau; i++)
	{
		tableau[i] = 0;
	}
}


/*
 * \brief Vérifie si le joueur a gagné
 * \param lettreTrouvee le lettreTrouvee de lettres trouvées
 * \param nombreLettres le nombre de lettres du mot
 * \return 1 si le joueur a gagné, 0 sinon
 */

 /*
 Le lettreTrouvee lettreTrouvee permet de connaître chaque lettre trouvée dans le mot mystère.
 S’il reste encore une case qui a la valeur 0, alors la partie n’est pas encore gagnée.
 Dans ce cas, il faut vérifier chaque case du lettreTrouvee et si une case contient la valeur 0,
 on doit assigner la valeur 0 à la variable  joueurGagne
 */
int gagne(int* lettresTrouvees, int nombreLettres)
{
	int i = 0;
	int joueurGagne = 1;

	for (i = 0; i < nombreLettres; i++)
	{
		if (lettresTrouvees[i] == 0)
		{
			joueurGagne = 0;
		}
	}
	return joueurGagne;
}

/*
 * \brief Lit un caractère saisi par l'utilisateur
 * \return le caractère saisi par l'utilisateur
 */
char lireCaractere()
{
	char caractere = 0;

	caractere = getchar(); // On lit le premier caractère

	caractere = toupper(caractere); // On met la lettre en majuscule, si elle ne l'est pas déjà

	/*
	Ce code est souvent utilisé pour "vider" le tampon d'entrée,
	en particulier après avoir lu des entrées au clavier, pour s'assurer qu'aucun caractère indésirable
	(comme des caractères de nouvelle ligne laissés par un précédent scanf) ne reste dans le tampon d'entrée.
	Le point-virgule (;) à la fin indique que le corps de la boucle est vide.
	Cela signifie que la boucle ne fait rien d'autre que lire des caractères.
	*/
	while (getchar() != '\n'); // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)

	return caractere;
}

/*
 * \brief Recherche une lettre dans le motSecret
 * \param lettre la lettre à rechercher (proposée par l'utilisateur)
 * \param motSecret le mot dans lequel on recherche la lettre
 * \param lettreTrouvee le lettreTrouvee de lettres trouvées
 * \return 1 si la lettre a été trouvée, 0 sinon
 */

 /*
 On parcourt la chaîne  motSecret  caractère par caractère.
 À chaque fois, on vérifie si la lettre que le joueur a proposée est une lettre du mot. Si la lettre correspond, alors on fait deux choses :
 1. on change la valeur du booléen  bonneLettre  à 1, pour que la fonction retourne 1 car la lettre se trouvait effectivement dans motSecret ;
 2. on met à jour le lettreTrouvee lettreTrouvee à la position actuelle pour indiquer que cette lettre a été trouvée.
 */
int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee) {
	int i = 0, bonneLettre = 0;

	// On parcourt motSecret pour vérifier si la lettre proposée par l'utilisateur est présente
	for (i = 0; motSecret[i] != '\0'; i++)
	{
		if (lettre == motSecret[i]) // Si la lettre est présente dans le mot
		{
			lettreTrouvee[i] = 1; // On met à jour le lettreTrouvee de lettres trouvées
			bonneLettre = 1; // On met à jour la variable bonneLettre
		}
	}
	return bonneLettre;
}

/*
 * \brief Génère un mot aléatoire
 * \param motSecret le mot généré aléatoirement
 */
void genererMotSecret(char* motSecret) {
	// Liste de mots
	const char* mots[] = { "ROUGE", "JAUNE", "BLANC", "MAMAN", "EMAIL","PORTE", "SAIDA", "LUNDI" };

	// Nombre de mots dans la liste, ici 8
	// sizeof(mots) renvoie la taille en octets(total) de la liste de mots
	// sizeof(mots[0]) renvoie la taille en octets du premier mot de la liste
	int nombreMots = sizeof(mots) / sizeof(mots[0]);

	/*
	Dans le contexte de la fonction genererMotSecret,
	cette ligne de code est utilisée pour s'assurer que chaque fois que le programme est exécuté,
	un mot différent est potentiellement sélectionné de manière aléatoire.
	*/
	srand((unsigned int)time(NULL));// Initialiser le générateur de nombres aléatoires

	// rand() % nombreMots retourne un nombre entier compris entre 0 et nombreMots - 1.
	int index = rand() % nombreMots; // Sélectionner un index aléatoire
	//strcpy(motSecret, mots[index]); // Copier le mot sélectionné dans motSecret
	strcpy_s(motSecret, TAILLE_MOT + 1, mots[index]); // Copier le mot sélectionné dans motSecret
}
