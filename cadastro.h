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
    float preco;
    char tipo[lim];
    char fornecedor[lim];
    int armazenamento;
} produto;

// funções do programa

//dependendo da escolha cadastrara produto ou fornecedor
void cadastro (produto * estoque, fornecedores * cadastro);

// cadastra um produto no estoque
void cad_produto(produto * estoque);

// cadastra um fornecedor no estoque
void cad_fornecedor(fornecedores * cadastro);

/* Alocação dinâmica */
// aloca um vetor de n produtos no heap
produto * AlocaProdutos(int n);

//aloca n fornecedores
fornecedores *AlocaFornecedores(int n);

// encontra um codigo e remove-o do vetor, trazendo os elementos apos ele para frente.
// retorna o produto removido
produto removeProduto(produto * estoque, long int codigo);

// imprime o estoque na stdout
void imprime_estoque(produto * estoque);

#endif //cadastro.h