#include <stdio.h>
#include <locale.h>

void main()
{
  setlocale(LC_ALL, "Portuguese");
  int valor;
  printf("Digite um valor: ");
  scanf("%d", &valor);

  if (valor % 2 == 0)
  {
    printf("O valor é par");
  }
  else
  {
    printf("o valor é impar");
  }

  printf("Finalizou o programa");
}