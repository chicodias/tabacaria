/* 
    Arquivo: main.c
    Autor: Matheus Pires e Alline

    função que faz o chamado as rotinas de execução de cadastro, visualização e venda na tabacaria
 */
#include "cadastro.h"
#include "vendas.h"
#include "visualiza.h"
#include "arquivos.h"


// menu principal da aplicação
int main()
{   

    int x,x1,x2;
	char s;
    produto * estoque = NULL;
    fornecedores * fn = NULL;
    produto * vendidos = NULL;

    FILE * fp;
    char filename[20];

    printf("Digite o nome do arquivo do estoque: ");
    scanf ("%s", filename);

    estoque = AbreEstoque(filename);
    
    //inicializa os endereços que conterao os produtos e fornecedores
    // contem o endereco pra primeira pos do vetor respectivo
    
    while(1)
    {
        printf("\t\tMENU\n\n");
        printf("Escolha uma das opções:\n");
        printf("1. Cadastro \n2. Visualização\n3. Vendas\n4. Alteração \n5. Sair\n");

        scanf("%d", &x);
        
        // seleção dos modulos
        switch (x)
        {
            case 1:
                printf("Digite o que deseja cadastrar: \n");
                printf("1.Fornecedor \n2.Produto\n");

                scanf("%d", &x1);

                if (x1 == 1)
                {
                    fn = cad_fornecedor(fn);
                    printf("\n");
                }

                else if (x1 == 2)
                {
                    cad_produto(&estoque);
                    printf("\n");
                }
            break;
            case 2:
                printf("Relatórios disponíveis: \n");
                printf("1.Produtos em Estoque \n2.Vendas\n");
                scanf("%d", &x1);
                
                    if (x1 == 1)
                    {
                        imprime_estoque(estoque);
                        printf("\n");
                    }

                    else if (x1 == 2)
                    {
                        printf("\n *** Produtos vendidos:\n");
                        	relatoriodeVendas(vendidos);
                        printf("\n");
                    }
            break;
            case 3:
                vendidos = venda (estoque, vendidos);
            break;
            case 4:
                printf("\nSelecione o que deseja alterar:\n");
                printf("1.Fornecedor \n2.Produto\n");
                scanf("%d", &x2);

                    if (x2 == 1)
                    {
                        alt_fornecedor(fn);
                        printf("\n");
                    }

                    else if (x2 == 2)
                    {
                        alt_produto(estoque);
                        printf("\n");
                    }
            break;
            case 5:
                printf("Deseja mesmo sair? S/N\n");
                scanf("%c", &s);

                if (s == 'S')
                    return 0;
            break;
            case 6:
                printf("Digite o nome do arquivo do estoque a ser salvo: ");
                scanf ("%s", filename);
                GravaEstoque(estoque, tamanho_estoque(estoque), filename);
                break;
            default:
                printf("Opção inválida.\n");
            break;
        }
    
    }
    // desaloca os vetores em memória da aplicação
    free(estoque);
    free(fn);
    free(vendidos);
    return 0;
}
