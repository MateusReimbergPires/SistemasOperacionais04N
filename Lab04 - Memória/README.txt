# O Código esta documentado e cumprindo todos os pedidos.

# Segue abaixo as funções que correspondem as exigências: 

1-Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista); 
 
R: Função para Criar e Função para Inserção

2-Construa uma função que imprima todos os valores da lista; 

R: Função para Impressão

3-Calcule a quantidade de memória gasta por cada instância da célula

R: Função para Calculo da Memória (celula)

4-Construa uma função que remove os elementos da lista;

R: Função para Remoção dos Elementos

5-Incremente sua função liberando a memória quando um elemento é liberado;

R: Função para Remoção dos Elementos
 
6-Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador

R: Trecho dentro da main()

"    // Máximo de Elementos
    double mem, memGb, max;
    printf("Insira a Memória disponivel em GB: ");
    scanf("%lf", &mem);
    memGb = mem * 1024 * 1024 * 1024;
    float maximoElementos = memGb/memoriaCelula(listaEncadeada);
    printf("Máximo de elementos: %f", maximoElementos); 
"
