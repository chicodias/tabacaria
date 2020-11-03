/*
    Arquivo: vendas.c
    Autor: Matheus Pires
    Contém as funções de venda da tabacaria
*/
#include "cadastro.h"
#include "vendas.h"

/* variavel global que controla o tamanho do vetor de produtos vendidos */
int TAM_MAX_VENDAS = 0;

// Realiza a venda de uma quantidade de produtos 
produto * venda (produto * estoque, produto * vendidos)
{
    int i, quantidade;
    produto prod;
    long int codigo;

    printf("Digite o numero de vendas: \n");
    scanf("%d", &quantidade);

    if (tamanho_estoque() < 1)
    {
        printf("Estoque vazio.\n");
        return NULL;
    }
    
    // se o vetor ainda nao tiver sido alocado
    if(TAM_MAX_VENDAS == 0)
    {
        vendidos = malloc(quantidade * sizeof (produto));
        i = 0;
        TAM_MAX_VENDAS = quantidade;
    }
    else
    {
        vendidos = realloc(vendidos, (quantidade + TAM_MAX_VENDAS) * sizeof (produto));
        i = TAM_MAX_VENDAS;
        TAM_MAX_VENDAS += quantidade;
    }
    
    while (i < TAM_MAX_VENDAS)
    {
        printf("Digite o codigo do produto: \n");
        scanf("%li", &codigo);
        prod = removeProduto(estoque, codigo);
        vendidos[i] = prod;
 
        if(prod.codigo == 0)
            printf("Produto não encontrado. Venda não realizada.\n");

        else
            printf("Registrou a venda com sucesso.\n");     

        i++;    
    }
    return vendidos;
}
