#include <stdio.h>
#include <stdlib.h>

void swap ( int *p1, int *p2) {

	int aux;

	aux = *p1;
	*p1 = *p2;
	*p2 = aux;

}

int main () {

	int n1;
	int n2;

	n1 = 10;
	n2 = 20;

	printf ("El valor de n1 es %d de n2 es %d\n",n1,n2);

	swap ( &n1 , &n2 );

	printf ("El valor de n1 es %d de n2 es %d\n",n1,n2);

	return (0);

}
