#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
};

typedef struct reg celula;

// Função para Criar
celula* criaCelula(int valor) {
    celula *celulaCriada = (celula *) malloc(sizeof(celula));
    celulaCriada->conteudo = valor;
    celulaCriada->prox = NULL;
    return celulaCriada;
}

// Função para Inserção
void insereCelula(celula **listaEncadeada, int valor) {
    celula *celulaCriada = criaCelula(valor);
    celulaCriada->prox = *listaEncadeada;
    *listaEncadeada = celulaCriada;
}

// Função para Impressão
void imprimeCelula(celula *listaEncadeada) {
    celula *AUX = listaEncadeada;
    while (AUX != NULL) {
        printf("%d ", AUX->conteudo);
        AUX = AUX->prox;
    }
    printf("\n");
}

// Função para Calculo da Memória (celula)
int memoriaCelula(celula *cel) {
    int tamanho = sizeof(*cel);
    return tamanho;
}

// Função para Remoção dos Elementos
void remocaoCelula(celula **listaEncadeada, int elemento) {
    celula *anterior = NULL;
    celula *atual = *listaEncadeada;

    while (atual != NULL) {
        if (atual->conteudo == elemento) {
            if (anterior == NULL) {
                *listaEncadeada = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

int main() {
    // Criação Lista
    celula *listaEncadeada = NULL;
  
    // Criação Instâncias
    insereCelula(&listaEncadeada, 3);
    insereCelula(&listaEncadeada, 2);
    insereCelula(&listaEncadeada, 1);
  
    // Impressão da Lista
    printf("Lista de Celulas: ");
    imprimeCelula(listaEncadeada);
  
    // Memória Ocupada na Lista
    printf("Memoria gasta por célula: %d bytes", memoriaCelula(listaEncadeada));
  
    // Remoção Elementos 0 e 2
    remocaoCelula(&listaEncadeada, 2);
    remocaoCelula(&listaEncadeada, 3);
    printf("\nLista após a remoção dos elementos 2 e 3: ");
    imprimeCelula(listaEncadeada);
    
    // Máximo de Elementos
    double mem, memGb, max;
    printf("Insira a Memória disponivel em GB: ");
    scanf("%lf", &mem);
    memGb = mem * 1024 * 1024 * 1024;
    float maximoElementos = memGb/memoriaCelula(listaEncadeada);
    printf("Máximo de elementos: %f", maximoElementos);
    
    return 0;
    }
