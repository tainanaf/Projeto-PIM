#include <stdio.h>

void main(){
  int valor;
  printf("Digite um valor: ");
  scanf("%d",&valor);

  if(valor % 2 == 0 ){
    printf("O valor e par");
  }
  else {
    printf("o valor e impar");
  }
}