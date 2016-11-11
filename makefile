main : src/main.c
	cd src; gcc main.c -L/home/hwayoug/TeamProject/Project/header -lkbhit -o main
	
libkbhit.a : kbhit.o
	cd header; ar rv libkbhit.a kbhit.o

kbhit.o : kbhit.c
	cd header; gcc -c kbhit.c
