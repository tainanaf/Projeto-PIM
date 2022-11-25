#include <stdio.h>
#include <locale.h>

typedef struct {
  int id;
  char fornecedor[30], nome[30];
  bool lactose, laticinios, gluten, acucar, gordura, integral, carne, sodio;
  float preco;
}
Produto;

void cadastrarProduto(Produto * produto, int * quantidadeProduto) {
  char novoCadastro;
  int i;
  novoCadastro = malloc(sizeof(char));
  do {
    i = *quantidadeProduto;
    fflush(stdin);
    system("cls");
    printf("======== CADASTRO DE PRODUTOS ========\n");
    printf("\nInforme o fornecedor: ");
    gets((produto + i) -> fornecedor);
    printf("Informe o nome do produto: ");
    gets((produto + i) -> nome);
    printf("Informe o preço: R$ ");
    scanf("%f", &(produto+i)->preco);
    printf("\n\n======= INFORMAÇÕES DO PRODUTO =======\n");
    (produto+i)->id = i + 1;

   (produto+i)->laticinios = perguntaSeProdutoPossui("Laticinios");
   (produto+i)->lactose = perguntaSeProdutoPossui("Lactose");
   (produto+i)->gluten = perguntaSeProdutoPossui("Gluten");
   (produto+i)->acucar= perguntaSeProdutoPossui("Açucar");
   (produto+i)->gordura = perguntaSeProdutoPossui("Gordura");
   (produto+i)->integral = perguntaSeProdutoPossui("Integral");
   (produto+i)->carne = perguntaSeProdutoPossui("Carne");
   (produto+i)->sodio = perguntaSeProdutoPossui("Sodio");


   *quantidadeProduto = *quantidadeProduto + 1;

    printf("\n\n-----------------------------------");
    printf("\n  CADASTRO REALIZADO COM SUCESSO! \a\n");
    printf("-----------------------------------\n");
    printf("\n[1] REALIZAR UM NOVO CADASTRO");
    printf("\n[2] VOLTAR PARA O MENU\n");
    fflush(stdin);
    novoCadastro = getche();
    while (novoCadastro != '1' && novoCadastro != '2') {
      printf("\nOPÇÃO INVÁLIDA.\nPOR FAVOR, DIGITE NOVAMENTE: ");
      novoCadastro = getche();
    }
  } while (novoCadastro != '2');

}

void simulador() {
  float po, pc, pv, comp;
  char opcao;
  system("cls");
  do {
    printf("====== SIMULADOR DE PREÇOS ======\n\n");
    printf("Digite o valor do produto: ");
    scanf("%f", & po);
    if (po < 3) {
      printf("\nVALORES MENORES DO QUE");
      printf("\nR$ 3,00 NÃO SÃO ACEITOS!!\n");
    } else if (po <= 5) {
      pc = po * 0.15;
      pv = pc + 2;
      comp = (1 - (pv / po)) * 100;
      printf("\n\nPREÇO DE COMPRA: R$ %.2f\n", pc);
      printf("\nPREÇO DE VENDA: R$ %.2f\n", pv);
      printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
    } else if (po <= 10) {
      pc = po * 0.2;
      pv = pc + 3;
      comp = (1 - (pv / po)) * 100;
      printf("\n\nPREÇO DE COMPRA: R$ %.2f\n", pc);
      printf("\nPREÇO DE VENDA: R$ %.2f\n", pv);
      printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
    } else if (po <= 30) {
      pc = po * 0.25;
      pv = pc + 4.5;
      comp = (1 - (pv / po)) * 100;
      printf("\n\nPREÇO DE COMPRA: R$ %.2f\n", pc);
      printf("\nPREÇO DE VENDA: R$ %.2f\n", pv);
      printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
    } else if (po <= 70) {
      pc = po * 0.3;
      pv = pc + 6;
      comp = (1 - (pv / po)) * 100;
      printf("\n\nPREÇO DE COMPRA: R$ %.2f\n", pc);
      printf("\nPREÇO DE VENDA: R$ %.2f\n", pv);
      printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
    } else if (po <= 999999999) {
      pc = po * 0.35;
      pv = pc + 7.5;
      comp = (1 - (pv / po)) * 100;
      printf("\n\nPREÇO DE COMPRA: R$ %.2f\n", pc);
      printf("\nPREÇO DE VENDA: R$ %.2f\n", pv);
      printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
    } else {
      printf("\nVALOR INVÁLIDO!\n");
    }
    printf("\n\n[1] FAZER OUTRA SIMULAÇÃO\n[0] SAIR\n");
    opcao = getche();
    system("cls");
  } while (opcao != '0');

}

