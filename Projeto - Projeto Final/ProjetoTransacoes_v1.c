/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Constantes
#define VALOR_TRANSACAO 10


//Estrutura
struct contaBancaria {
 int saldo;
};
typedef struct contaBancaria conta;
conta from, to;
int valor;

// Criacao Threads e Semaforos
pthread_t transacoes;
sem_t mutex;


// Funcoes
int main()
{
    from.saldo = 100;
    to.saldo = 0;   

    // Acesso ao saldo
    printf("teste valor conta (from): %d \n", from.saldo);
    printf("teste valor conta (to): %d \n", to.saldo);
}
