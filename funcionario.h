#include <stdio.h>
#include <locale.h>

typedef struct
{
	char nome[30], cpf[20], sexo[30], funcao[30], login[50], senha[30];
	float salario, idade;
} Funcionario;

void menuAdm(int *quantidadeFuncionario, Funcionario *funcionario)
{

	char opcao;
	do
	{
		printf("=================================\n--------  LASTFOOD MENU  --------\n=================================\n\n");
		printf("[1] CADASTRAR NOVO FUNCION�RIO\n");
		printf("[2] LISTA DE FUNCION�RIOS \n");
		printf("[3] BUSCAR FUNCION�RIO \n");
		printf("[4] EDITAR CADASTRO DO FUNCIONARIO\n");
		printf("[0] SAIR \n");
		printf("\nEscolha uma op��o: ");
		opcao = getche();
		switch (opcao)
		{
		case '1':
			cadastrarFuncionarios(funcionario, quantidadeFuncionario);
			system("cls");
			break;
		case '2':
			listarFuncionarios(quantidadeFuncionario, funcionario);
			system("pause");
			system("cls");
			break;
		case '3':
			procurarFuncionario(quantidadeFuncionario, funcionario);
			break;
		case '4':
			editarCadastroDoFuncionario(quantidadeFuncionario, funcionario);
			break;
		case '0':
			printf("\n\nSESS�O FINALIZADA \n\n");
			system("pause");
			break;
		default:
			printf("\nESSA OP��O N�O EXISTE! ESCOLHA UMA OP��O V�LIDA \n");
			system("pause");
			system("cls");
		}
	} while (opcao != '0');
}

int mostraMenuColaborador(Produto * produto, int * quantidadeProduto) {
  char opcao;

  do {
    printf("=================================\n--------  LASTFOOD MENU  --------\n=================================\n\n");
    printf("[1] SIMULADOR DE VALORES\n");
    printf("[2] CADASTRAR PRODUTO \n");
    printf("[3] LISTAR PRODUTOS \n");
    printf("[4] ALTERAR NFORMA��ES DO PRODUTO\n");
    printf("[5] BUSCAR PRODUTO \n");
    printf("[0] SAIR\n");
    printf("\nEscolha uma op��o: ");
    opcao = getche();

    switch (opcao) {
    case '1':
      simulador();
      system("cls");
      break;
    case '2':
      cadastrarProduto(produto, quantidadeProduto);
      system("cls");
      break;
    case '3':
      if ( * quantidadeProduto == 0) {
        system("cls");
        printf("-----------------------------------\n");
        printf("    NENHUM PRODUTO CADASTRADO!!\n");
        printf("-----------------------------------\n\n");
        system("pause");
        system("cls");
      } else {
        listarProdutos(quantidadeProduto, produto);
        system("cls");
      }
      break;
    case '4':
      if ( * quantidadeProduto == 0) {
        system("cls");
        printf("-----------------------------------\n");
        printf("    NENHUM PRODUTO CADASTRADO!!\n");
        printf("-----------------------------------\n\n");
        system("pause");
        system("cls");
      } else {
        alteraInformacoesDorProduto(produto, quantidadeProduto);
        system("cls");
      }
      break;

      case '5':
      buscarProduto(produto,quantidadeProduto);
      system("cls");
      break;

    case '0':
      printf("\n\nSESS�O FINALIZADA \n\n");
      system("pause");
      break;
    default:
      printf("\nESSA OP��O N�O EXISTE! ESCOLHA UMA OP��O V�LIDA \n");
    }
  } while (opcao != '0');
  system("cls");
}

char menuInicial()
{
	char opcao;

	printf("================================\n -----  Com.TI.go SISTEMAS  -----\n================================\n\n");
	printf("\n[1] ADMINISTRADOR");
	printf("\n\[2] FUNCIONARIO");
	printf("\n\[0] SAIR\n");
	opcao = getche();
	while (opcao != '1' && opcao != '2' && opcao != '0')
	{
		printf("\n--------------------------------\nOp��o incorreta! \nPor favor, digite novamente: ");
		opcao = getche();
	}


	return opcao;
}


