#include <stdio.h>

int main() {
    char entrada[100]; 
	char saida[100];
    FILE *arquivoEntrada;
    FILE *arquivoSaida;

    printf("Arquivo de entrada: ");
    scanf("%s", entrada);
    printf("Arquivo de saida: ");
    scanf("%s", saida);

    arquivoEntrada = fopen(entrada, "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    arquivoSaida = fopen(saida, "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao criar arquivo\n");
        fclose(arquivoEntrada);
        return 1;
    }
	
	// o fputc serve para escrever o caracter do arquivo1 no arquivo2
    char caracter;
    while ((caracter = fgetc(arquivoEntrada)) != EOF) {
        fputc(caracter, arquivoSaida);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Copia Realizada\n");

    return 0;
}
