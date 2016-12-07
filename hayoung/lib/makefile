libhyfuncs.so.1.0: change_number.o check_3block.o making_newblock.o
	ld -shared -soname=libhyfuncs.so.1 change_number.o check_3block.o making_newblock.o -o libhyfuncs.so.1.0 -lc
	ln -s libhyfuncs.so.1.0 libhyfuncs.so
	ln -s libhyfuncs.so.1.0 libhyfuncs.so.1
	
change_number.o:
	gcc -fPIC -c change_number.c
	
check_3block.o:
	gcc -fPIC -c check_3block.c
	
making_newblock.o:
	gcc -fPIC -c making_newblock.c
	
clean:
	rm -f change_number.o making_newblock.o check_3block.o libhyfuncs.so.1.0 libhyfuncs.so.1 libhyfuncs.so
