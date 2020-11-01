all: loja.o main.o
	gcc -std=c99 -Wall loja.o main.o -o tabacaria

run:
	./tabacaria

clean:
	rm *.o tabacaria
	

