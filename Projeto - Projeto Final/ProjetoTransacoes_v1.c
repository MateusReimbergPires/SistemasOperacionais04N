#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Constantes
#define VALOR_TRANSACAO 10
#define QUANTIDADE_TRANSACAO 100

//Estrutura
struct contaBancaria{
    int saldo;
};

// Funcoes
void* transferirValor(int valor, struct contaBancaria *de, struct contaBancaria *para){
    if (de->saldo < valor){
        printf("Saldo insuficiente!\n");
        return 1;
    }
    de->saldo-=valor;
    para->saldo+=valor;
    return 0;
}



int main (){

    pthread_t threads[QUANTIDADE_TRANSACAO];

    for (i = 0; i < QUANTIDADE_TRANSACAO; i++){
        pthread_create(&threads[i]; NULL; transferirValor; args)
    }

    struct contaBancaria from, to;
    from.saldo = 0;
    to.saldo = 1000;

    transferirValor(10, &to, &from);
    // Acesso ao saldo
    printf("teste valor conta (from): %d \n", from.saldo);
    printf("teste valor conta (to): %d \n", to.saldo);
    return 0;
}
