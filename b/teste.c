#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int verifyArg(int argc, char *argv[], int *nice){
    int server_qtd = atoi(argv[1]);
	if (argc < 3) {
		printf ("usage: %s server_quantity server_host server_host_2 ... server_host_n\n", argv[0]);
		exit (1);
	}

    printf("%d\n", server_qtd);
    if(argv[server_qtd+1]==NULL){
        printf("There's some missing server.\n");
        exit(1);
    }
    *nice = 10;
    return server_qtd;
}

int main (int argc, char *argv[])
{
	char *host, *host2;
    int nice;

	int server_quantity = verifyArg(argc, argv, &nice);

    for(int i = 2; i < server_quantity + 2; i++){
        printf("server [%d]: %s\n", i - 2, argv[i]);
    }

    printf("%d", nice);
	// host = argv[1];
	// host2 = argv[2];
	// prog_1000 (host2);
	// prog_1000 (host);
    exit (0);
}