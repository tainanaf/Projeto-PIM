#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char nome[30], cpf[20], sexo[30], funcao[30], login[50], senha[30];
	float salario, idade;
} Funcionario;

// DECLARAÇÃO DE FUNÇÕES !!                                                                 	//
void procurarFuncionario(int *quantidadeFuncionario, Funcionario *funcionario);
void menuAdm(int *quantidadeFuncionario, Funcionario *funcionario);
void cadastrarFuncionarios(Funcionario *funcionario, int *quantidadeFuncionario);
void listarFuncionarios(int *quantidadeFuncionario, Funcionario *funcionario);
void procurarFuncionarioPorFuncao(int *quantidadeFuncionario, Funcionario *funcionario);
void procurarFuncionarioPorNome(int *quantidadeFuncionario, Funcionario *funcionario);
Funcionario* procurarFuncionarioPorCPF(int *quantidadeFuncionario, Funcionario *funcionario);
void loginFuncionario(Funcionario *funcionario, int *quantidadeFuncionario);
void loginAdministrador();
void editarCadastroDoFuncionario(int *quantidadeFuncionario, Funcionario *funcionario);
char menuInicial();
void mostraFuncionario(Funcionario *funcionario);
void menuContinuarEditando();

// VOID MAIN "PROGRAMA PRINCIPAL"//
void main() {
	setlocale(LC_ALL, "portuguese");
	char opcao;
	int *quantidadeFuncionario;
	Funcionario * funcionario;
	funcionario = malloc(10* sizeof(Funcionario));
	quantidadeFuncionario = malloc(sizeof(int));
	*quantidadeFuncionario = 0;

	do {
		opcao = menuInicial();
		switch (opcao) {
			case '1':
				loginAdministrador();
				menuAdm(quantidadeFuncionario, funcionario);
				system("cls");
				break;
			case '2':
				loginFuncionario(funcionario, quantidadeFuncionario);
				break;
			case '0':
				printf("\n\nPROGRAMA FINALIZADO! \n\n");
				system("pause");
				break;
			default:
				printf("\nESSA OPÇÃO NÃO EXISTE! ESCOLHA UMA OPÇÃO VÁLIDA \n");
		}
	} while (opcao != '0');
}

// FUNÇÕES//

void menuAdm(int *quantidadeFuncionario, Funcionario *funcionario) {
	char opcao;
	do {
		printf("=================================\n--------  LASTFOOD MENU  --------\n=================================\n\n");
		printf("[1] CADASTRAR NOVO FUNCIONÁRIO\n");
		printf("[2] LISTA DE FUNCIONÁRIOS \n");
		printf("[3] BUSCAR FUNCIONÁRIO \n");
		printf("[4] EDITAR CADASTRO DO FUNCIONARIO\n");
		printf("[0] SAIR \n");
		printf("\nEscolha uma opção: ");
		opcao = getche();
		switch (opcao) {
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
				printf("\n\nSESSÃO FINALIZADA \n\n");
				system("pause");
				break;
			default:
				printf("\nESSA OPÇÃO NÃO EXISTE! ESCOLHA UMA OPÇÃO VÁLIDA \n");
				system("pause");
				system("cls");
		}
	} while (opcao != '0');
}

void cadastrarFuncionarios(Funcionario *funcionario, int *quantidadeFuncionario) {
	char novoCadastro;
	int i;
	do {
		i = *quantidadeFuncionario;
		fflush(stdin);
		system("cls");
		printf("=====CADASTRO DE FUNCIONÁRIO=====\n");
		printf("\nInforme o CPF do funcionário (sem hífen): ");
		gets((funcionario + i)->cpf);
		printf("Informe o nome do funcionário: ");
		gets((funcionario + i)->nome);
		printf("Informe a idade do funcionário: ");
		fflush(stdin);
		scanf("%f", &(funcionario + i)->idade);
		fflush(stdin);
		printf("Informe o sexo do funcionário: ");
		gets((funcionario + i)->sexo);
		printf("Informe o cargo do funcionário: ");
		gets((funcionario + i)->funcao);
		printf("Informe o salário do funcionário: R$ ");
		scanf("%f", &(funcionario + i)->salario);
		fflush(stdin);
		printf("\n----------CRIANDO LOGIN----------\nInforme o login do funcionário: ");
		gets((funcionario + i)->login);
		fflush(stdin);
		printf("Informe a senha do funcionário: ");
		gets((funcionario + i)->senha);

		*quantidadeFuncionario = *quantidadeFuncionario + 1;

		printf("\nCadastro realizado com sucesso! \a\n");
		printf("\n[1] Realizar um novo cadastro");
		printf("\n[2] Voltar para o menu\n");
		novoCadastro = getche();
		while (novoCadastro != '1' && novoCadastro != '2') {
			printf("\nOPÇÃO INVÁLIDA.\nPOR FAVOR, DIGITE NOVAMENTE: ");
			novoCadastro = getche();
		}
	} while (novoCadastro != '2');
}

