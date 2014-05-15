#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define P_SIZE sizeof(struct psuma)

struct psuma {
	uint16_t v1;
	uint16_t v2;
	uint32_t res; 
};

int main () {

	int n;
	int sd;
	int lon;
	char buffer[P_SIZE];
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;
	struct psuma *suma;

	sd = socket ( PF_INET , SOCK_DGRAM , IPPROTO_UDP );

	suma = (struct psuma *) buffer;

	suma->v1 = htons( 4 );
	suma->v2 = htons( 32 );
	suma->res = htonl( 0 );

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons (4444);
	servidor.sin_addr.s_addr = inet_addr("127.0.0.1");

	lon = sizeof (servidor);

	sendto( sd , buffer , P_SIZE , 0 , (struct sockaddr *)  &servidor, lon );

	n = recvfrom( sd , buffer , P_SIZE , 0 , (struct sockaddr *) &servidor, &lon);

	printf ("La suma de %d y %d es %d\n", ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res) ); 

	close (sd);

}
