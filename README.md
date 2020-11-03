# Tabacaria

Arquivos .c e .h necessários para compilar e rodar a aplicação da tabacaria

## Como compilar e executar este repositório

No terminal, digite os comandos:

`make all` para compilar, `make run` para executar, e `make clean` limpa os arquivos gerados pelo compilador.

### Rodando os casos de teste

Utilize os comandos: 
`make run <casos_teste/1.in`
`make run <casos_teste/2.in`
`make run <casos_teste/3.in`


## Arquivos no repositório

- `cadastro.h`: contém os cabeçalhos e definições do programa `cadastro.c`
- `cadastro.c`: contém as funções da rotina de cadastros da tabacaria  
- `vendas.h`: contém o cabeçalho das funções do arquivo `vendas.c`
- `vendas.c`: contém as funções da rotina da tabacaria,
- `main.c`: função principal reponsável por exibir o menu e chamar as outras rotinas,
- `Makefile`: compila os arquivos com auxílio do gcc,
- `readme.MD`: contém informações sobre este repositório. 

