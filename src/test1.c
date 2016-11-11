#include<stdio.h>
#include<stdlib.h>
#include "array.h"
#include<time.h> // for rand
int array[9][9];

int change_number(int x, int y)
{
	srand(time(NULL));
	
	int origin= array[x][y];
	int change = origin;
	
	while(origin == change)
	{
		change = rand()%5;
	}
	return change;
}

int check(int sx, int sy, int dx, int dy)
{
	int i, j;
	int target,A,B;
	int re_value=0;
	
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			target = array[i][j];
			
			A = array[i][j+1];
			B = array[i][j+2];
					
			if(A==target)
			{
				if(A==B)//3
				{
					array[i][j] = change_number(i,j);
					target = array[i][j];
					re_value=1;
				}
			}
			A = array[i+1][j];
			B = array[i+2][j];
			
			if(A==target)
			{
				if(A==B)//3
				{
					array[i][j] = change_number(i,j);
					target = array[i][j];
					re_value=1;
				}
			}
		}
	}
	return re_value;
}

int main()
{
	srand(time(NULL));
	
	printf("origin : \n");
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			array[i][j]=rand()%5;
			printf("%s ",block[array[i][j]][1]);
		}
		printf("\n");
	}
	
	while(check(0,0,9,9));
	
	printf("change : \n");
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			printf("%s ",block[array[i][j]][1]);
		}
		printf("\n");
	}
	
	return 0;
}
