#include "incremente.h"

/*
Ici, la première fois qu'on appelle la fonction incremente, 
la variable nombre est créée. Elle est incrémentée à 1, et une fois la fonction terminée la variable n'est pas supprimée.
Lorsque la fonction est appelée une seconde fois, la ligne de la déclaration de variable est tout simplement "sautée". 
On ne recrée pas la variable, on réutilise la variable qu'on avait déjà créée. Comme la variable valait 4, elle vaudra maintenant 5, puis 6, puis 7, etc.
*/

int incremente() {
	static int i = 0;
	i++;
	return i;
}

static int triple(int nombre) {
	return nombre * 3;
}

int incrementeTriple() {
	return triple(incremente());
}