void listarFuncionarios(int *quantidadeFuncionario, Funcionario *funcionario) {
	int i;
	if (*quantidadeFuncionario == 0) {
		printf("\n\nNENHUM FUNCIONÁRIO CADASTRADO!!\n\n");
		return;
	}

	printf("\n\n======= LISTA DE FUNCIONÁRIOS =======\n\n");
	for (i = 0; i<*quantidadeFuncionario; i++) {
		mostraFuncionario(funcionario + i);
		printf("- - - - - - - - - - - - - - - - - - -\n");
	}
}

void procurarFuncionarioPorFuncao(int *quantidadeFuncionario, Funcionario *funcionario) {
	bool achou = false;
	char funcao[30], opcao;

	fflush(stdin);

	printf("\nINFORME A FUNCAO DO FUNCIONÁRIO: ");
	gets(funcao);
	achou = false;
	for (int i = 0; i < *quantidadeFuncionario; i++) {
		if (strcmp(funcao, (funcionario + i)->funcao) == 0) {
			achou = true;
			mostraFuncionario(funcionario + i);
			system("pause");
			system("cls");
		}
	}

	if (achou == false) {
		printf("\nA FUNCÃO DIGITADA NÃO FOI ENCONTRADO! \n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1') {
			system("cls");
			procurarFuncionarioPorNome(quantidadeFuncionario, funcionario);
		}
	}
}

void procurarFuncionarioPorNome(int *quantidadeFuncionario, Funcionario *funcionario) {
	fflush(stdin);
	bool achou = false;
	char nome[30], opcao;

	printf("\nINFORME O NOME  DO FUNCIONÁRIO: ");
	gets(nome);
	for (int i = 0; i < *quantidadeFuncionario; i++) {
		if (strcmp(nome, (funcionario + i)->nome) == 0) {
			achou = true;

			mostraFuncionario(funcionario + i);
			system("pause");
			system("cls");
		}
	}

	if (achou == false) {
		printf("\nO NOME DIGITADO NÃO FOI ENCONTRADO! \n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1') {
			system("cls");
			procurarFuncionarioPorNome(quantidadeFuncionario, funcionario);
		}
	}
}

Funcionario* procurarFuncionarioPorCPF(int *quantidadeFuncionario, Funcionario *funcionario) {
	bool achou = false;
	char cpf[20], opcao;

	fflush(stdin);

	printf("\nINFORME O CPF DO FUNCIONÁRIO (SEM HÍFEN): ");
	gets(cpf);
	achou = false;
	for (int i = 0; i < *quantidadeFuncionario; i++) {
		if (strcmp(cpf, (funcionario + i)->cpf) == 0) {
			achou = true;
			mostraFuncionario(funcionario + i);
			printf("\n");
			system("pause");
			system("cls");
			return (funcionario + i);
		}
	}

	if (achou == false) {
		printf("\nO CPF digitado não foi encontrado!\n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1') {
			system("cls");
			procurarFuncionarioPorCPF(quantidadeFuncionario, funcionario);
			return;
		}

		if (opcao == '0') {
			system("cls");
			menuAdm(quantidadeFuncionario, funcionario);
		}
	}

	return NULL;
}

void loginFuncionario(Funcionario *funcionario, int *quantidadeFuncionario) {
	system("cls");
	int i = 0;
	bool achou = false;
	char login1[30], senha1[30];
	if (*quantidadeFuncionario == 0) {
		printf("\nNENHUM COLABORADOR CADASTRADO!!\n\n");
		return;
	}

	printf("---------------------------------\n\tLOGIN COLABORADOR\n---------------------------------\n");
	do {
		fflush(stdin);
		printf("\nUSUÁRIO: ");
		scanf("%s", &login1);
		printf("SENHA: ");
		scanf("%s", &senha1);
		for (i = 0; i<*quantidadeFuncionario; i++) {
			if (strcmp((funcionario + i)->login, login1) == 0 && strcmp((funcionario + i)->senha, senha1) == 0)
			{
				achou = true;

				printf("\n---------------------------------\n\tLOGIN CONCLUÍDO!\n---------------------------------\n\n");
				printf("\tSEJA BEM VINDO \n\t%s!!\n\n", (funcionario + i)->nome);
				system("pause");
				system("cls");
				return i;
			}
		}

		if (achou == false) {
			printf("\nLOGIN INCORRETO.");
			printf("\nPOR FAVOR, TENTE NOVAMENTE: \n");
		}
	} while (strcmp((funcionario + i)->login, login1) != 0 || strcmp((funcionario + i)->senha, senha1) != 0);
}

