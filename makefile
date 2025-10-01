all:
	gcc -Wall -c include/*.h                # compila os .h em .gch
	gcc -Wall -c servicos/*.c -I include    # compila os .c em .o
	gcc -Wall -c *.c   -I include           # compila os .c em .o
	gcc -o m *.o                  # linka tudo

clean:
	rm -f *.o  m include/*.gch
