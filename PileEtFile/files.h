#include <stdio.h>
#include <stdlib.h>

typedef struct ElementFile ElementFile;
struct ElementFile
{
	int nbElement;
	ElementFile *suivant;
};

typedef struct File File;
struct File
{
	int tailleFile;
	ElementFile *premier;
};

void enfiler(File *file, int nvNombre);
int defiler(File *file);
void afficherFile(File *file);
File *initialiserFile();