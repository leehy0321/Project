#include<stdio.h>
#include<stdlib.h>
#include "array.h"
#include<time.h> // for rand
#include "check.h"
#include "change.h"

int main()
{
	srand(time(NULL));
	
	int array[11][11];
	memset(array,-1,sizeof(array));
	
	printf("origin : \n");
	for(int i=1; i<10; i++)
	{
		for(int j=1; j<10; j++)
		{
			array[i][j]=rand()%5;
			printf("%s ",block[array[i][j]][1]);
		}
		printf("\n");
	}
	
	while(check(array,1,1,9,9));
	
	printf("change : \n");
	for(int i=1; i<10; i++)
	{
		for(int j=1; j<10; j++)
		{
			printf("%s ",block[array[i][j]][1]);
		}
		printf("\n");
	}
	
	return 0;
}