void loginAdministrador() {
	system("cls");
	char login[50] = "adm", login1[50], senha[8] = "1234", senha1[8];
	printf("---------------------------------\n       LOGIN ADMINISTRADOR\n---------------------------------\n");
	do {
		fflush(stdin);
		printf("\nUSUÁRIO: ");
		scanf("%s", &login1);
		printf("SENHA: ");
		scanf("%s", &senha1);
		if (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0) {
			printf("\nLOGIN INCORRETO.");
			printf("\nPOR FAVOR, TENTE NOVAMENTE: \n");
		}
	} while (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0);
	printf("\n---------------------------------\n        LOGIN CONCLUÍDO!\n---------------------------------\n\n");
	system("pause");
	system("cls");
}

void procurarFuncionario(int *quantidadeFuncionario, Funcionario *funcionario) {
	if (*quantidadeFuncionario == 0) {
		printf("\n\nNENHUM FUNCIONARIO CADASTRADO!!\n\n");
		system("pause");
		system("cls");
		return;
	}

	char opcao;
	do {
		printf("\n\n-----------BUSCAR POR-----------\n");
		printf("[1] NOME\n");
		printf("[2] CPF\n");
		printf("[3] FUNÇÃO\n");
		printf("[0] Sair\n\n");
		printf("Escolha uma opção: ");
		opcao = getche();
		fflush(stdin);
		switch (opcao) {
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
				printf("\nESSA OPÇÃO NÃO EXISTE! ESCOLHA UMA OPÇÃO VÁLIDA \n");
				system("pause");
				printf("\n");
				system("cls");
		}
	} while (opcao != '0');
}

void editarCadastroDoFuncionario(int *quantidadeFuncionario, Funcionario *funcionario) {
	char opcao;

	if (*quantidadeFuncionario == 0) {
		printf("\n\nNENHUM FUNCIONARIO CADASTRADO!!\n\n");
		system("pause");
		system("cls");
		return;
	}

	system("cls");
	printf("\n----EDITAR CADASTRO DE FUNCIONARIOS----\n");
	Funcionario *funcionarioEncontrado = procurarFuncionarioPorCPF(quantidadeFuncionario, funcionario);
	if (funcionarioEncontrado == NULL) {
		return;
	}

	do {
		fflush(stdin);
		printf("\nOque deseja editar: \n\n");
		printf("[1] NOME\n");
		printf("[2] IDADE\n");
		printf("[3] SEXO\n");
		printf("[4] FUNÇÃO\n");
		printf("[5] SALARIO\n\n");
		printf("[0] SAIR\n");
		opcao = getche();

		switch (opcao) {
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
				printf("\nAtualizar função: ");
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

char menuInicial() {
	char opcao;

	printf("================================\n-----  Com.TI.go SISTEMAS  -----\n================================\n\n");
	printf("\n[1] ADMINISTRADOR\n");
	printf("[2] COLABORADOR\n");
	printf("[0] SAIR\n");
	opcao = getche();
	while (opcao != '1' && opcao != '2' && opcao != '0') {
		printf("\n--------------------------------\nOpção incorreta! \nPor favor, digite novamente: ");
		opcao = getche();
	}

	return opcao;
}

void menuContinuarEditando(int *quantidadeFuncionario, Funcionario *funcionario) {
	char opcao;
	do {
		printf("\n[1] Continuar editando\n");
		printf("[2] Editar outro funcionario\n\n");
		printf("[0] sair");
		opcao = getche();
		switch (opcao) {
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

void mostraFuncionario(Funcionario *funcionario) {
	printf("\nCPF: %s \n", funcionario->cpf);
	printf("Nome: %s \n", funcionario->nome);
	printf("Idade: %.0f \n", funcionario->idade);
	printf("Sexo: %s \n", funcionario->sexo);
	printf("Função: %s \n", funcionario->funcao);
	printf("Salário: R$ %.2f \n", funcionario->salario);
}
