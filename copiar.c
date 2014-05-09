#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main( int argc , char *argv[] ) {

        int f1,f2;
        int n;
        char buffer[1024];



        if ( argc < 3 ) {
            
            printf ( "Ejecute %s archivo_origen archivo_destino\n",argv[0] );

            exit (-1);

        }


        f1 = open ( argv[1], O_RDONLY);

        if (f1 == -1) {
            perror("Error en archivo origen");
            exit(-1);
        }

        f2 = open ( argv[2], O_WRONLY|O_CREAT , S_IRUSR|S_IRGRP );

        while ( ( n = read ( f1 , buffer , sizeof (buffer) ) )  > 0 ) {

            write ( f2 , buffer , n );
        
        }

        close (f1);
        close (f2);

}












