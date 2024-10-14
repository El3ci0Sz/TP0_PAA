all: main.c main.c Desenho.c 
	gcc main.c -o exec Desenho.c

run:./exec