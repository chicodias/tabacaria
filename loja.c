/* 
    Arquivo: loja.h
    Autor: Alline
    Contém as funções utilizadas nas rotinas de execução da tabacaria
 */

#include "loja.h"


/*  CAdastra um produto */
int cad_produto()
{
    int i = 0;

	printf("\nDigite o nome do produto, o código, preço, o tipo e fornecedor, em seguida o armazenamento: \n");
    printf("\n( Para concluir o cadastro e voltar ao menu, digite enter )\n");

	while (1) {

        printf("oiii teste\n");
		fgets( produtos[i].nome, lim, stdin);
		scanf("%li", &produtos[i].codigo);
		scanf("%.2f", &produtos[i].preco);
		fgets( produtos[i].tipo, lim, stdin);
		fgets( produtos[i].fornecedor, lim, stdin);
		scanf("%d", &produtos[i].armazenamento);
		i++;

        //ESTA EM LOOP INFINITO NA ENTRADA, VERIFICAR + TARDE

		if ( produtos[i].nome == 0) {
            printf("Cadastro(s) feito!\n Voltando ao menu.");
            break;
        }

        else {
            continue;
        }
	}
    menu();
}
}

/* Cadastra um fornecedor */
int cad_fornecedor()
{
	int i = 0;

	while(1){

        printf("\nDigite o nome do(s) fornecedor(es), a especialidade e o c�digo: \n");
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

void alteracao() //dependendo da escolha altera produto ou fornecedor
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

        printf("\nDigite o c�digo do fornecedor que alterar�: \n");
        printf("\n( Para concluir as altera��es e voltar ao menu, digite enter )\n");

        scanf("%li", &x);

        if (x == '\0') {
            printf("Voltando ao menu\n");
            menu();
        }
        else{

            while(x != fn->codigo) { //verifica se o codigo que � buscado � igual ao que j� exite no programa

                *(fn++);

                if ( fn->codigo == '\0' ) {
                    printf("Fornecedor n�o encontrado!\n");
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
                    free(fn); //esse po � o que foi contado ou o valor inicial?
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

/* Altera um produto */
int alt_produto(produto *pd)
{
	long int x;
	char op;

    pd = (malloc ( sizeof (produtos)));

	while(1){

        printf("\nDigite o c�digo do produto que alterar�: \n");
        printf("\n( Para concluir as altera��es e voltar ao menu, digite \"0\" )\n");

        scanf("%li", &x);

        while(x != pd->codigo) { //verifica se o codigo que � buscado � igual ao que j� exite no programa

            *(pd++);

            if ( pd->codigo == '\0' ) {
                printf("Produto n�o encontrado!\n");
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
                free(pd); //esse po � o que foi contado ou o valor inicial?
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

/* Abre o menu */
void menu ()
{
	int x, x1;
	char s;

	printf("\t\tMENU\n\n");
	printf("Escolha uma das op��es:\n");
	printf("1. Cadastro e Altera��o \n2. Visualiza��o\n3. Vendas \n4. Sair\n");

	scanf("%d", &x);

	switch (x)
	{
		case 1:
			printf("\nSelecione a a��o desejada:\n");
			printf("1. Cadastro\n2. Altera��o\n3. Voltar ao menu principal\n");
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

