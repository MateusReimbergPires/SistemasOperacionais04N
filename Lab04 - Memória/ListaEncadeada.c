#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
};

typedef struct reg celula;

// Fun��o para Criar
celula* criaCelula(int valor) {
    celula *celulaCriada = (celula *) malloc(sizeof(celula));
    celulaCriada->conteudo = valor;
    celulaCriada->prox = NULL;
    return celulaCriada;
}

// Fun��o para Inser��o
void insereCelula(celula **listaEncadeada, int valor) {
    celula *celulaCriada = criaCelula(valor);
    celulaCriada->prox = *listaEncadeada;
    *listaEncadeada = celulaCriada;
}

// Fun��o para Impress�o
void imprimeCelula(celula *listaEncadeada) {
    celula *AUX = listaEncadeada;
    while (AUX != NULL) {
        printf("%d ", AUX->conteudo);
        AUX = AUX->prox;
    }
    printf("\n");
}

// Fun��o para Calculo da Mem�ria (celula)
int memoriaCelula(celula *cel) {
    int tamanho = sizeof(*cel);
    return tamanho;
}

// Fun��o para Remo��o dos Elementos
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
    // Cria��o Lista
    celula *listaEncadeada = NULL;
  
    // Cria��o Inst�ncias
    insereCelula(&listaEncadeada, 3);
    insereCelula(&listaEncadeada, 2);
    insereCelula(&listaEncadeada, 1);
  
    // Impress�o da Lista
    printf("Lista de Celulas: ");
    imprimeCelula(listaEncadeada);
  
    // Mem�ria Ocupada na Lista
    printf("Memoria gasta por c�lula: %d bytes", memoriaCelula(listaEncadeada));
  
    // Remo��o Elementos 0 e 2
    remocaoCelula(&listaEncadeada, 2);
    remocaoCelula(&listaEncadeada, 3);
    printf("\nLista ap�s a remo��o dos elementos 2 e 3: ");
    imprimeCelula(listaEncadeada);
    
    // M�ximo de Elementos
    double mem, memGb, max;
    printf("Insira a Mem�ria disponivel em GB: ");
    scanf("%lf", &mem);
    memGb = mem * 1024 * 1024 * 1024;
    float maximoElementos = memGb/memoriaCelula(listaEncadeada);
    printf("M�ximo de elementos: %f", maximoElementos);
    
    return 0;
    }
