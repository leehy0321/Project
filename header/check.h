#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int change_number(int input);
int check_same(int flag, int array[11][11], int i, int j);
int check_size(int flag, int x, int y);
void Part_check(int array[11][11], int sx, int sy, int dx, int dy, int re_val[2][3][3]);
int Entry_check(int array[11][11]);
void create_block(int array[11][11],int re_val[2][3][5]);
void delete_and_create(int array[11][11], int flag, int count, int sx, int sy, int dx, int dy);

int AAA = 3 ;
#define hahaha 3
