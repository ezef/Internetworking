#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[] ) {

	if ( argc > 1 ) {
 
    		printf ("Ejecuto %s con el argumento %s\n", argv[0], argv[1] );

	} else {

		printf("Ejecuto %s sin argumentos\n", argv[0] );

	}

	return (0);

}
