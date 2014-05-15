#include <stdio.h>
#include <stdlib.h>

int main () {

	int cont;
	char string[10]  = "HOLA";
	char *s;

	for ( cont = 1 ; cont <= 10 ; cont++ ) {

		printf ("El valor de cont es %d\n",cont);

	} 

	for ( s = string ; *s != '\0' ; s++ ) {

		printf ("%c",*s);

	} 

	printf ("\n");

	return (0);

}