void listarProdutos(int * quantidadeProduto, Produto * produto) {
  system("cls");
  printf("======= LISTA DE PRODUTOS =======\n");
  for (int i = 0; i < * quantidadeProduto; i++) {
    mostraProduto(produto + i);
  }
  printf("\n\n");
  system("pause");
}
void mostraSimouNao(bool condicao, char nome[30]) {
  if (condicao)
    printf("%s: SIM\n", nome);
  else
    printf("%s: NÃO\n", nome);
}

void buscarProduto( Produto *produto, int *quantidadeProduto){
    if (*quantidadeProduto == 0)
	{
		printf("\n\nNENHUM PRODUTO CADASTRADO!!\n\n");
		system("pause");
		system("cls");
		return;
	}

	char opcao;
	do
	{
		printf("\n\n-----------BUSCAR POR-----------\n");
		printf("[1] ID\n");
		printf("[2] Fornecedor\n");
		printf("[3] Nome\n");
		printf("[4] Informações Nutricionais\n");
		printf("[0] Sair\n");
		printf("Escolha uma opção: ");
		opcao = getche();
		fflush(stdin);
		switch (opcao)
		{

        case '1':
            mostrarProdutoPorId(quantidadeProduto,produto);
            system("cls");
            return;
            break;
		case '2':
		    buscarProdutoPorFornecedor(produto,quantidadeProduto);
			system("cls");
			return;
			break;

		case '3':
		    buscarProdutoPorNome(produto,quantidadeProduto);
			system("cls");
			return;
			break;

		case '4':
            buscarProdutoPorInformacoesNutricionais(produto,quantidadeProduto);
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

void buscarProdutoPorNome (Produto *produto,int *quantidadeProduto){
    fflush(stdin);
    system("cls");
	bool achou = false;
	char nome[30], opcao;
	int funcionarioEncontrado = 0;

	printf("\nInforme o nome do Produto: ");
	gets(nome);
    system("cls");
	for (int i = 0; i < *quantidadeProduto; i++){

        if (strcmp(nome, (produto + i)->nome) == 0)
        {
            achou = true;
            mostraProduto(produto + i);

        }
	}

	if (achou == false){
		printf("\nO NOME DIGITADO NÃO FOI ENCONTRADO! \n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1')
		{
			system("cls");
			buscarProdutoPorNome(produto, quantidadeProduto);
		}
	}
	printf("\n");
	system("pause");
}

void buscarProdutoPorFornecedor (Produto *produto,int *quantidadeProduto){
    fflush(stdin);
     system("cls");
	bool achou = false;
	char nome[30], opcao;

	printf("\nINFORME O FORNECEDOR: ");
	gets(nome);
	system("cls");
	for (int i = 0; i < *quantidadeProduto; i++)
	{
		if (strcmp(nome, (produto + i)->fornecedor) == 0)
		{
			achou = true;

			mostraProduto(produto + i);
		}
	}

	if (achou == false)
	{
		printf("\nO NOME DIGITADO NÃO FOI ENCONTRADO! \n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1')
		{
			system("cls");
			buscarProdutoPorNome(produto, quantidadeProduto);
			return;
		}
	}
	system("pause");
	system("cls");
	return;

}

void buscarProdutoPorInformacoesNutricionais(Produto *produto,int *quantidadeProduto){
        system("cls");
        if(quantidadeProduto == 0){
            printf("\nNenhum Produto Cadastrado!\n");
            system("pause");
            system("cls");
            return;
        }
    bool produtoContem;
    char opcao;
    do
	{
		printf("\n\n-----------BUSCAR POR-----------\n");
		printf("[1] Laticínios\n");
		printf("[2] Lactose\n");
		printf("[3] Gluten\n");
		printf("[4] Açucar\n");
		printf("[5] Gordura\n");
		printf("[6] Integral\n");
		printf("[7] Carne\n");
		printf("[8] Sodio\n");
		printf("[0] Sair\n");
		printf("\nEscolha uma opção: ");
		opcao = getche();
		fflush(stdin);
		switch (opcao){
		case '1':
            produtoContem = perguntaSeProdutoDeveTer("Laticinios");
            system("cls");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->laticinios == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNENHUM PRODUTO ENCONTRADO\n");
                    system("pause");
                    system("cls");
                }
            }

            system("pause");
            system("cls");

			return;
			break;

		case '2':
		     produtoContem = perguntaSeProdutoDeveTer("Lactose");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->lactose == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNENHUM PRODUTO ENCONTRADO\n");
                    system("pause");
                    system("cls");
                }
            }
            system("pause");
			system("cls");
			return;
			break;

		case '3':
		    produtoContem = perguntaSeProdutoDeveTer("Gluten");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->gluten == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNenhum produto encontrado\n");
                }
            }
            system("pause");
			system("cls");
			return;
			break;
		case '4':
		    produtoContem = perguntaSeProdutoDeveTer("Açucar");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->acucar == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNENHUM PRODUTO ENCONTRADO\n");
                    system("pause");
                    system("cls");
                }
            }
            system("pause");
			system("cls");
			return;
			break;

		case '5':
			produtoContem = perguntaSeProdutoDeveTer("Gordura");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->gordura == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNENHUM PRODUTO ENCONTRADO\n");
                    system("pause");
                    system("cls");
                }
            }
            system("pause");
			system("cls");
			return;
			break;
		case '6':
			produtoContem = perguntaSeProdutoDeveTer("Integral");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->integral == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNENHUM PRODUTO ENCONTRADO\n");
                    system("pause");
                    system("cls");
                }
            }
            system("pause");
			system("cls");
			return;
			break;
        case '7':
        produtoContem = perguntaSeProdutoDeveTer("Carne");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->carne == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNENHUM PRODUTO ENCONTRADO\n");
                    system("pause");
                    system("cls");
                }
            }
            system("pause");
			system("cls");
        return;
        break;

        case '8':
        produtoContem = perguntaSeProdutoDeveTer("Sodio");
            for (int i = 0; i < *quantidadeProduto;i++){
                if((produto+i)->sodio == produtoContem){
                    mostraProduto(produto+i);
                }
                else{
                    printf("\nNENHUM PRODUTO ENCONTRADO\n");
                    system("pause");
                    system("cls");
                }
            }
            system("pause");
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

