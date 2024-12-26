#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
	int nombre;
	Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
	int nbElements;
	Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);

void insertionMilieu(Liste *liste, int nvNombre, Element *position);
void suppressionMilieu(Liste *liste, Element *aSupprimer);
void destructionListe(Liste *liste);

Liste *initialisation()
{
	Liste *liste = malloc(sizeof(*liste));

	Element *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	element -> nombre = 0;

	element -> suivant = NULL;

	liste -> premier = element;
	liste -> nbElements = 1;

	return liste;
}

void insertion(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(*nouveau));
	
	if (liste == NULL || nouveau == NULL)
	
	{
		exit(EXIT_FAILURE);
	}
	
	nouveau -> nombre = nvNombre;
	
	nouveau -> suivant = liste -> premier;
	
	liste -> premier = nouveau;
	liste -> nbElements++;
}

void suppression(Liste *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (liste -> premier != NULL)
	{
		Element *aSupprimer = liste -> premier;

		liste -> premier = liste -> premier -> suivant;

		liste -> nbElements--;

		free(aSupprimer);
		
	}
}

/*
1. On part du premier élément et on affiche le contenu de chaque élément de la liste (un nombre).

2. On se sert du pointeur suivant pour passer à l'élément qui suit à chaque fois.

*/

void afficherListe(Liste *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Element *actuel = liste -> premier;
	
	while (actuel != NULL)
	{
		printf("\t%d -> ", actuel -> nombre);
		actuel = actuel -> suivant;
	}
	printf("NULL\n");
}

void insertionMilieu(Liste *liste, int nvNombre, Element *position)
{
	Element* nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL || position == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *elementPrecedent = liste -> premier;

	while (liste -> premier -> suivant != position) {
		elementPrecedent = elementPrecedent -> suivant;
	}

	nouveau -> nombre = nvNombre;
	nouveau -> suivant = elementPrecedent -> suivant;
	elementPrecedent -> suivant = nouveau;
	liste -> nbElements++;
}

void suppressionMilieu(Liste *liste, Element *aSupprimer)
{
	if (liste == NULL || aSupprimer == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (liste -> premier == aSupprimer)
	{
		// Si l'élément à supprimer est le premier élément
		liste -> premier = aSupprimer -> suivant;
	}
	else
	{
		Element *elementPrecedent = liste -> premier;

		// Trouver l'élément précédent de celui à supprimer
		while (elementPrecedent -> suivant != aSupprimer)
		{
			elementPrecedent = elementPrecedent -> suivant;
		}

		// Réorienter le pointeur suivant de l'élément précédent
		elementPrecedent -> suivant = aSupprimer -> suivant;
	}

	liste->nbElements--;

	free(aSupprimer);
}

void destructionListe(Liste *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Element *current = liste -> premier;
	Element *next;

	while (current != NULL)
	{
		next = current -> suivant;
		free(current);
		current = next;

	}



	liste -> premier = NULL;

	liste -> nbElements = 0;
}
