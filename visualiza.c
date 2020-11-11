/*
    Arquivo: visualiza.h 
    Autor: Filipe
    Contém as rotinas de visualização de relatórios da tabacaria
*/
#include "vendas.h"

/* Imprime na saida padrao o relatorio de produtos vendidos */
void relatoriodeVendas (produto * vendidos)
{
    float margem, total = 0;
    
    for (int i = 0; i < tamanho_vendidos(); i++)
    {
        margem = vendidos[i].preco_venda - vendidos[i].preco_compra;
        printf("\n     item: %s \n     margem do item: %.2lf R$\n", vendidos[i].nome, margem);
        total += margem;
    }
    printf("\n\nTotal de lucro registrado: %.2lf R$.\n", total);
}

/* Imprime os produtos em estoque */
void imprime_estoque(produto * estoque)
{
    for (int i = 0; i < tamanho_estoque(); i++)
        printf("   %d. %s \n",i,estoque[i].nome);
}
