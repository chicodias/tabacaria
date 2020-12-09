/*
    Arquivo: arquivos.h 
    Autor: Alline e Matheus
    Contém os cabeçalhos das rotinas de manipulação de arquivo
*/

#ifndef FILES_H
#define FILES_H

#include "cadastro.h"
#include <stdio.h>
#include <stdlib.h>

/* tamanho máximo das strings */
#define lim 100

/* recebe o nome do arquivo abre-o do disco */
produto * AbreEstoque (char filename[]);

void GravaEstoque(char filename[], int** M, int m, int n);

#endif /* FILES.H */