#include <stdio.h>
#include <stdlib.h>
#include "files.h"


void enfiler(File *file, int nvNombre)
{
	ElementFile *nouveau = malloc(sizeof(*nouveau));
	
	if (file == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau -> nbElement = nvNombre;
	nouveau -> suivant = NULL;

	if (file -> premier == NULL)
	{
		file -> premier = nouveau;
	}
	else
	{
		ElementFile *elementActuel = file -> premier;
		while (elementActuel -> suivant != NULL)
		{
			elementActuel = elementActuel -> suivant;
		}

		elementActuel -> suivant = nouveau;
	}

	file -> tailleFile++;
}

int defiler(File *file)
{
	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	int nombreDefile = 0;
	
	if (file -> premier != NULL)
	{
		ElementFile *elementDefile = file -> premier;
		nombreDefile = elementDefile -> nbElement;
		file -> premier = elementDefile -> suivant;
		
		free(elementDefile);
		
		file -> tailleFile--;
	}

	return nombreDefile;
}

File *initialiserFile()
{
	File *file = malloc(sizeof(*file));
	
	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	file -> tailleFile = 0;
	
	file -> premier = NULL;
	
	return file;
}

void afficherFile(File *file)
{
	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	ElementFile *actuel = file -> premier;
	
	while (actuel != NULL)
	{
		printf("\t %d -> ", actuel -> nbElement);
		
		actuel = actuel -> suivant;
	}

	printf("NULL\n");
}