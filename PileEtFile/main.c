#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "piles.h"

int main()
{

	// 1. Création de la pile et tester
	printf("\t1. Creation de la pile, emplier et deplier un element, et puis afficher la pile \n");

	Pile *maPile = initialiser();

	empiler(maPile, 0);
	empiler(maPile, 1);
	empiler(maPile, 2);
	empiler(maPile, 3);
	empiler(maPile, 4);

	printf("\t2. Taille de la pile: %d\n", maPile -> taillePile); // 5
	afficherPile(maPile); // 4 -> 3 -> 2 ->  1 ->  0 NULL
	
	int elementDepile = depiler(maPile);
	printf("\t3. Element depile est : %d\n", elementDepile); // 4
	afficherPile(maPile); // 3 -> 2 ->  1 ->  0 NULL
	
	printf("\t4. Taille de la pile: %d, apres avois depile le premier element.\n", maPile->taillePile); // 4

	free(maPile);


	// 2. Création de la file et tester
	printf("\t5. Creation de la file, enfiler et defiler un element, et puis afficher la file \n");

	File *maFile = initialiserFile();

	enfiler(maFile, 0);
	enfiler(maFile, 1);
	enfiler(maFile, 2);
	enfiler(maFile, 3);

	printf("\t6. Taille de la file: %d\n", maFile -> tailleFile); // 4
	afficherFile(maFile); // 0 -> 1 -> 2 -> 3 NULL

	int elementDefile = defiler(maFile);
	printf("\t7. Element defile est : %d\n", elementDefile); // 0
	afficherFile(maFile); // 1 -> 2 -> 3 NULL

	printf("\t8. Taille de la file: %d, apres avois defile le premier element.\n", maFile->tailleFile); // 3

	free(maFile);

	return 0;
}