/* ******************************/
/* FGA/Eng. Software/ FRC       */
/* Prof. Fernando W. Cruz       */
/* Codigo: tcpClient2.c         */
/* ******************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_LENGTH 500000 /* tamanho do array */

typedef struct
{
	float numbers[ARRAY_LENGTH];
} sendParameter;

typedef struct
{
	float numbers[2];
} receiveParameter;

void generateRandomNumbers(float array[])
{
	for (int index = 0; index < ARRAY_LENGTH; index++)
	{
		float randomNumber = pow((float)index - ((drand48()*ARRAY_LENGTH) / 2.0), 2.0);
		array[index] = randomNumber;
	}
}

int main(int argc, char *argv[])
{
	struct sockaddr_in ladoServ; /* contem dados do servidor 	*/
	int sd;						 /* socket descriptor              */
	int n, k;					 /* num caracteres lidos do servidor */
	sendParameter bufout;		 /* buffer de dados enviados  */
	receiveParameter bufin;		 /* buffer de dados recebidos  */

	/* confere o numero de argumentos passados para o programa */
	if (argc < 3)
	{
		printf("uso correto: %s <ip_do_servidor> <porta_do_servidor>\n", argv[0]);
		exit(1);
	}

	memset((char *)&ladoServ, 0, sizeof(ladoServ)); /* limpa estrutura */
	memset(&bufout, 0, sizeof(bufout));				/* limpa buffer */
	memset(&bufin, 0, sizeof(bufin));				/* limpa buffer */

	ladoServ.sin_family = AF_INET; /* config. socket p. internet*/
	ladoServ.sin_addr.s_addr = inet_addr(argv[1]);
	ladoServ.sin_port = htons(atoi(argv[2]));

	/* Cria socket */
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0)
	{
		fprintf(stderr, "Criacao do socket falhou!\n");
		exit(1);
	}

	/* Conecta socket ao servidor definido */
	if (connect(sd, (struct sockaddr *)&ladoServ, sizeof(ladoServ)) < 0)
	{
		fprintf(stderr, "Tentativa de conexao falhou!\n");
		exit(1);
	}

	char input[4];
	input[0] = 'S';
	
	while (input[0] == 'S' || input[0] == 's')
	{
		srand ( time(0) );
		generateRandomNumbers(bufout.numbers);

		int n = send(sd, &bufout, sizeof(bufout), 0); /* enviando dados ...  */

		recv(sd, &bufin, sizeof(bufin), 0);

		printf("Menor Número do Array => %.02f\n", bufin.numbers[0]);
		printf("Maior Número do Array => %.02f\n", bufin.numbers[1]);

		printf("Deseja gerar os números novamente? [Digite \'S\' para \'SIM\']\n> ");
		scanf(" %s", input);
	}
	printf("------- encerrando conexao com o servidor -----\n");
	close(sd);
	return (0);
} /* fim do programa */