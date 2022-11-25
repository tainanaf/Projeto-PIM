#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "produto.h"
#include "funcionario.h"

void main()
{
	setlocale(LC_ALL, "portuguese");
	char opcao;
	int *quantidadeFuncionario,*quantidadeProduto;
	Funcionario *funcionario;
	Produto *produto;
	funcionario = malloc(10 * sizeof(Funcionario));
    produto = malloc(50 * sizeof(produto));
	quantidadeFuncionario = malloc(sizeof(int));
	quantidadeProduto = malloc(sizeof(int));
	*quantidadeFuncionario = 0;
	*quantidadeProduto = 0;


	do
	{
		opcao = menuInicial();
		switch (opcao)
		{
		case '1':
			loginAdministrador();
			menuAdm(quantidadeFuncionario, funcionario);
			system("cls");
			break;
		case '2':
			if (*quantidadeFuncionario == 0){
				printf("\nNenhum funcionario cadastrado!\n");
				system("pause");
				system("cls");
				break;
			}
			loginFuncionario(funcionario, quantidadeFuncionario);
			mostraMenuColaborador(produto,quantidadeProduto);
			break;
		case '0':
			printf("\n\nPROGRAMA FINALIZADO! \n\n");
			system("pause");
			break;
		default:
			printf("\nESSA OPCÃOO NÃO EXISTE! ESCOLHA UMA OPÇÃOO VALIDA \n");
		}
	} while (opcao != '0');
}







