/*
    Arquivo: visualiza.h 
    Autor: Filipe
    Contém os cabeçalhos das rotinas de visualização de relatórios da tabacaria
*/

#ifndef VISU_H
#define VISU_H

#include "vendas.h"

/* recebe o estoque e calcula o relatorio */
void relatoriodeVendas (produto * vendidos);

/* imprime o estoque atual */
void imprime_estoque(produto * estoque); 

#endif
