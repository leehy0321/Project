#include "array.h"
#include "check.h"

int val[2][3][5];
int array[11][11] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			  { 0, 2, 3, 4, 0, 1, 2, 3, 4, 0, 0 },
			  { 0, 3, 4, 0, 1, 2, 3, 4, 0, 1, 0 },
			  { 0, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0 },
			  { 0, 3, 4, 5, 6, 7, 8, 9, 0, 1, 0 },
			  { 0, 4, 5, 6, 7, 8, 0, 0, 1, 2, 0 },
			  { 0, 1, 2, 3, 4, 0, 0, 2, 3, 4, 0 },
			  { 0, 2, 3, 0, 0, 0, 7, 4, 1, 1, 0 },
			  { 0, 3, 4, 0, 1, 2, 3, 4, 0, 1, 0 },
			  { 0, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0 },
			  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			};
int main()
{
	//srand(time(NULL));
	
	int array[11][11];
	/*
	//Entry Check
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
	}*/
	
	//Part Check
	
	for(int i=0; i<11; i++)
	{
		for(int j=0; j<11; j++)
		{
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	Part_check(array,6,7,5,7,val);
	
	//printf(" VVV num : %d %d , %d <-> %d , %d ",val[0][0][0], val[0][0][1], val[0][0][2], val[0][0][3], val[0][0][4]);
	create_block(array, val);
	printf("\n\n");
	for(int i=0; i<11; i++)
	{
		for(int j=0; j<11; j++)
		{
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
