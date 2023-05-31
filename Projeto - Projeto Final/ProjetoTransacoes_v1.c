/*
Nome:                                   TIA:
Guilherme de Arruda Leme                42136199
Marco Antonio Marino Paulino da Costa   42133092
Mateus Reimberg Pires                   42105838
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Constantes
#define VALOR_TRANSACAO 10
#define NUMERO_TRANSACOES 100

//Estrutura
typedef struct{
    int saldo;
    sem_t *semaforo;
} ContaBancaria;

//Solucao tecnica para passar mais de um valor como argumento para a thread
typedef struct{
    int valor;
    ContaBancaria *conta1;
    ContaBancaria *conta2;
} Argumentos;

// Funcoes
void* transferirValor(void* args){
    Argumentos* argumentos = (Argumentos*) args;

    ContaBancaria *conta1 = argumentos->conta1;
    ContaBancaria *conta2 = argumentos->conta2;

    sem_wait(conta2->semaforo);
    sem_wait(conta1->semaforo);
    if (conta1->saldo < argumentos->valor){
        printf("Saldo insuficiente!\n");
    }
    else{
        conta1->saldo -= argumentos->valor;
        conta2->saldo += argumentos->valor;
    }
    sem_post(conta1->semaforo);
    sem_post(conta2->semaforo);
}

int main(){

    //Instanciação das threads e semaforos
    pthread_t threads[NUMERO_TRANSACOES];
    sem_t semaforo1, semaforo2;

    //Inicialização dos semaforos
    sem_init(&semaforo1, 0, 1);
    sem_init(&semaforo2, 0, 1);

    //Instanciação das contas e valores das contas
    ContaBancaria from, to;
    from.saldo = 1000;
    to.saldo = 0;
    from.semaforo = &semaforo1;
    to.semaforo = &semaforo2;

    //Acesso ao saldo
    printf("----------------------------\n");
    printf("Antes da realizacao das transacoes:\n");
    printf("Valor conta (from): %d \n", from.saldo);
    printf("Valor conta (to): %d \n", to.saldo);

    //Argumentos da thread para transferencia da conta from para to
    Argumentos fromTo;
    fromTo.valor = VALOR_TRANSACAO;
    fromTo.conta1 = &from;
    fromTo.conta2 = &to;

    //Argumentos da thread para transferencia da conta to para from
    Argumentos toFrom;
    toFrom.valor = VALOR_TRANSACAO;
    toFrom.conta1 = &to;
    toFrom.conta2 = &from;

    //Iniciacao das threads + execucao
    int i;
    for (i = 0; i < NUMERO_TRANSACOES; i++){
        pthread_create(&threads[i], NULL, transferirValor, &fromTo);
    }

    for (i = 0; i < NUMERO_TRANSACOES; i++){
        pthread_join(threads[i], NULL);
    }

    //Acesso ao saldo
    printf("----------------------------\n");
    printf("Apos transacao da conta from para to:\n");
    printf("Valor conta (from): %d \n", from.saldo);
    printf("Valor conta (to): %d \n", to.saldo);

    for (i = 0; i < NUMERO_TRANSACOES; i++){
        pthread_create(&threads[i], NULL, transferirValor, &toFrom);
    }

    for (i = 0; i < NUMERO_TRANSACOES; i++){
        pthread_join(threads[i], NULL);
    }

    //Acesso ao saldo
    printf("----------------------------\n");
    printf("Apos transacao da conta to para from:\n");
    printf("Valor conta (from): %d \n", from.saldo);
    printf("Valor conta (to): %d \n", to.saldo);

    sem_destroy(&semaforo1);
    sem_destroy(&semaforo2);

    printf("----------------------------\n");

    return 0;
}