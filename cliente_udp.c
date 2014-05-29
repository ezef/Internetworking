#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define P_SIZE sizeof(struct psuma)

struct psuma {
	uint16_t v1;
	uint16_t v2;
	uint32_t res;
};

int main(int argc, char *argv[])
{

	int n;
	int sd;
	int lon;
	char teclado[512];
	char buffer[P_SIZE];
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;
	struct hostent *h;
	struct psuma *suma;

	if (argc < 2) {
		printf("Debe ejecutar ./%s (nombre de host)\n",argv[0]); 
		exit (-1);
	}

	sd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	suma = (struct psuma *) buffer;

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);

	//servidor.sin_addr.s_addr = inet_addr("127.0.0.1");

	if ( h = gethostbyname ( argv [1] ) ) {
	
		memcpy ( &servidor.sin_addr , h->h_addr , h->h_length );
	
	}

	while (ntohl(suma->res) != 100) {

		printf("Ingrese valor 1: ");
		fgets(teclado, sizeof(teclado), stdin);
		teclado[strlen(teclado) - 1] = '\0';

		suma->v1 = htons(atoi(teclado));

		printf("Ingrese valor 2 (sumar 100 para salir): ");
		fgets(teclado, sizeof(teclado), stdin);
		teclado[strlen(teclado) - 1] = '\0';

		suma->v2 = htons(atoi(teclado));

		suma->res = htonl(0);

		lon = sizeof(servidor);

		sendto(sd, buffer, P_SIZE, 0, (struct sockaddr *) &servidor, lon);

		n = recvfrom(sd, buffer, P_SIZE, 0, (struct sockaddr *) &servidor, &lon);

		printf("La suma de %d y %d es %d\n", ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));

	}

	close(sd);

}
