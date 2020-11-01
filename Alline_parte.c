#include "biblio.h"

#define lim 100
#define prod 500

produto produtos[prod], *pd;
fornecedores fornecedor[lim], *fn;

//declarando as funÃ§Ãµes do programa

void cadastro();
int cad_fornecedor();
int cad_produto();
void menu();

void cadastro() //dependendo da escolha cadastrara produto ou fornecedor
{
	int x;

  	printf("Digite o que deseja cadastrar: \n");
  	printf("1.Fornecedor \n2.Produto\n");

  	scanf("%d", &x);

	if (x == 1)
	{
		cad_fornecedor();
		printf("\n");
	}

	else
	{
		cad_produto();
        printf("\n");
	}
}

int cad_fornecedor()
{
	int i = 0;

	while(1){

        printf("\nDigite o nome do(s) fornecedor(es), a especialidade e o código: \n");
        printf("\n( Para concluir o cadastro e voltar ao menu, digite enter)\n");

        fgets( fornecedor[i].nome,lim, stdin );
        fgets( fornecedor[i].especialidade,lim, stdin );
        scanf("%li", &fornecedor[i].codigo); //NAO ESTA FUNCIONANDO, VERIFICAR
        i++;

        if ( fornecedor[i].nome == '\0') {
            printf("Cadastro(s) feito!");
            break;
        }
	}
	menu();
}

int cad_produto()
{
	int i = 0;

	printf("\nDigite o nome do produto, o código, o tipo e fornecedor, em seguida o tipo de armazenamento dele: \n");
    printf("\n( Para concluir o cadastro e voltar ao menu, digite enter )\n");

	while (1) {

		fgets( produtos[i].nome, lim, stdin);
		scanf("%li", &produtos[i].codigo);
		fgets( produtos[i].tipo, lim, stdin);
		fgets( produtos[i].fornecedor, lim, stdin);
		scanf("%d", &produtos[i].armazenamento);
		i++;

        //ESTA EM LOOP INFINITO NA ENTRADA, VERIFICAR + TARDE

		if ( produtos[i].nome == '\0') {
            printf("Cadastro(s) feito!");
            break;
        }

        else {
            continue;
        }
	}
    menu();
}

void alteracao() //dependendo da escolha cadastrara produto ou fornecedor
{
	int x;

  	printf("\nDigite o que deseja alterar: \n");
  	printf("1.Fornecedor \n2.Produto\n");

  	scanf("%d", &x);

	if (x == 1)
	{
		alt_fornecedor();
	}

	else
	{
		alt_produto();
	}
}

int alt_fornecedor(fornecedores *fn)
{
	long int x;
	char op;

    fn = (malloc ( sizeof (fornecedor)));

	while(1){

        printf("\nDigite o código do fornecedor que alterará: \n");
        printf("\n( Para concluir as alterações e voltar ao menu, digite enter )\n");

        scanf("%li", &x);

        if (x == '\0') {
            printf("Voltando ao menu\n");
            menu();
        }
        else{

            while(x != fn->codigo) { //verifica se o codigo que é buscado é igual ao que já exite no programa

                *(fn++);

                if ( fn->codigo == '\0' ) {
                    printf("Fornecedor não encontrado!\n");
                    alteracao();
                }
                else {
                    break;
                }
            }

            while(1){
                printf("Digite os novos dados do fornecedor %li. (nome, especialidade, codigo)\n", x);
                printf("Para apagar um fornecedor, aperte enter\n");

                fgets( fn->nome,lim, stdin );
                fgets( fn->especialidade,lim, stdin );
                scanf("%li", fn->codigo);

                if ( fn->nome == '\0') {
                    free(fn); //esse po é o que foi contado ou o valor inicial?
                }

                printf("Deseja concluir e voltar ao menu? (S/N) \n\n");
                scanf("%c", &op);
                if ( op == 'S' ){
                    menu();
                }
                else {
                    continue;
                }
            }
        }
    }
}

int alt_produto(produto *pd)
{
	long int x;
	char op;

    pd = (malloc ( sizeof (produtos)));

	while(1){

        printf("\nDigite o código do produto que alterará: \n");
        printf("\n( Para concluir as alterações e voltar ao menu, digite \"0\" )\n");

        scanf("%li", &x);

        while(x != pd->codigo) { //verifica se o codigo que é buscado é igual ao que já exite no programa

            *(pd++);

            if ( pd->codigo == '\0' ) {
                printf("Produto não encontrado!\n");
                alteracao();
            }
            else {
                break;
            }
        }

        while(1){
            printf("Digite os novos dados do produto %li. (nome, especialidade, codigo)\n", x);
            printf("Para apagar um fornecedor, aperte enter\n");

            fgets( pd->nome, lim, stdin);
            scanf("%li", pd->codigo);
            fgets( pd->tipo, lim, stdin);
            fgets( pd->fornecedor, lim, stdin);
            scanf("%d", pd->armazenamento);

            if ( pd->nome == '\0') {
                free(pd); //esse po é o que foi contado ou o valor inicial?
            }

            printf("Deseja concluir e voltar ao menu? (S/N) \n\n");
            scanf("%c", &op);
            if ( op == 'S' ){
                menu();
            }
            else {
                continue;
            }
        }
    }
}

void menu ()
{
	int x, x1;
	char s;

	printf("\t\tMENU\n\n");
	printf("Escolha uma das opções:\n");
	printf("1. Cadastro e Alteração \n2. Visualização\n3. Vendas \n4. Sair\n");

	scanf("%d", &x);

	switch (x)
	{
		case 1:
			printf("\nSelecione a ação desejada:\n");
			printf("1. Cadastro\n2. Alteração\n3. Voltar ao menu principal\n");
			scanf("%d", &x1);
				if(x1 == 1) {
					cadastro();
				}
				/*
				else if(x1 == 2) {
					alteracao();
				}
                */
				else {
					menu();
				}
			break;

		case 4:
			printf("Deseja mesmo sair? S/N\n");
			scanf("%c", &s);

			if (s == 'S')
			{
				break;
			}
			else
			{
				menu();
			}
			break;
	}
}

