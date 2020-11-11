# Roteiro de apresentação

## estrutura do projeto:
### main.c
função que faz o chamado as rotinas de execução de cadastro, visualização e venda na tabacaria

### arquivos .h
contem o cabeçalho das funções de seu respectivo arquivo .c. além disso, contem os includes, declaracoes de tipos e constantes

### arquivos .c
contem os codigos das funcoes do respectivo modulo.

módulos: cadastro, venda, visualização

## cadastro
variaveis globais int TAM_MAX_PRODUTOS = 0, TAM_ATUAL_PRODUTOS = 0; servem para monitorar o tamanho do vetor do estoque em tempo de execução a fim de so realizar uma opereção de realicação caso não hajam posições disponíveis no vetor.

além das funcoes de cadastro, importante mencionar uma aspecto das variaveis globais utilizadas no cadastro.c: elas só são vistas dentro do contexto cadastro.c. Fora dele, é necessario utilizar a função tamanho_estoque()

as funcoes que fazem uma busca no vetor, o percorrem em sentido linear, da posicao zero até n. no caso da remoção, se por exemplo foi removido um produto da posicao i, todos os elementos da posicao i+1 em diante são trazidos para frente.

## vendas

funcao de vendas passa um produto do vetor estoque[] para o vetor vendidos[]

## relatorios

percorre os respectivos vetores (estoque[] ou vendidos[]) e imprime os produtos armazenados neles.