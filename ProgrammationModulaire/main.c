#include <stdio.h>
#include <stdlib.h>
#include "aire.h"
#include "incremente.h"

int main() {

	aireRectangle(5.23, 10.0);

	printf("\n\n******************************* Variable Locale, Globale et Static dans une fonction **************\n");

	printf("Variable de incremente %d\n", incremente());
	printf("Variable de incremente %d\n", incremente());
	printf("Variable de incremente %d\n", incremente());
	printf("Variable de incremente %d\n", incremente());

	printf("\n\n******************************* Test: Appel d une autre fonction  **************\n");
	printf("Variable de incrementeTriple %d\n", incrementeTriple());

	printf("\n\n******************************* Test Fonction local (static) **************\n");
	printf("Variable de incremente %d\n", triple(5));

	return 0;
}

