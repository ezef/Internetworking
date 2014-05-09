#include <stdio.h>
#include <stdlib.h>

int main () {

	int pid;
	int cont;

	cont = 10;

	pid = fork();

	if ( pid != 0 ) {

		for ( cont = 1 ; cont <= 10000 ; cont++ ) {
			printf ("Proceso Padre: valor de cont es %d\n",cont);
			sleep (1);
		} 

	} else {

                for ( cont = 1 ; cont <= 10000 ; cont++ ) {
                        printf ("Proceso Hijo: valor de cont es %d\n",cont);
			sleep (1);
                }

	}

	return (0);

}
