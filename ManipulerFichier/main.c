#include <stdio.h>
#include <stdlib.h>
#define MAX_CHARACTERES 100

int main() {

	// 1. ouvrir un fichier et le fermer
    FILE *fichier = NULL;

    if (fopen_s(&fichier, "test.txt", "r+") == 0) {
        printf("Le fichier a ete ouvert avec succes\n");
    }
    else {
        printf("Le fichier n'a pas pu etre ouvert\n");
    }

    if (fichier != NULL && fclose(fichier) == 0){
        printf("Le fichier a ete ferme avec succes\n"); 
    }

	// 2. ecrire dans un fichier avec fputc
	FILE* fichierWChar = NULL;

    if (fopen_s(&fichierWChar, "testChar.txt", "w") == 0) {

        fputc('A', fichierWChar);
        fclose(fichierWChar);
    }

	// 3. ecrire dans un fichier avec fputs

	FILE* fichierWString = NULL;

	if (fopen_s(&fichierWString, "testString.txt", "w") == 0) {
		fputs("Hello, C Programmeur ! \nSalut les développeurs\nBienvenue sur OpenClassrooms !", fichierWString);
		fclose(fichierWString);
	}

	// 4. ecrire un fichier avec fprintf

	FILE* fichierWPrintf = NULL;
	int age = 0;

	printf("Quel age avez-vous ? ");
	scanf_s("%d", &age);

	if (fopen_s(&fichierWPrintf, "testPrintf.txt", "w") == 0) {
		fprintf(fichierWPrintf, "Hello, C Programmeur ! \nSalut les développeurs\nBienvenue sur OpenClassrooms !\n, Vous avez %d age !", age);
		fclose(fichierWPrintf);
	}

	// 5. lire un fichier avec fgetc

	FILE* fichierRChar = NULL;

	if (fopen_s(&fichierRChar, "test.txt", "r") == 0) {
		int caractere = 0;
		// Boucle de lecture des caractères un à un

		do {
			caractere = fgetc(fichierRChar); // On lit le caractère
			printf("%c", caractere); // On l'affiche
		} while (caractere != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

		fclose(fichierRChar);
	}


	// 6. lire un fichier avec fgets et afficher une ligne
	FILE *fichierReadStringLine = NULL;
	char chaineLine[MAX_CHARACTERES] = ""; // Chaîne vide de taille MAX_CHARACTERES

	if (fopen_s(&fichierReadStringLine, "testString.txt", "r") == 0) {
		// On lit MAX_CHARACTERES caractères du fichier, on stocke le tout dans "chaine"
		fgets(chaineLine, MAX_CHARACTERES, fichierReadStringLine);
		printf("\n\tReading only 1 line :\n %s\n", chaineLine); // On affiche la chaîne
		fclose(fichierReadStringLine);
	}

	// 7. lire un fichier avec fgets et afficher tout le contenu
	FILE *fichierReadString = NULL;
	char chaine[MAX_CHARACTERES] = ""; // Chaîne vide de taille MAX_CHARACTERES

	if (fopen_s(&fichierReadString, "test3.txt", "r") == 0) {
		
		while (fgets(chaine, MAX_CHARACTERES, fichierReadString) != NULL) {
			printf("\nToutes les lignes : %s", chaine);
		}
		fclose(fichierReadString);
	}

	// 8. lire un fichier avec fscanf, lire une chaine "formatee" avec fscanf
	FILE *fichierReadPrintf = NULL;
	
	int score[3] = { 0 };

	if (fopen_s(&fichierReadPrintf, "score.txt", "r") == 0) {
		fscanf_s(fichierReadPrintf, "%d %d %d", &score[0], &score[1], &score[2]);
		printf("\n  Les meilleurs scores sont : \n Score 1 : %d \n Score 2 : %d \n Score 3 : %d \n", score[0], score[1], score[2]);
		fclose(fichierReadPrintf);
	}

    return 0;
}