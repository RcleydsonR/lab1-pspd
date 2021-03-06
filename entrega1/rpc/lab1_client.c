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

void generateRandomNumbers(float array[])
{
	for (int index = 0; index < ARRAY_LENGTH; index++)
	{
		float randomNumber = pow((float)index - ((drand48()*ARRAY_LENGTH) / 2.0), 2.0);
		array[index] = randomNumber;
	}
}

void prog_1000(char *host)
{
	CLIENT *clnt;
	answer  *result_1;
	params  sort_1000_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PROG, VERSAO, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	char input[4];
	
	do 
	{
		generateRandomNumbers(sort_1000_arg.number);

		result_1 = sort_1000(&sort_1000_arg, clnt);
		if (result_1 == (answer *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("Menor Número do Array => %.02f\n", result_1->number[0]);
		printf("Maior Número do Array => %.02f\n", result_1->number[1]);

		printf("--------------------------------------------------------------\n");
		printf("Deseja gerar os números novamente? [Digite \'S\' para \'SIM\']\n> ");
		scanf(" %s", input);
	}while (input[0] == 'S' || input[0] == 's');



#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	prog_1000 (host);
exit (0);
}