void cadastrarFuncionarios(Funcionario *funcionario, int *quantidadeFuncionario)
{
	char novoCadastro;
	int i;
	do
	{
		i = *quantidadeFuncionario;
		fflush(stdin);
		system("cls");
		printf("=====CADASTRO DE FUNCION�RIO=====\n");
		printf("\nCPF (sem h�fen): ");
		gets((funcionario + i)->cpf);
		printf("Nome: ");
		gets((funcionario + i)->nome);
		printf("Idade: ");
		fflush(stdin);
		scanf("%f", &(funcionario + i)->idade);
		fflush(stdin);
		printf("Sexo: ");
		gets((funcionario + i)->sexo);
		printf("Fun��o: ");
		gets((funcionario + i)->funcao);
		printf("Sal�rio: R$ ");
		scanf("%f", &(funcionario + i)->salario);
		fflush(stdin);
		printf("\n----------CRIANDO LOGIN----------\nLogin: ");
		gets((funcionario + i)->login);
		fflush(stdin);
		printf("Senha: ");
		gets((funcionario + i)->senha);

		*quantidadeFuncionario = *quantidadeFuncionario + 1;

		printf("\nCadastro realizado com sucesso! \a\n");
		printf("\n[1] Realizar um novo cadastro");
		printf("\n[2] Voltar para o menu\n");
		novoCadastro = getche();
		while (novoCadastro != '1' && novoCadastro != '2')
		{
			printf("\nOP��O INV�LIDA.\nPOR FAVOR, DIGITE NOVAMENTE: ");
			novoCadastro = getche();
		}
	} while (novoCadastro != '2');
}

void listarFuncionarios(int *quantidadeFuncionario, Funcionario *funcionario)
{
	int i;
	if (*quantidadeFuncionario == 0)
	{
		printf("\n\nNENHUM FUNCION�RIO CADASTRADO!!\n\n");
		return;
	}

	printf("\n\n======= LISTA DE FUNCION�RIOS =======\n\n");
	for (i = 0; i < *quantidadeFuncionario; i++)
	{
		mostraFuncionario(funcionario + i);
		printf("- - - - - - - - - - - - - - - - - - -\n");
	}
}

