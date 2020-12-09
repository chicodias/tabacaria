all: arquivos.o cadastro.o vendas.o visualiza.o main.o
	gcc -std=c99 -Wall arquivos.o cadastro.o vendas.o visualiza.o main.o -o tabacaria

run:
	./tabacaria

clean:
	rm *.o tabacaria
	

