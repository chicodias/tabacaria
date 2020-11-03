/*
    Arquivo: vendas.h 
    Autor: Matheus Pires
    Contém os cabeçalhos das rotinas de venda da tabacaria
*/

#ifndef VENDAS_H
#define VENDAS_H

#include "cadastro.h"

// retira produtos do estoque e coloca-os como vendidos
// imprime na saida padrao caso consiga ou nao
produto * venda (produto * estoque, produto * vendas);

#endif
