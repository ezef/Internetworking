#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char buffer[512];
    int n;

    printf ("Ingrese ALGO?:" );

    // gets( buffer ); no usar

    fgets ( buffer , sizeof (buffer) , stdin );
    buffer [ strlen(buffer) -1 ] = '\0';

    n = atoi(buffer);

    printf ("Ingreso: %s %d\n",buffer,n);

}
