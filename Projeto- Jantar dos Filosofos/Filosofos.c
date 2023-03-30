/*
Integrantes:

 Mateus Reimberg - TIA: 42105838
 Guilherme Leme - TIA: 42136199
 Marco Antonio - TIA: 42133092
 
 ---------------------------------------------------------------------------------------------------------
 
b) Explique, em cada trecho do seu programa, como é resolvido o problema da comunicação inter processos (IPC).

 R: A solução do problema da comunicação inter processos (IPC) ocorre através do uso de semaforos,
mais especificamente, com a utilização do "sem_wait()" e "sem_post()", onde são responsaveis por cuidar
de quando um filosofo pega um talher na sua vez, e após utilizalo, que ocorra sua devolução.

*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Constantes
#define FILOSOFOS_GARFOS 5

// Criacao Threads e Semaforos 
pthread_t threads_filosofos[FILOSOFOS_GARFOS];
sem_t semaforos_garfos[FILOSOFOS_GARFOS];
sem_t mutex;
sem_t turno;

// Funcoes
void pensar(int id_filosofo){
    printf("O Filosofo %d está pensando.\n", id_filosofo);
    sleep(1);
}

void pegar(int garfo_esquerda, int garfo_direita, int id_filosofo){
    sem_wait(&turno);
    sem_wait(&mutex);
    sem_wait(&semaforos_garfos[garfo_esquerda]);
    sem_wait(&semaforos_garfos[garfo_direita]);
    printf("O Filosofo %d está com 2 garfos.\n", id_filosofo);
    sem_post(&mutex);
}

void comer(int id_filosofo){
    printf("O Filosofo %d está comendo.\n", id_filosofo);
    sleep(1);
}

void largar(int garfo_esquerda, int garfo_direita, int id_filosofo){
    sem_wait(&mutex);
    sem_post(&semaforos_garfos[garfo_esquerda]);
    sem_post(&semaforos_garfos[garfo_direita]);
    printf("O Filosofo %d largou ambos os garfos.\n", id_filosofo);
    sem_post(&turno);
    sem_post(&mutex);
}

void *jantar_filosofos(void *ptr){
    int id_filosofo = *(int*)ptr;
    
    while(1){
        //pensar
        pensar(id_filosofo);
        
        //pegar
        int garfo_esquerda = id_filosofo;
        int garfo_direita = (id_filosofo + 1) % FILOSOFOS_GARFOS;
        pegar(garfo_esquerda, garfo_direita, id_filosofo);
        
        //comer
        comer(id_filosofo);
        
        //largar
        largar(garfo_esquerda, garfo_direita, id_filosofo);
    }
    return 0;
}

int main() {
    // Semaforos
    sem_init(&mutex, 0, 1);
    sem_init(&turno, 0, 1);
    for(int i = 0; i < FILOSOFOS_GARFOS; i++){
        sem_init(&semaforos_garfos[i], 0, 1);
    }
    
    // Threads
    int ids[FILOSOFOS_GARFOS];
    for(int i = 0; i < FILOSOFOS_GARFOS; i++){
        ids[i] = i;
        if(pthread_create(&threads_filosofos[i], NULL, jantar_filosofos, &ids[i]) != 0){
            printf("Erro ao criar thread.\n");
            return 1;
        }
    }   
    
    // Esperar as threads terminarem
    for(int i = 0; i < FILOSOFOS_GARFOS; i++){
        if(pthread_join(threads_filosofos[i], NULL) != 0){
            printf("Erro ao esperar thread.\n");
            return 1;
        }
    }
    
    // Destruir semaforos
    sem_destroy(&mutex);
    sem_destroy(&turno);
    for(int i = 0; i < FILOSOFOS_GARFOS; i++){
        sem_destroy(&semaforos_garfos[i]);
    }
    
    return 0;
    
}
