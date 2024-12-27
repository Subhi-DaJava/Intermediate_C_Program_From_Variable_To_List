#include <stdio.h>
#include <stdlib.h>
#include "piles.h"

void empiler(Pile* pile, int nvNombre)
{
	Element* nouveau = malloc(sizeof(*nouveau));

	if (pile == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	nouveau->nbElement = nvNombre;
	nouveau->suivant = pile->premier;

	pile->premier = nouveau;

	pile->taillePile++;
}

int depiler(Pile* pile)
{
	if (pile == NULL)
	{
		exit(EXIT_FAILURE);
	}

	int nombreDepile = 0;

	Element* elementDepile = pile->premier;

	if (pile != NULL && pile->premier != NULL)
	{
		nombreDepile = elementDepile->nbElement;
		pile->premier = elementDepile->suivant;

		free(elementDepile);

		pile->taillePile--;
	}

	return nombreDepile;
}

void afficherPile(Pile* pile)
{
	if (pile == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Element* actuel = pile->premier;

	while (actuel != NULL)
	{
		printf("\t  %d -> ", actuel->nbElement);
		actuel = actuel->suivant;
	}

	printf("NULL\n");
}

Pile* initialiser()
{
	Pile* pile = malloc(sizeof(*pile));

	if (pile == NULL) {
		exit(EXIT_FAILURE);
	}

	pile->premier = NULL;

	pile->taillePile = 0;

	return pile;
}