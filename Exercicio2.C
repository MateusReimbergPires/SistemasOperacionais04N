#include <stdio.h>
 
 int main(void) {
  //2- Exercicio
  int n1 = 8, n2 = 9, n3 = 5, ME = 10;
  float MA;
    
  MA = (n1+n2*2+n3*3+ME)/7;
  printf("Suas Notas foram:\nN1 = 8\nN2 = 9\nN3 = 5\nME = 10\n\n");
  if(MA >= 9){
    printf("Sua MA foi %.2f, e seu conceito da tabela foi A", MA);
  }
  else if(9 > MA >= 7.5){
    printf("Sua MA foi %.2f, e seu conceito da tabela foi B", MA);
  }
  else if(7.5> MA >= 6){
    printf("Sua MA foi %.2f, e seu conceito da tabela foi C", MA);
  }
  else if(6 > MA >= 4){
    printf("Sua MA foi %.2f, e seu conceito da tabela foi D", MA);
  } else{
    printf("Sua MA foi %.2f, e seu conceito da tabela foi E", MA);
  } 
}
