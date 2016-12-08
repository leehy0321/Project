#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int change_number(int input);
int check_same(char c, int array[11][11], int j, int i);
int check_size(char c, int x, int y);
void Part_check(int array[11][11], int sx, int sy, int dx, int dy, int re_val[2][3][5],int *S);
int Entry_check(int array[11][11]);
void create_block(int array[11][11],int re_val[2][3][5],int *S);
int is_there(int same_array[2][5], int same_position[2]);
void delete_and_create(int array[11][11], int re_val[2][3][5], int Index,int *S);
void re_check(int array[11][11], int re_val[2][3][5], int sx, int sy, int dx, int dy);
void init_val(int re_val[2][3][5]);
