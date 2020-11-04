/*  */
#include "vendas.h"

void relatoriodeVendas (produto * vendidos)
{
    float margem, total = 0;
    
    for (int i = 0; i < tamanho_vendidos(); i++)
    {
        margem = vendidos[i].preco_venda - vendidos[i].preco_compra;
        printf("\n item: %s \n margem do item: %.2lf R$\n", vendidos[i].nome, margem);
        total += margem;
    }
    printf("\n\nTotal de lucro registrado: %.2lf R$.\n", total);
}