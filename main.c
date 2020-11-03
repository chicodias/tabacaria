/* 
    Arquivo: main.c
    Autor: Matheus Pires e Alline

    função que faz o chamado as rotinas de execução de cadastro, visualização e venda na tabacaria
 */
#include "cadastro.h"
#include "vendas.h"

// menu principal da aplicação
int main()
{   
    int x;
	char s;
    
    //inicializa os endereços que conterao os produtos e fornecedores
    // contem o endereco pra primeira pos do vetor respectivo
    produto * estoque = NULL;
    fornecedores * fn = NULL;
    produto * vendidos = NULL;

    while(1)
    {
        printf("\t\tMENU\n\n");
        printf("Escolha uma das opções:\n");
        printf("1. Cadastro \n2. Visualização\n3. Vendas \n4. Sair\n");

        scanf("%d", &x);
        
        // seleção dos modulos
        switch (x)
        {
            case 1:
                cadastro (&estoque, &fn);
            break;

            case 3:
                vendidos = venda (estoque, vendidos);
            break;

            case 4:
                printf("Deseja mesmo sair? S/N\n");
                scanf("%c", &s);

                if (s == 'S')
                    return 0;
            break;
            default:
                printf("Opção inválida.\n");
            break;
        }
        imprime_estoque(estoque);
    }
    // desaloca os vetores em memória da aplicação
    //free(estoque);
    //free(fn);
    //free(vendidos);
}