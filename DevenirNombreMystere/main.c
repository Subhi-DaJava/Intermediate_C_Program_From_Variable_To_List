#include <stdio.h>
#include <stdlib.h>
#include "devenirNombreMystere.h"

int main() {
	int nombreMystere = devenirNombreMystere();
	int nombreEntre = 0;
	do {
		static int coups = 0;
		printf("Quel est le nombre ? ");
		scanf_s("%d", &nombreEntre);
		coups++;
		if (nombreEntre > nombreMystere) {
			printf("C'est moins !\n");
		}
		else if (nombreEntre < nombreMystere) {
			printf("C'est plus !\n");
		}
		else {
			printf("Bravo, vous avez trouve le nombre mystere en %d coups !!!\n", coups);
		}
	} while (nombreEntre != nombreMystere);

	return 0;

}
