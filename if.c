#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main () { 

    int n1;
    int n2;

    n1 = 10;
    n2 = 2;

    n1 = n1 + 1;
    n1++;
    n1+=6;

    n2=18;

    printf("n1=%d n2=%d\n",n1,n2);

    if ( (n1 > n2 ) || (n1 == n2 ) ) { // Igual a (n1>= n2)
    
        printf("la variable n1=%d es mayor o igual a n2=%d\n",n1,n2);

    }   

    printf("n1=%d n2=%d\n",n1++,++n2); // pre y post incremento 
    printf("n1=%d n2=%d\n",n1,n2);

    if (!FALSE) {
    
        printf("Cualquier expresion que devuelva 0 es Falso\n");

    } else {

	printf("Falso");

    }

    if ( n1 ) {

        printf("Cualqueir expresion que devuelve distinto de cero es Verdadera\n");

    }

    return 0;

}
