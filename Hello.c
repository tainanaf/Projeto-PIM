#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  char nome[30], cpf[20], sexo[30], funcao[30], login[50], senha[30];
  float salario, idade;
} Funcionario;

void procurarFuncionario(int quantidadeFuncionario, Funcionario *funcionario);
void menuAdm(int *quantidadeFuncionario, Funcionario *funcionario);
void cadastrarFuncionarios(Funcionario *p, int *quantidadeFuncionario);
void listarFuncionarios(int *quantidadeFuncionario, Funcionario *p);
void procurarFuncao(int *quantidadeFuncionario, Funcionario *p);
void procurarNome(int quantidadeFuncionario, Funcionario *p);
Funcionario *procurarCpf(int *quantidadeFuncionario, Funcionario *p);
void loginCol(Funcionario *p, int *quantidadeFuncionario);
void loginAdm();
void procurarFuncionario(int quantidadeFuncionario, Funcionario *funcionario);
void editarCadastro(int *quantidadeFuncionario, Funcionario *p);
char menuInicial();
void mostraFuncionario(Funcionario *funcionario);

void main()
{
  setlocale(LC_ALL, "portuguese");
  char opcao;
  int *quantidadeFuncionario;
  Funcionario *funcionario;
  funcionario = malloc(10 * sizeof(Funcionario));
  quantidadeFuncionario = malloc(sizeof(int));
  *quantidadeFuncionario = 0;
  do
  {
    opcao = menuInicial();

    switch (opcao)
    {
    case '1':
      loginAdm();
      menuAdm(quantidadeFuncionario, funcionario);
      system("cls");
      break;
    case '2':
      loginCol(funcionario, quantidadeFuncionario);
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

void menuAdm(int *quantidadeFuncionario, Funcionario *funcionario)
{
  char opcao;

  do
  {
    printf("=================================\n--------  LASTFOOD MENU  --------\n=================================\n\n");
    printf("[1] CADASTRAR NOVO FUNCIONÁRIO\n");
    printf("[2] LISTA DE FUNCIONÁRIOS \n");
    printf("[3] BUSCAR FUNCIONÁRIO \n");
    printf("[4] EDITAR CADASTRO DO FUNCIONARIO");
    printf("[0] SAIR \n");
    printf("\nEscolha uma opção: ");
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
      editarCadastro(quantidadeFuncionario, funcionario);
      break;
    case '0':
      printf("\n\nSESSÃO FINALIZADA \n\n");
      system("pause");
      break;
    default:
      printf("\nESSA OPÇÃO NÃO EXISTE! ESCOLHA UMA OPÇÃO VÁLIDA \n");
    }
  } while (opcao != '0');
}

void cadastrarFuncionarios(Funcionario *p, int *quantidadeFuncionario)
{
  char novoCadastro;
  int i;
  do
  {
    i = *quantidadeFuncionario;
    fflush(stdin);
    system("cls");
    printf("=====CADASTRO DE FUNCIONÁRIO=====\n");
    printf("\nInforme o CPF do funcionário (sem hífen): ");
    gets((p + i)->cpf);
    printf("Informe o nome do funcionário: ");
    gets((p + i)->nome);
    printf("Informe a idade do funcionário: ");
    fflush(stdin);
    scanf("%f", &(p + i)->idade);
    fflush(stdin);
    printf("Informe o sexo do funcionário: ");
    gets((p + i)->sexo);
    printf("Informe o cargo do funcionário: ");
    gets((p + i)->funcao);
    printf("Informe o salário do funcionário: R$ ");
    scanf("%f", &(p + i)->salario);
    fflush(stdin);
    printf("\n----------CRIANDO LOGIN----------\nInforme o login do funcionário: ");
    gets((p + i)->login);
    fflush(stdin);
    printf("Informe a senha do funcionário: ");
    gets((p + i)->senha);

    *quantidadeFuncionario = *quantidadeFuncionario + 1;

    printf("\nCadastro realizado com sucesso! \a\n");
    printf("\n[1] Realizar um novo cadastro");
    printf("\n[2] Voltar para o menu\n");
    novoCadastro = getche();
    while (novoCadastro != '1' && novoCadastro != '2')
    {
      printf("\nOPÇÃO INVÁLIDA.\nPOR FAVOR, DIGITE NOVAMENTE: ");
      novoCadastro = getche();
    }
  } while (novoCadastro != '2');
}

void listarFuncionarios(int *quantidadeFuncionario, Funcionario *p)
{
  int i;
  if (*quantidadeFuncionario == 0)
  {
    printf("\nNENHUM FUNCIONÁRIO CADASTRADO!!\n\n");
    return;
  }
  printf("\n\n======= LISTA DE FUNCIONÁRIOS =======\n\n");
  for (i = 0; i < *quantidadeFuncionario; i++)
  {
    mostraFuncionario(p + i);
    printf("- - - - - - - - - - - - - - - - - - -\n");
  }
}

void procurarFuncao(int *quantidadeFuncionario, Funcionario *p)
{
  bool achou = false;
  char funcao[30];
  int i;

  fflush(stdin);
  if (*quantidadeFuncionario == 0)
  {
    printf("\nNENHUM CARGO CADASTRADO!!\n\n");
    return;
  }
  printf("\nINFORME O CARGO DO FUNCIONÁRIO: ");
  gets(funcao);
  achou = false;
  for (i = 0; i < *quantidadeFuncionario; i++)
  {
    if (strcmp(funcao, (p + i)->funcao) == 0)
    {
      achou = true;
      mostraFuncionario(p + i);
    }
  }
  if (achou == false)
  {
    printf("\nO CARGO DIGITADO NÃO FOI ENCONTRADO! \n\n");
  }
}

void procurarNome(int quantidadeFuncionario, Funcionario *p)
{
  bool achou = false;
  char nome[30];

  fflush(stdin);
  if (quantidadeFuncionario == 0)
  {
    printf("\nNENHUM FUNCIONARIO CADASTRADO COM ESTE NOME!!\n\n");
    return;
  }
  printf("\nINFORME O NOME COMPLETO DO FUNCIONÁRIO: ");
  gets(nome);
  for (int i = 0; i < quantidadeFuncionario; i++)
  {
    if (strcmp(nome, (p + i)->nome) == 0)
    {
      achou = true;

      mostraFuncionario(p + i);
    }
  }
  if (achou == false)
  {
    printf("\nO NOME DIGITADO NÃO FOI ENCONTRADO! \n\n");
  }
}

Funcionario *procurarCpf(int *quantidadeFuncionario, Funcionario *funcionario)
{
  bool achou = false;
  char cpf[20];
  int i;

  fflush(stdin);
  if (*quantidadeFuncionario == 0)
  {
    printf("\nNENHUM CPF CADASTRADO!!\n\n");
    return NULL;
  }
  printf("\nINFORME O CPF DO FUNCIONÁRIO (SEM HÍFEN): ");
  gets(cpf);
  achou = false;
  for (i = 0; i < *quantidadeFuncionario; i++)
  {
    if (strcmp(cpf, (funcionario + i)->cpf) == 0)
    {
      achou = true;
      mostraFuncionario(funcionario + i);
      return (funcionario + i);
    }
  }
  if (achou == false)
  {
    printf("O CPF digitado não foi encontrado! Digite um CPF válido! \n\n");
  }
  return NULL;
}

void loginCol(Funcionario *p, int *quantidadeFuncionario)
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
    printf("\nUSUÁRIO: ");
    scanf("%s", &login1);
    printf("SENHA: ");
    scanf("%s", &senha1);
    for (i = 0; i < *quantidadeFuncionario; i++)
    {
      if (strcmp((p + i)->login, login1) == 0 && strcmp((p + i)->senha, senha1) == 0)
      {
        achou = true;

        printf("\n---------------------------------\n\tLOGIN CONCLUÍDO!\n---------------------------------\n\n");
        printf("\tSEJA BEM VINDO \n\t%s!!\n\n", (p + i)->nome);
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
  } while (strcmp((p + i)->login, login1) != 0 || strcmp((p + i)->senha, senha1) != 0);
}

void loginAdm()
{
  system("cls");
  char login[50] = "adm", login1[50], senha[8] = "1234", senha1[8];
  printf("---------------------------------\n       LOGIN ADMINISTRADOR\n---------------------------------\n");
  do
  {
    fflush(stdin);
    printf("\nUSUÁRIO: ");
    scanf("%s", &login1);
    printf("SENHA: ");
    scanf("%s", &senha1);
    if (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0)
    {
      printf("\nLOGIN INCORRETO.");
      printf("\nPOR FAVOR, TENTE NOVAMENTE: \n");
    }
  } while (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0);
  printf("\n---------------------------------\n        LOGIN CONCLUÍDO!\n---------------------------------\n\n");
  system("pause");
  system("cls");
}

void procurarFuncionario(int quantidadeFuncionario, Funcionario *funcionario)
{
  char opcao;
  printf("\n\n-----------BUSCAR POR-----------\n");
  printf("[1] NOME\n");
  printf("[2] CPF\n");
  printf("[3] FUNÇÃO\n\n");
  printf("Escolha uma opção: ");
  opcao = getche();
  fflush(stdin);
  switch (opcao)
  {
  case '1':
    procurarNome(quantidadeFuncionario, funcionario);
    system("pause");
    system("cls");
    break;
  case '2':
    procurarCpf(quantidadeFuncionario, funcionario);
    system("pause");
    system("cls");
    break;
  case '3':
    procurarFuncao(quantidadeFuncionario, funcionario);
    system("pause");
    system("cls");
    break;
  default:
    printf("\nESSA OPÇÃO NÃO EXISTE! ESCOLHA UMA OPÇÃO VÁLIDA \n");
  }
}

void editarCadastro(int *quantidadeFuncionario, Funcionario *p)
{
  char opcao;
  Funcionario *funcionarioEncontrado = procurarCpf(quantidadeFuncionario, p);
  if (funcionarioEncontrado == NULL)
  {
    system("pause");
    return;
  }
  do
  {
    printf("Oque deseja editar: \n");
    printf("[1] NOME\n");
    printf("[2] IDADE\n");
    printf("[3] SEXO\n");
    printf("[4] FUNÇÃO\n");
    printf("[5] SALARIO\n");
    printf("[0] SAIR");
    opcao = getche();

    switch (opcao)
    {
    case '1':
      printf("Digite o novo nome: ");
      gets(funcionarioEncontrado->nome);
      mostraFuncionario(funcionarioEncontrado);
      break;

    default:
      break;
    }
  } while (opcao != '0');

  system("pause");
  system("cls");
}

char menuInicial()
{

  char opcao;

  printf("================================\n-----  Com.TI.go SISTEMAS  -----\n================================\n\n");
  printf("\n[1] ADMINISTRADOR\n\n");
  printf("[2] COLABORADOR\n");
  printf("[0] SAIR\n");
  opcao = getche();
  while (opcao != '1' && opcao != '2' && opcao != '0')
  {
    printf("\n--------------------------------\nOpção incorreta! \nPor favor, digite novamente: ");
    opcao = getche();
  }
  return opcao;
}

void mostraFuncionario(Funcionario *funcionario)
{

  printf("\nCPF: %s \n", funcionario->cpf);
  printf("Nome: %s \n", funcionario->nome);
  printf("Idade: %.0f \n", funcionario->idade);
  printf("Sexo: %s \n", funcionario->sexo);
  printf("Função: %s \n", funcionario->funcao);
  printf("Salário: R$ %.2f \n", funcionario->salario);
}