#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
	int nbElement;
	Element *suivant;
};

typedef struct Pile Pile;
struct Pile {
	int taillePile;
	Element *premier;
};

void empiler(Pile *pile, int nvNombre);

int depiler(Pile *pile);

void afficherPile(Pile *pile);

Pile *initialiser();