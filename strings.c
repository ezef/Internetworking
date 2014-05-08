#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char vec[10] = "CHAU";
    char str[20];
    char *s;

    s = vec;

    printf ("El \\ string %s tiene %d letras sizeof %d\n", s , strlen (s), sizeof(s) );

    vec[0] = 'H';
    vec[1] = 'O';
    vec[2] = 'L';
    vec[3] = 'A';
    vec[4] = '\0';

    strncpy ( str , vec , sizeof(str) );

    printf ("El \\ string %s tiene %d letras sizeof %d\n", str , strlen (str), sizeof(str) );

    //  vec = "INTERNETWORKING"; NO SE PUEDE

    snprintf (str, sizeof(str) ,"%s INTERNETWORKING %s",vec,s);
	
    printf ("El \\ string %s tiene %d letras sizeof %d\n", str , strlen (str), sizeof(str) );


    return (0);

}
