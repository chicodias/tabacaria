/* 
    Arquivo: cadastro.c
    Autor: Alline e Matheus
    Contém as funções utilizadas nas rotinas de cadastro da tabacaria
 */

#include "cadastro.h"

/* variaveis globais que controlam o tamanho dos vetores alocados */
int TAM_MAX_PRODUTOS, TAM_ATUAL_PRODUTOS;
int TAM_MAX_FORNECEDORES, TAM_ATUAL_FORNECEDORES;


// aloca um vetor de tamanho n no heap e retorna seu endereço
produto * AlocaProdutos(int n){
    produto * vet;
    vet = malloc(n * sizeof(produto));
    TAM_MAX_PRODUTOS = n;
    TAM_ATUAL_PRODUTOS = n;    
    return vet;
}

// Aloca no heap um vetor de fornecedores de tamanho n e retorna seu endereço
fornecedores *AlocaFornecedores(int n)
{
   fornecedores * vet;
    vet = malloc(n * sizeof(fornecedores));    
    TAM_MAX_FORNECEDORES = n;
    TAM_ATUAL_FORNECEDORES = n; 
    return vet;
}

//dependendo da escolha cadastrara produto ou fornecedor
void cadastro (produto * estoque, fornecedores * cadastro)
{
	int x;

  	printf("Digite o que deseja cadastrar: \n");
  	printf("1.Fornecedor \n2.Produto\n");

  	scanf("%d", &x);

	if (x == 1)
	{
		cad_fornecedor(cadastro);
		printf("\n");
	}

	else
	{
		cad_produto(estoque);
        printf("\n");
	}
}

/*  lê produtos da entrada padrão e cadastra-os no estoque */
void cad_produto (produto * estoque)
{
    int i, quantidade;

    printf("Digite a quantidade de produtos a serem cadastrados");
    scanf("%d", &quantidade);

    // se o estoque ainda nao tiver sido alocado
    if (estoque == NULL)
    {
        estoque = AlocaProdutos(quantidade);
        i = 0;
    }

    // Se ja existir um estoque na memoria
    else
    {
        // caso haja espaço no vetor, insira no final
        if(TAM_MAX_PRODUTOS - TAM_ATUAL_PRODUTOS > quantidade)
        {
            i = TAM_ATUAL_PRODUTOS;
            TAM_ATUAL_PRODUTOS += quantidade;
        }
        // caso não haja, realoque
        else
        {
            i = TAM_ATUAL_PRODUTOS;
            TAM_ATUAL_PRODUTOS += quantidade;
            TAM_MAX_PRODUTOS = TAM_ATUAL_PRODUTOS;
            estoque = realloc (estoque, (TAM_ATUAL_PRODUTOS + quantidade) * sizeof(produto));
        }
    }
    
		while(i < TAM_ATUAL_PRODUTOS)
    {
        printf("\nDigite o código, preço, armazenamento, nome do produto, o tipo, o fornecedor do produto:\n");
	    scanf ("%li %f %d ", &estoque[i].codigo, &estoque[i].preco, &estoque[i].armazenamento);
        fgets (estoque[i].nome, lim, stdin);
	    fgets (estoque[i].tipo, lim, stdin);
        fgets (estoque[i].fornecedor, lim, stdin);
        printf("\n %li %f %d\n", estoque[i].codigo, estoque[i].preco, estoque[i].armazenamento);
        i++;
    }       

    printf("Total de Cadastros feitos: %d.\n Voltando ao menu.\n",quantidade);
}

/* le fornecedores e insere-os no cadastro de fornecedores*/
void cad_fornecedor(fornecedores * cadastro)
{
	int i = 0;
    int quantidade;
    
    printf("Digite a quantidade de fornecedores a serem cadastrados");
    scanf("%d", &quantidade);
// Se ja existir um estoque na memoria
    if (cadastro == NULL)
    {
        cadastro = AlocaFornecedores(quantidade);
        i = 0;
    }
    // se o cadastro de fornecedores ja estiver alocado
    else
    {
        // caso haja espaço no vetor, insira no final
        if(TAM_MAX_FORNECEDORES - TAM_ATUAL_FORNECEDORES > quantidade)
        {
            i = TAM_ATUAL_FORNECEDORES;
            TAM_ATUAL_FORNECEDORES += quantidade;
        }
        // caso não haja, realoque
        else
        {
            i = TAM_ATUAL_FORNECEDORES;
            TAM_ATUAL_FORNECEDORES += quantidade;
            TAM_MAX_FORNECEDORES = TAM_ATUAL_FORNECEDORES;
            cadastro = realloc (cadastro, (TAM_ATUAL_FORNECEDORES + quantidade) * sizeof(fornecedores));
        }
    }
    
		while(i < TAM_ATUAL_FORNECEDORES)
    {
        printf("\nDigite o codigo do fornecedor, o nome e a especialidade: \n");

        scanf("%li ", &cadastro[i].codigo); 
        fgets (cadastro[i].nome,lim, stdin );
        fgets (cadastro[i].especialidade,lim, stdin );
        
    }
    printf("Cadastrou %d fornecedor(es)!",i);
}

// remove um produto a partir de seu codigo e retorna-o caso consiga
produto removeProduto(produto * estoque, long int codigo)
{
    produto chave = {.codigo = 0};
    for(int i = 0; i < TAM_ATUAL_PRODUTOS; ++i)
    {
        // achou o produto
        if(codigo == estoque[i].codigo)
        {
            chave = estoque[i];
            // reposiciona o resto do vetor
            for (int k = i; k < TAM_ATUAL_PRODUTOS; ++k)
                estoque[k] = estoque[k+1];
            
            TAM_ATUAL_PRODUTOS--;
        }
    }
    return chave;
}

void imprime_estoque(produto * estoque)
{
    for (int i = 0; i < TAM_ATUAL_PRODUTOS; i++)
        printf("%s \n",estoque[i].nome);
}