void procurarFuncionarioPorFuncao(int *quantidadeFuncionario, Funcionario *funcionario)
{
	bool achou = false;
	char funcao[30], opcao;

	fflush(stdin);

	printf("\nINFORME A FUNCAO DO FUNCION�RIO: ");
	gets(funcao);
	achou = false;
	for (int i = 0; i < *quantidadeFuncionario; i++)
	{
		if (strcmp(funcao, (funcionario + i)->funcao) == 0)
		{
			achou = true;
			mostraFuncionario(funcionario + i);
			system("pause");
			system("cls");
		}
	}

	if (achou == false)
	{
		printf("\nA FUNC�O DIGITADA N�O FOI ENCONTRADO! \n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1')
		{
			system("cls");
			procurarFuncionarioPorNome(quantidadeFuncionario, funcionario);
		}
	}
}

void procurarFuncionarioPorNome(int *quantidadeFuncionario, Funcionario *funcionario)
{
	fflush(stdin);
	bool achou = false;
	char nome[30], opcao;

	printf("\nINFORME O NOME  DO FUNCION�RIO: ");
	gets(nome);
	for (int i = 0; i < *quantidadeFuncionario; i++)
	{
		if (strcmp(nome, (funcionario + i)->nome) == 0)
		{
			achou = true;

			mostraFuncionario(funcionario + i);
			system("pause");
			system("cls");
		}
	}

	if (achou == false)
	{
		printf("\nO NOME DIGITADO N�O FOI ENCONTRADO! \n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1')
		{
			system("cls");
			procurarFuncionarioPorNome(quantidadeFuncionario, funcionario);
		}
	}
}

Funcionario *procurarFuncionarioPorCPF(int *quantidadeFuncionario, Funcionario *funcionario)
{
	bool achou = false;
	char cpf[20], opcao;

	fflush(stdin);

	printf("\nINFORME O CPF DO FUNCION�RIO (SEM H�FEN): ");
	gets(cpf);
	achou = false;
	for (int i = 0; i < *quantidadeFuncionario; i++)
	{
		if (strcmp(cpf, (funcionario + i)->cpf) == 0)
		{
			achou = true;
			mostraFuncionario(funcionario + i);
			printf("\n");
			system("pause");
			system("cls");
			return (funcionario + i);
		}
	}

	if (achou == false)
	{
		printf("\nO CPF digitado n�o foi encontrado!\n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1')
		{
			system("cls");
			procurarFuncionarioPorCPF(quantidadeFuncionario, funcionario);
			return;
		}

		if (opcao == '0')
		{
			system("cls");
			menuAdm(quantidadeFuncionario, funcionario);
		}
	}

	return NULL;
}

void loginFuncionario(Funcionario *funcionario, int *quantidadeFuncionario)
{
	system("cls");
	int i = 0;
	bool achou = false;
	char login1[30], senha1[30];
	if (*quantidadeFuncionario == 0)
	{
		printf("\nNENHUM COLABORADOR CADASTRADO!!\n\n");
		return;
	}

	printf("---------------------------------\n\tLOGIN COLABORADOR\n---------------------------------\n");
	do
	{
		fflush(stdin);
		printf("\nUSU�RIO: ");
		scanf("%s", &login1);
		printf("SENHA: ");
		scanf("%s", &senha1);
		for (i = 0; i < *quantidadeFuncionario; i++)
		{
			if (strcmp((funcionario + i)->login, login1) == 0 && strcmp((funcionario + i)->senha, senha1) == 0)
			{
				achou = true;

				printf("\n---------------------------------\n\tLOGIN CONCLU�DO!\n---------------------------------\n\n");
				printf("\tSEJA BEM VINDO %s!!\n", (funcionario + i)->nome);
				printf("---------------------------------\n");
				system("pause");
				system("cls");
				return i;
			}
		}

		if (achou == false)
		{
			printf("\nLOGIN INCORRETO.");
			printf("\nPOR FAVOR, TENTE NOVAMENTE: \n");
		}
	} while (strcmp((funcionario + i)->login, login1) != 0 || strcmp((funcionario + i)->senha, senha1) != 0);
}

void loginAdministrador()
{
	system("cls");
	char login[50] = "adm", login1[50], senha[8] = "1234", senha1[8];
	printf("---------------------------------\n       LOGIN ADMINISTRADOR\n---------------------------------\n");
	do
	{
		fflush(stdin);
		printf("\nUSUARIO: ");
		scanf("%s", &login1);
		printf("SENHA: ");
		scanf("%s", &senha1);
		if (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0)
		{
			printf("\nLOGIN INCORRETO.");
			printf("\nPOR FAVOR, TENTE NOVAMENTE: \n");
		}
	} while (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0);
	printf("\n---------------------------------\n        LOGIN CONCLUIDO!\n---------------------------------\n\n");
	system("pause");
	system("cls");
}

void procurarFuncionario(int *quantidadeFuncionario, Funcionario *funcionario)
{
	if (*quantidadeFuncionario == 0)
	{
		printf("\n\nNENHUM FUNCIONARIO CADASTRADO!!\n\n");
		system("pause");
		system("cls");
		return;
	}

	char opcao;
	do
	{
		printf("\n\n-----------BUSCAR POR-----------\n");
		printf("[1] NOME\n");
		printf("[2] CPF\n");
		printf("[3] FUN��O\n");
		printf("[0] Sair\n\n");
		printf("Escolha uma op��o: ");
		opcao = getche();
		fflush(stdin);
		switch (opcao)
		{
		case '1':
			procurarFuncionarioPorNome(quantidadeFuncionario, funcionario);
			system("cls");
			return;
			break;

		case '2':
			procurarFuncionarioPorCPF(quantidadeFuncionario, funcionario);
			system("cls");
			return;
			break;

		case '3':
			procurarFuncionarioPorFuncao(quantidadeFuncionario, funcionario);
			system("cls");
			return;
			break;

		case '0':
			system("cls");
			return;
			break;

		default:
			printf("\nESSA OP��O N�O EXISTE! ESCOLHA UMA OP��O V�LIDA \n");
			system("pause");
			printf("\n");
			system("cls");
		}
	} while (opcao != '0');
}

void editarCadastroDoFuncionario(int *quantidadeFuncionario, Funcionario *funcionario)
{
	char opcao;

	if (*quantidadeFuncionario == 0)
	{
		printf("\n\nNENHUM FUNCIONARIO CADASTRADO!!\n\n");
		system("pause");
		system("cls");
		return;
	}

	system("cls");
	printf("\n----EDITAR CADASTRO DE FUNCIONARIOS----\n");
	Funcionario *funcionarioEncontrado = procurarFuncionarioPorCPF(quantidadeFuncionario, funcionario);
	if (funcionarioEncontrado == NULL)
	{
		return;
	}

	do
	{
		fflush(stdin);
		printf("\nOque deseja editar: \n\n");
		printf("[1] NOME\n");
		printf("[2] IDADE\n");
		printf("[3] SEXO\n");
		printf("[4] FUN��O\n");
		printf("[5] SALARIO\n\n");
		printf("[0] SAIR\n");
		opcao = getche();

		switch (opcao)
		{
		case '1':
			printf("\n Atualizar nome: ");
			gets(funcionarioEncontrado->nome);
			printf("\nNOVO CADASTRO\n");
			mostraFuncionario(funcionarioEncontrado);
			menuContinuarEditando(quantidadeFuncionario, funcionario);
			break;

		case '2':
			printf("\nAtualizar idade: ");
			scanf("%f", &funcionarioEncontrado->idade);
			printf("\nNOVO CADASTRO\n");
			mostraFuncionario(funcionarioEncontrado);
			menuContinuarEditando(quantidadeFuncionario, funcionario);
			break;

		case '3':
			printf("\nAtualizar sexo: ");
			gets(funcionarioEncontrado->sexo);
			printf("\nNOVO CADASTRO\n");
			mostraFuncionario(funcionarioEncontrado);
			menuContinuarEditando(quantidadeFuncionario, funcionario);
			break;

		case '4':
			printf("\nAtualizar fun��o: ");
			gets(funcionarioEncontrado->funcao);
			printf("\nNOVO CADASTRO\n");
			mostraFuncionario(funcionarioEncontrado);
			menuContinuarEditando(quantidadeFuncionario, funcionario);
			break;

		case '5':
			printf("\nAtualizar salario: ");
			scanf("%f", &funcionarioEncontrado->salario);
			printf("\nNOVO CADASTRO\n");
			mostraFuncionario(funcionarioEncontrado);
			menuContinuarEditando(quantidadeFuncionario, funcionario);
			break;

		case '0':
			system("cls");
			return;
			break;

		default:
			printf("\nValor digitado invalido!\n");
			system("pause");
			system("cls");
			break;
		}
	} while (opcao != '0');

	system("pause");
	system("cls");
}

void menuContinuarEditando(int *quantidadeFuncionario, Funcionario *funcionario)
{
	char opcao;
	do
	{
		printf("\n[1] Continuar editando\n");
		printf("[2] Editar outro funcionario\n\n");
		printf("[0] sair");
		opcao = getche();
		switch (opcao)
		{
		case '1':
			system("cls");
			return;

		case '2':
			system("cls");
			editarCadastroDoFuncionario(quantidadeFuncionario, funcionario);
			return;

		case '0':
			system("cls");
			break;

		default:
			printf("\nVALOR DIGITADO INVALIDO!!\n\n");
			system("pause");
			system("cls");
		}
	} while (opcao != '0');
	menuAdm(quantidadeFuncionario, funcionario);
	system("cls");
}

void mostraFuncionario(Funcionario *funcionario)
{
	printf("\nCPF: %s \n", funcionario->cpf);
	printf("Nome: %s \n", funcionario->nome);
	printf("Idade: %.0f \n", funcionario->idade);
	printf("Sexo: %s \n", funcionario->sexo);
	printf("Fun��o: %s \n", funcionario->funcao);
	printf("Sal�rio: R$ %.2f \n", funcionario->salario);
}
