/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lab1.h"

void generateRandomNumbers(float array[], long length)
{
	for (int index = 0; index < length; index++)
	{
		float randomNumber = pow((float)index - ((drand48() * length) / 2.0), 2.0);
		array[index] = randomNumber;
	}
}

void prog_1000(char *host, int qtd, float *maxValue, float *minValue)
{
	CLIENT *clnt;
	answer *result_1;
	params sort_1000_arg;

	clnt = clnt_create(host, PROG, VERSAO, "tcp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}

	generateRandomNumbers(sort_1000_arg.number, ARRAY_LENGTH/qtd);

	result_1 = sort_1000(&sort_1000_arg, clnt);
	if (result_1 == (answer *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	if(result_1->number[1] > *maxValue)
		*maxValue = result_1->number[1];
	if(result_1->number[0] < *minValue)
		*minValue = result_1->number[0];
	
	clnt_destroy(clnt);
}

int verifyArg(int argc, char *argv[])
{
	int server_qtd = atoi(argv[1]);
	if (argc < 3)
	{
		printf("usage: %s server_quantity server_host server_host_2 ... server_host_n\n", argv[0]);
		exit(1);
	}

	printf("%d\n", server_qtd);
	if (argv[server_qtd + 1] == NULL)
	{
		printf("There's some missing server.\n");
		exit(1);
	}
	return server_qtd;
}

int main(int argc, char *argv[])
{
	int server_quantity = verifyArg(argc, argv);
	char *hosts[server_quantity], input[4];


	do
	{
		float maxValue = 0.0;
		float minValue = INFINITY;
		for (int i = 2; i < server_quantity + 2; i++)
		{
			srand(time(0));
			hosts[i - 2] = argv[i];
			prog_1000(hosts[i - 2], server_quantity, &maxValue, &minValue);
		}

		printf("Menor Número do Array => %.02f\n", minValue);
		printf("Maior Número do Array => %.02f\n", maxValue);

		printf("--------------------------------------------------------------\n");
		printf("Deseja gerar os números novamente? [Digite \'S\' para \'SIM\']\n> ");
		scanf(" %s", input);
	} while (input[0] == 'S' || input[0] == 's');

	exit(0);
}