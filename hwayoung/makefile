# hwayoung
all: makeLib main

makeLib : 
	make -C ui;

main : main.c
	gcc main.c -lpthread -Ihome/hwayoung/TeamProject/Project/hwayoung/ui/include -Lhome/hwayoung/TeamProject/Project/hwayoung/ui/lib/hwayounglib.a -o main


clean :
	rm main; cd ui/lib; rm -f hwayounglib.a board.o keyboard.o util.o
