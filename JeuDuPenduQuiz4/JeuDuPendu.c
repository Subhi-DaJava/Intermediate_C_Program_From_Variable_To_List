#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JeuDuPendu.h"
#include <ctype.h>

int main(int argc, char* argv[])
{
	char lettre = 0; // Stocke la lettre proposée par l'utilisateur 

	// C'est le mot à découvrir, il est ici en clair pour l'instant, généré par l'ordinateur plus tard au hasard, 5 lettres max
	// TODO: générer un mot aléatoire avec le nombre de lettres souhaité
	char motSecret[] = "ROUGE";

	int coupsRestants = 10; // Compteur de coups restants (0 = perdu)

	int nombreLettres = tailleMot(motSecret); // Nombre de lettres du mot secret

	int *lettreTrouvee = NULL; // tableau de boolean, chaque case sera associée à une lettre trouvée ou non.  

	lettreTrouvee = malloc(nombreLettres * sizeof(int)); // Allocation de la mémoire dynamique du tableau lettreTrouvee
	initTableau(lettreTrouvee, nombreLettres); // Initialisation du tableau lettreTrouvee
	
	printf("\n\t Bienvenue dans le jeu du pendu ! Vous etes pret(e) : ");

	// Je jeu commence ici
	while (coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres))
	{
		printf("\n\n\t Il vous reste %d coups a jouer", coupsRestants);
		printf("\n\t Quel est le mot secret ? ");
		
		// On affiche le mot avec les lettres déjà trouvées
		for (int i = 0; i < nombreLettres; i++)
		{
			if (lettreTrouvee[i]) // Si la lettre a été trouvée
			{
				printf("%c", motSecret[i]); // On l'affiche
			}
			else
			{
				printf("*"); // Sinon, on affiche une étoile pour les lettres non trouvées
			}
		}

		printf("\n\t Proposez une lettre : ");
		lettre = lireCaractere();

		// Si la lettre se trouve pas (Si la lettre n'a pas été trouvée) dans le motSecret , on enlève un coup au joueur
		if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
		{
			coupsRestants--; // On enlève un coup au joueur
		}

	}
	
	// Afficher le résultat
	
	if (gagne(lettreTrouvee, nombreLettres))
	{
		printf("\n\n\t Bravo ! Vous avez trouve le mot secret ! Le mot secret etait bien : %s \n\n", motSecret);
	}
	else {
		printf("\n\n\t PENDU !!!! Le mot secret etait : %s \n\n", motSecret);
	}
	// On libère la mémoire allouée dynamiquement
	free(lettreTrouvee);

	return 0;
}