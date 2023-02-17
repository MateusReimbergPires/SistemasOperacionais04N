#include <stdio.h>

int main(void) {
  //1- Exercicio
  int i, j;
  int matriz[3][3] = {{6,27,38},{66,1,45},{57,84,9}};
  int menor = matriz[0][0];
  
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      if (menor > matriz[i][j]){
        menor = matriz[i][j];
      }
    }
  }
  printf("A Matriz:\n[6,27,38]\n[66,1,45]\n[57,84,9]\n\n");
  printf("O menor valor: %d", menor);
}