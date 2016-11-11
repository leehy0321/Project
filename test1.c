#include<stdio.h>
#include<stdlib.h>
#include "array.h"
#include<time.h> // for rand
#include "check.h"
#include "change.h"

int array[9][9];

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
