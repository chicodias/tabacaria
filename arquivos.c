/*
    Arquivo: arquivos.h 
    Autor: Alline e Matheus
    Contém os cabeçalhos das rotinas de manipulação de arquivo
*/

#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"

produto * AbreEstoque (char filename[])
{
    FILE *fp = NULL;
    produto * estoque = NULL;
    int n = 0;

    fp = fopen(filename,"r");
    if (fp == NULL)
    return NULL;

   // lendo a quantidade de produtos no estoque
    fscanf(fp,"%d", &n);


    estoque = (produto *) malloc(n*sizeof(produto));

   // lendo cada um dos produtos salvos
    for (int i = 0; i < n; i++)
    {
        fscanf (fp, "%li %f %f %d ", &estoque[i].codigo, &estoque[i].preco_compra, &estoque[i].preco_venda , &estoque[i].armazenamento);
        fgets ((estoque)[i].nome, lim, fp);
        fgets ((estoque)[i].tipo, lim, fp);
        fgets ((estoque)[i].fornecedor, lim, fp);
        printf("%s\n", estoque[i].nome);
    }

    printf("estoque carregado com sucesso.\n");

    fclose (fp);
    return estoque;
}

void GravaEstoque(produto * estoque, int n, char filename[])
{
    FILE *fp;
    fp = fopen (filename,"w");

    fprintf(fp,"%d\n",n);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp,"%li\n%f\n%f\n%d\n%s\n%s\n%s\n" , estoque[i].codigo, estoque[i].preco_compra, estoque[i].preco_venda,
                                                estoque[i].armazenamento, estoque[i].nome, estoque[i].tipo, estoque[i].fornecedor);

    }


    printf("%s gravado com sucesso.\n",filename);
    fclose (fp);
    }
