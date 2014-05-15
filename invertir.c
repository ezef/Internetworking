#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv (char *p1, char *p2) {

	int lon, cont = 0; 

	lon = strlen(p1);

	while ( lon > 0 ) {

		lon--;

		p2[cont] = p1[lon];

		cont++;

	}

	p2[cont]='\0';

}

int main() {
	char s[100] = "FUNCIONA?";
	char sinv[100];

	inv (s, sinv);

	printf("%s invertido es %s\n",s,sinv);

}


















