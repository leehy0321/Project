#lib

libhwayounglib.so.1.0: timer.o board.o keyboard.o util.o
	ld -shared -soname=libhwayounglib.so.1 timer.o board.o keyboard.o util.o -o libhwayounglib.so.1.0 -lc
	ln -s libhwayounglib.so.1.0 libhwayounglib.so
	ln -s libhwayounglib.so.1.0 libhwayounglib.so.1

timer.o:
	gcc -fPIC -c timer.c
	
board.o:
	gcc -fPIC -c board.c
	
keyboard.o:
	gcc -fPIC -c keyboard.c
	
util.o:
	gcc -fPIC -c util.c
	
clean:
	rm -f board.o keyboard.o util.o timer.o libhwayounglib.so.1.0 libhwayounglib.so.1 libhwayounglib.so

