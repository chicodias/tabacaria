all: cadastro.o vendas.o main.o
	gcc -std=c99 -Wall cadastro.o vendas.o main.o -o tabacaria

run:
	./tabacaria

clean:
	rm *.o tabacaria
	

