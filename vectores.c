#include <stdio.h>

int main () { 

    int n1;
    int vec[10]; // indexado de 0..9

    for ( n1 = 0; n1 <= 9 ; n1++ ) {

        vec[n1] = n1;

        printf ("El valor de n1 es %d\n",n1);

    }


    return 0;

}
