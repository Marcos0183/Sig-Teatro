all:
	gcc -Wall -c include/*.h                # compila os .h em .gch
	gcc -Wall -c *.c   -I include           # compila os .c em .o
	gcc -o sig-teatro *.o                  # linka tudo

clean:
	rm -f *.o  sig-teatro include/*.gch
