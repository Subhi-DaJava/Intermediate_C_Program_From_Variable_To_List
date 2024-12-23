#include <stdio.h>
#include <stdlib.h>

#define LARGEUR 15
#define HAUTEUR 20
#define SURFACE (LARGEUR * HAUTEUR)

#define COUCOU() printf("Coucou, programmeur C, Bonne Fêtes !\n");
#define RACONTER_MON_HISTOIRE() printf("Je m'appelle SUBHI !\n"); \
							    printf("Je suis un programmeur C !\n"); \
							    printf("J'ai deja appris le langage JAVA !\n"); 

#define MAJUER(age) if(age >= 18) \
					printf("Vous etres majeur !\n"); \
					else printf("Ops, vous etes mineur!\n"); 

#define MAJUER_CHECK(name, age) if(age >= 18) \
					printf("%s , vous etres majeur !\n", name); \
					else printf("Ops, %s vous etes mineur!\n", name); 

int main()
{
	printf("Surface d'un rectangle, dont largeur=%d, hauteur=%d, vaut : %d\n", LARGEUR, HAUTEUR,SURFACE);

	printf("******************************** 1. Constantes predifinies *************************************************\n");

	printf("Nom du fichier : %s\n", __FILE__);
	printf("Nom de la fonction : %s\n", __func__);
	printf("Ligne du fichier : %d\n", __LINE__);
	printf("Date de compilation : %s\n", __DATE__);
	printf("Heure de compilation : %s\n", __TIME__);
	
	printf("******************************** 2. Macros *************************************************\n");

	COUCOU()

	printf("******************************** 3. Macros plusieurs linges antislash \  avant chaque nouvelle ligne. *************************************************\n");
	
	RACONTER_MON_HISTOIRE()

	printf("******************************** 4. Macros avec un parametre *************************************************\n");
	
	MAJUER(20)
	MAJUER(15)

	printf("******************************** 5. Macros avec plusieurs parametres *************************************************\n");
	MAJUER_CHECK("Subhi", 40)

	return 0;
}