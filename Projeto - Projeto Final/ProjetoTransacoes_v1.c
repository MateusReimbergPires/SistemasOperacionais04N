/*
Nome:                       TIA:
Guilherme de Arruda Leme    42136199
Marco Antonio               4
Mateus Reimberg Pires       4
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Constantes
#define VALOR_TRANSACAO 10
#define NUMERO_TRANSACOES 10

//Estrutura
typedef struct{
    int saldo;
} ContaBancaria;

//Solucao tecnica para passar mais de um valor como argumento para a thread
typedef struct{
    int valor;
    ContaBancaria *de;
    ContaBancaria *para;
} Argumentos;

// Funcoes
void* transferirValor(void* args){
    Argumentos* argumentos = (Argumentos*) args;
    if (argumentos->de->saldo < argumentos->valor){
        printf("Saldo insuficiente!\n");
    }
    else{
    argumentos->de->saldo -= argumentos->valor;
    argumentos->para->saldo += argumentos->valor;    
    }
}

int main(){
    ContaBancaria from, to;
    from.saldo = 100;
    to.saldo = 100;
    Argumentos a;
    a.valor = 10;
    a.de = &from;
    a.para = &to;

    transferirValor((void*) &a);
    //Acesso ao saldo
    printf("teste valor conta (from): %d \n", from.saldo);
    printf("teste valor conta (to): %d \n", to.saldo);
    return 0;
}
