#ui
all: hwayounglib.a

hwayounglib.a : lib/board.o lib/keyboard.o lib/util.o
	cd lib; ar rv hwayounglib.a board.o keyboard.o util.o

board.o : lib/board.c
	cd lib; gcc -c board.c -o board.o

keyboard.o : keyboard.c
	cd lib; gcc -c keyboard.c -o keyboard.o

util.o : util.c
	cd lib; gcc -c util.c -o util.o
	

clean : 
	cd lib; rm -f *.o *.a 
