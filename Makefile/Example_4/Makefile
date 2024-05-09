all:my_program
	echo "Build done"
my_program:main.o helper.o
	gcc main.o helper.o -o my_program
main.o:main.c
	gcc -c main.c 
helper.o:helper.c
	gcc -c helper.c
clean:
	rm *.o my_program
