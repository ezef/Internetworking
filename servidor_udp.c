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

int main()
{

	int n;
	int sd;
	int lon;
	char buffer[P_SIZE];
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;
	struct psuma *suma;

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);
	servidor.sin_addr.s_addr = INADDR_ANY;

	sd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (bind(sd, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
		perror("Error en bind");
		exit(-1);
	}

	while (1) {

		lon = sizeof(cliente);

		n = recvfrom(sd, buffer, P_SIZE, 0, (struct sockaddr *) &cliente, &lon);

		suma = (struct psuma *) buffer;

		printf("Recibo: %d %d %d \n", ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));

		suma->res = htonl(ntohs(suma->v1) + ntohs(suma->v2));

		printf("Envío: %d %d %d \n", ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));

		sendto(sd, buffer, P_SIZE, 0, (struct sockaddr *) &cliente, lon);

	}

	close(sd);

}
