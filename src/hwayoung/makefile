all: hwayounglib.a main

hwayounglib.a : board.o keyboard.o util.o
	ar rv hwayounglib.a board.o keyboard.o util.o

board.o : board.c
	gcc -c board.c -o board.o

keyboard.o : keyboard.c
	gcc -c keyboard.c -o keyboard.o

util.o : util.c
	gcc -c util.c -o util.o
	

main : main.c
	gcc main.c -o main -I.. -lpthread -L .. hwayounglib.a


clean :
	rm -f hwayounglib.a board.o keyboard.o util.o main

	


