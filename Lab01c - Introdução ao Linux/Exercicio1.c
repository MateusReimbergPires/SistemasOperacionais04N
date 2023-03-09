#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    char caracteres;

    printf("Insira o nome do arquivo: ");
    fgets(nomeArquivo, 100, stdin);

    // remove o caractere de quebra de linha da string
    // o \0 serve para indicar o fim da string
    int i = 0;
    while (nomeArquivo[i] != '\n' && nomeArquivo[i] != '\0') {
        i++;
    }
    nomeArquivo[i] = '\0';

    // fopen serve para abrir o arquivo
    arquivo = fopen(nomeArquivo, "r");
    // condicao para caso ele nao exista
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // fgetc serve para ler o caracter do arquivo
    // EOF serve para mostrar o fim do arquivo
    // putchar imprime os caracteres do arquivo 
    while ((caracteres = fgetc(arquivo)) != EOF) {
        putchar(caracteres);
    }
	// fclose serve para fechar o arquivo
    fclose(arquivo);

    return 0;
}
