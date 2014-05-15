#include <stdio.h>
#include <stdlib.h>

int main () {

	int n1;
	int n2;
	int *p;
	int *q;

	n1 = 10;
	n2 = 20;

	p = malloc ( sizeof (int) );
	
	*p = 30;

	q = &n2;

	printf ("El valor de n1 es %d de n2 es %d de *p es %d de *q es %d\n",n1,n2,*p,*q);

	*q = 50;

	free (p);

	p = q;

	printf ("El valor de n1 es %d de n2 es %d de *p es %d de *q es %d\n",n1,n2,*p,*q);

	printf ("Las posiciones de memoria de n1 es %d de n2 es %d de p es %d de q es %d\n",&n1,&n2,p,q);
	
	return (0);

}
