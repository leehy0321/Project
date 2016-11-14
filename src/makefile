hy_libfucs.a: change_number.o check_3block.o
	ar rv hy_libfucs.a change_number.o check_3block.o

change_number.o:
	gcc -c -g -Wall change_number.c
	
check_3block.o:
	gcc -c -g -Wall check_3block.c
	
clean:
	rm -f hy_libfucs.a check_3block.o change_number.o
