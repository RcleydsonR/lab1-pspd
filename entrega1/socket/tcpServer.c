/* *****************************/
/* FGA / Eng. Software / FRC   */
/* Prof. Fernando W. Cruz      */
/* Codigo: tcpServer2.c	       */
/* *****************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QLEN 5              /* tamanho da fila de clientes  */
#define ARRAY_LENGTH 500000 /* tamanho do array */

typedef struct
{
  float numbers[ARRAY_LENGTH];
} receiveParameter;

typedef struct
{
  float numbers[2];
} sendParameter;

void merge(float originalArray[], int beginIndex, int middleIndex, int finalIndex)
{
  int firstPartSize = middleIndex - beginIndex + 1;
  int lastPartSize = finalIndex - middleIndex;
  float *firstPartArray = malloc(firstPartSize * sizeof(float));
  float *lastPartArray = malloc(lastPartSize * sizeof(float));

  for (int aux = 0; aux < firstPartSize; aux++)
    firstPartArray[aux] = originalArray[beginIndex + aux];

  for (int aux = 0; aux < lastPartSize; aux++)
  {
    lastPartArray[aux] = originalArray[middleIndex + aux + 1];
  }

  int firstPartIndex = 0, lastPartIndex = 0, generalIndex = beginIndex;

  while (firstPartIndex < firstPartSize && lastPartIndex < lastPartSize)
  {
    if (firstPartArray[firstPartIndex] <= lastPartArray[lastPartIndex])
    {
      originalArray[generalIndex++] = firstPartArray[firstPartIndex++];
    }
    else
    {
      originalArray[generalIndex++] = lastPartArray[lastPartIndex++];
    }
  }

  while (firstPartIndex < firstPartSize)
  {
    originalArray[generalIndex++] = firstPartArray[firstPartIndex++];
  }

  while (lastPartIndex < lastPartSize)
  {
    originalArray[generalIndex++] = lastPartArray[lastPartIndex++];
  }
}

void mergeSort(float originalArray[], int beginIndex, int finalIndex)
{
  if (beginIndex >= finalIndex)
    return;

  int middleIndex = (beginIndex + finalIndex) / 2;

  mergeSort(originalArray, beginIndex, middleIndex);
  mergeSort(originalArray, middleIndex + 1, finalIndex);
  merge(originalArray, beginIndex, middleIndex, finalIndex);
}

int atende_cliente(int descritor, struct sockaddr_in endCli)
{
  receiveParameter bufin;
  sendParameter bufout;
  int n;
  while (1)
  {
    // memset(&bufin, 0x0, sizeof(bufin));
    n = recv(descritor, &bufin, sizeof(bufin), MSG_WAITALL);

    if (n == 0)
      break;
    
    printf("Os numeros enviados pelo cliente foram recebidos.\n");
    mergeSort(bufin.numbers, 0, ARRAY_LENGTH - 1);

    bufout.numbers[0] = bufin.numbers[0];
    bufout.numbers[1] = bufin.numbers[ARRAY_LENGTH - 1];

    send(descritor, &bufout, sizeof(bufout), 0);

    printf("O maior e menor numero foram enviados para o cliente.\n");
    printf("-------------------------------------------------------------\n");
  }

  fprintf(stdout, "Encerrando conexao com %s:%u ...\n\n", inet_ntoa(endCli.sin_addr), ntohs(endCli.sin_port));
  close(descritor);
} /* fim atende_cliente */

int main(int argc, char *argv[])
{
  struct sockaddr_in endServ; /* endereco do servidor   */
  struct sockaddr_in endCli;  /* endereco do cliente    */
  int sd, novo_sd;            /* socket descriptors */
  int pid, alen, n;

  if (argc < 3)
  {
    printf("Digite IP e Porta para este servidor\n");
    exit(1);
  }
  memset((char *)&endServ, 0, sizeof(endServ)); /* limpa variavel endServ    */
  endServ.sin_family = AF_INET;                 /* familia TCP/IP   */
  endServ.sin_addr.s_addr = inet_addr(argv[1]); /* endereco IP      */
  endServ.sin_port = htons(atoi(argv[2]));      /* PORTA	    */

  /* Cria socket */
  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0)
  {
    fprintf(stderr, "Falha ao criar socket!\n");
    exit(1);
  }

  /* liga socket a porta e ip */
  if (bind(sd, (struct sockaddr *)&endServ, sizeof(endServ)) < 0)
  {
    fprintf(stderr, "Ligacao Falhou!\n");
    exit(1);
  }

  /* Ouve porta */
  if (listen(sd, QLEN) < 0)
  {
    fprintf(stderr, "Falhou ouvindo porta!\n");
    exit(1);
  }

  printf("Servidor ouvindo no IP %s, na porta %s ...\n\n", argv[1], argv[2]);
  /* Aceita conexoes */
  alen = sizeof(endCli);
  for (;;)
  {
    /* espera nova conexao de um processo cliente ... */
    if ((novo_sd = accept(sd, (struct sockaddr *)&endCli, &alen)) < 0)
    {
      fprintf(stdout, "Falha na conexao\n");
      exit(1);
    }
    fprintf(stdout, "Cliente %s: %u conectado.\n", inet_ntoa(endCli.sin_addr), ntohs(endCli.sin_port));
    atende_cliente(novo_sd, endCli);
  } /* fim for */
} /* fim do programa */
