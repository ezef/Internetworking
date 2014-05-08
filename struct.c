#include <stdio.h>
#include <stdlib.h>

int main () {

	
	struct tipoalumno {
		int legajo;
		char nombre[100];
	};

	struct tipoalumno alumno;

	struct tipoalumno *p;

	alumno.legajo = 123456;
	snprintf ( alumno.nombre, 100 , "AGUSTIN" );

	printf ("El legajo de %s es %d\n",alumno.nombre, alumno.legajo );

	p = &alumno;

	printf ("El legajo de %s es %d\n", (*p).nombre, p->legajo );

	return (0);

}
