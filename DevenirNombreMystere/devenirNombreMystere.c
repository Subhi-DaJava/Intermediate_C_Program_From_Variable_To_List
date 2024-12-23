#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "devenirNombreMystere.h"

const int MAX = 100, MIN = 1;

int devenirNombreMystere() {
	int nombreMystere = 0;
	srand(time(NULL));
	nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
}