/*
    Arquivo: cadastro.h 
    Autor: Alline e Matheus
    Contém os cabeçalhos das rotinas de execução do arquivo loja.c
*/

#ifndef CADASTRO_H
#define CADASTRO_H

#include <stdio.h>
#include <stdlib.h>

/* tamanho máximo das strings */
#define lim 100


typedef
struct fornecedores_{
    char nome[lim];
    long int codigo;
    char especialidade[lim];
} fornecedores;
    
typedef
struct produto_{
    long int codigo;
    char nome[lim];
    float preco_compra;
    float preco_venda;
    char tipo[lim];
    char fornecedor[lim];
    int armazenamento;
} produto;

// funções do programa


// cadastra um produto no estoque e retorna seu endereço
void cad_produto(produto ** estoque);

// cadastra um fornecedor no estoque
fornecedores * cad_fornecedor(fornecedores * cadastro);

// encontra um codigo e remove-o do vetor, trazendo os elementos apos ele para frente.
// retorna o produto removido
// se prod.codigo == 0, não encontrou
produto removeProduto(produto * estoque, long int codigo);

// retorna o tamanho do estoque
int tamanho_estoque();

// retorna a quant de fornecedores.
int tamanho_fornecedores();

/* altera um fornecedor */
void alt_fornecedor (fornecedores *pd);

/* altera um produto */
void alt_produto(produto *pd);

#endif //cadastro.h
