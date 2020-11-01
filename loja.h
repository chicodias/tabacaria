/*
    Arquivo: loja.h 
    Autor: Alline
    Contém os cabeçalhos das rotinas de execução do arquivo loja.c
*/

#ifndef LOJA_H
#define LOJA_H

#include <stdio.h>
#include <stdlib.h>

#define lim 100

typedef
struct fornecedores_{
    char nome[lim];
    long int codigo;
    char especialidade;
} fornecedores;
    
typedef
struct produto_{
    long int codigo;
    char nome[lim];
    float preco;
    char tipo[lim], fornecedor[lim];
    int armazenamento;
} produto;

//declarando as funções do programa

void cadastro();
int cad_fornecedor();
int cad_produto();
void menu();

#endif //loja.h