void mostraProduto(Produto *produto){
    printf("\nID: %d \n",produto->id);
    printf("Fornecedor: %s \n", produto->fornecedor);
    printf("Produto: %s \n", produto->nome);
    printf("Preço: R$%.2f \n\n", produto->preco);
    fflush(stdin);
    printf("\n======= INFORMAÇÕES DO PRODUTO =======\n");
    mostraSimouNao(produto->lactose, "Lactose");
    mostraSimouNao(produto->laticinios, "Laticíneos");
    mostraSimouNao(produto->gluten, "Gluten");
    mostraSimouNao(produto->acucar, "Açucar");
    mostraSimouNao(produto->gordura, "Gordura");
    mostraSimouNao(produto->integral, "Integral");
    mostraSimouNao(produto->sodio, "Sodio");
    mostraSimouNao(produto->carne, "Carne");
    printf("- - - - - - - - - - - - - - - - - - -\n\n");
}

int perguntaSeProdutoPossui(char informacao[10]){
    char opcao;
    fflush(stdin);
    printf("\nProduto possui %s? (s/n): ",informacao);
    do {
      opcao = getche();
      switch (opcao) {
      case 's':
        return true;
      case 'n':
        return false;
      default:
        printf("\n\nCARACTER INVÁLIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
      }
    } while (opcao != 's' && opcao != 'n');
    return false;
}

int perguntaSeProdutoDeveTer(char informacao[10]){
    char opcao;
    fflush(stdin);
    printf("\n\nFiltrar por produtos que tenham %s (s) ou que não contenham %s ?(n)\n",informacao,informacao);
    do {
      opcao = getche();
      switch (opcao) {
      case 's':
        return true;
      case 'n':
        return false;
      default:
        printf("\n\nCARACTER INVÁLIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
      }
    } while (opcao != 's' && opcao != 'n');
    return false;
}

Produto *procurarProdutoPorId(int *quantidadeProduto, Produto *produto)
{
	bool achou = false;
	int id;
	char opcao;

	fflush(stdin);

	printf("\nInforme o ID: ");
	scanf("%d",&id);
	achou = false;
	for (int i = 0; i < *quantidadeProduto; i++)
	{
		if ((produto+i)->id == id)
		{
			achou = true;
			mostraProduto(produto + i);
			printf("\n");
			system("pause");
			system("cls");
			return (produto + i);
		}
	}


		printf("\nO produto digitado não foi encontrado!\n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1')
		{   *procurarProdutoPorId(quantidadeProduto,produto);
			system("cls");
			return;
		}

		if (opcao == '0')
		{
			system("cls");
			mostraMenuColaborador(produto,quantidadeProduto);
		}

        return NULL;
}

void  alteraInformacoesDorProduto ( Produto *produto,  int *quantidadeProduto)
{
	char opcao;

	if (*quantidadeProduto == 0)
	{
		printf("\n\nNENHUM PRODUTO CADASTRADO!!\n\n");
		system("pause");
		system("cls");
		return;
	}

	system("cls");
	printf("\n----EDITAR INFORMAÇÃOES DO PRODUTO----\n");
	Produto *produtoEncontrado = procurarProdutoPorId(quantidadeProduto, produto);
	if (produtoEncontrado == NULL)
	{
		return;
	}

	do
	{
		fflush(stdin);
		printf("\n- - - - - - - - - -EDITAR INFORMAÇÕES- - - - - - - - - -\n\n");
		printf("[1] FORNECEDOR\n");
		printf("[2] NOME\n");
		printf("[3] PREÇO\n");
		printf("\n======= INFORMAÇÕES DO PRODUTO =======\n\n");
		printf("[4] LATICINIOS\n\n");
		printf("[5] LACTOSE\n\n");
		printf("[6] GLUTÉN\n\n");
		printf("[7] AÇUCAR\n\n");
		printf("[8] GORDURA\n\n");
		printf("[9] INTEGRAL\n\n");
		printf("[10] CARNE\n\n");
		printf("[11] SODIO\n\n");
		printf("[0] SAIR\n");
		 printf("- - - - - - - - - - - - - - - - - - -\n\n");
		opcao = getche();

		switch (opcao)
		{
		case '1':
			printf("\n Atualizar fornecedor: ");
			gets(produtoEncontrado->fornecedor);
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
			mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

		case '2':
			printf("\nAtualizar nome: ");
			gets(produtoEncontrado->nome);
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
			mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

		case '3':
			printf("\nAtualizar preço: ");
			scanf("%f", &produtoEncontrado->preco);
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
			mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

		case '4':
			printf("\nAtualizar Laticinios: ");
            produtoEncontrado->laticinios = perguntaSeProdutoPossui("Laticinios");
			printf("\n=======NOVO CADASTRO=======\n");;
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

		case '5':
			printf("\nAtualizar Lactose: ");
			produtoEncontrado->lactose = perguntaSeProdutoPossui("Lactose");
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

		case '6':
			printf("\nAtualizar Gluten: ");
			produtoEncontrado->gluten= perguntaSeProdutoPossui("Gluten");
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

        case '7':
			printf("\nAtualizar Açucar: ");
			produtoEncontrado->acucar= perguntaSeProdutoPossui("Açucar");
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

        case '8':
			printf("\nAtualizar Gordura: ");
			produtoEncontrado->gordura= perguntaSeProdutoPossui("Gordura");
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

        case '9':
			printf("\nAtualizar Integral: ");
			produtoEncontrado->integral= perguntaSeProdutoPossui("Integral");
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;
        case '10':
			printf("\nAtualizar Carne: ");
			produtoEncontrado->carne= perguntaSeProdutoPossui("Carne");
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
			break;

        case '11':
			printf("\nAtualizar Sodio: ");
			produtoEncontrado->sodio= perguntaSeProdutoPossui("Sodio");
			system("cls");
			printf("\n=======NOVO CADASTRO=======\n");
            mostraProduto(produtoEncontrado);
			menuContinuarEditandoProduto(quantidadeProduto, produto);
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

void menuContinuarEditandoProduto(int *quantidadeProduto, Produto *produto)
{

	char opcao;
	do
	{
		printf("\n[1] Continuar editando\n");
		printf("[2] Editar outro produto\n\n");
		printf("[0] sair");
		opcao = getche();
		switch (opcao)
		{
		case '1':
			system("cls");
			return;

		case '2':
			system("cls");
			alteraInformacoesDorProduto(produto,quantidadeProduto);
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

}

void mostrarProdutoPorId(int *quantidadeProduto, Produto *produto)
{
	bool achou = false;
	int id;
	char opcao;

	fflush(stdin);

	printf("\nInforme o ID: ");
	scanf("%d",&id);
	achou = false;
	for (int i = 0; i < *quantidadeProduto; i++)
	{
		if ((produto+i)->id == id)
		{
			achou = true;
			mostraProduto(produto + i);
			printf("\n");
			system("pause");
			system("cls");
			return;
		}
	}


		printf("\nO produto digitado não foi encontrado!\n\n");
		printf("[1] Tentar novamente\n\n");
		printf("[0] Sair\n");
		opcao = getche();
		if (opcao == '1')
		{   *procurarProdutoPorId(quantidadeProduto,produto);
			system("cls");
			return;
		}

		if (opcao == '0')
		{
			system("cls");
			mostraMenuColaborador(produto,quantidadeProduto);
		}

        return NULL;
}
