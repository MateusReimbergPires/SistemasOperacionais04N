#include <stdio.h>

int main(void) {
  //3- Exercicio
  //Retirar as "//" para colocar seu proprio input.
  int numeroUsuario = 7, meio = (numeroUsuario/2) + 1, contador;
  int vetor[numeroUsuario];
  
  printf("Digite um numero impar:\n");
  //scanf("%d", &numeroUsuario);
  //if(numeroUsuario % 2 == 1){
  printf("Supondo que o numero seja 7.\n\n");
    
  contador = numeroUsuario - numeroUsuario+1;
  for( int i = 0; i <= meio; i++){
    for(int j = i +1; j <= numeroUsuario - i; j++){
      printf("%d", j);
    }
    printf("\n");
  }
  //}else{
    //printf("O número não é impar");
  //} 
}