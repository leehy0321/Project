#include "array.h"
#include "check.h"

int val[2][3][5];
int array_[11][11] = { {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
			  { 5, 2, 3, 4, 0, 1, 2, 3, 4, 0, 5 },
			  { 5, 3, 4, 0, 1, 2, 3, 4, 0, 1, 5 },
			  { 5, 2, 3, 4, 2, 1, 3, 2, 1, 0, 5 },
			  { 5, 3, 4, 2, 3, 1, 2, 3, 0, 1, 5 },
			  { 5, 2, 1, 0, 3, 0, 0, 0, 1, 2, 5 },
			  { 5, 1, 2, 3, 4, 0, 0, 2, 3, 4, 5 },
			  { 5, 2, 4, 2, 3, 0, 2, 4, 1, 1, 5 },
			  { 5, 1, 4, 0, 1, 2, 3, 4, 0, 1, 5 },
			  { 5, 2, 4, 1, 3, 2, 1, 3, 4, 0, 5 },
			  { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
			};
			
void print_blcok()
{
	for(int i=0; i<11; i++)
	{
		for(int j=0; j<11; j++)
		{
			printf("%s ",block[array_[i][j]][1]);
		}
		printf("\n");
	}
}
int main()
{
	//srand(time(NULL));
	
	
	//Entry Check
	
	/*printf("origin : \n");
	for(int i=1; i<10; i++)
	{
		for(int j=1; j<10; j++)
		{
			//printf("%s ",block[array_[i][j]][1]);
			printf("%d ",array_[i][j]);
		}
		printf("\n");
	}
	
	while(Entry_check(array_));
	
	printf("change : \n");
	for(int i=1; i<10; i++)
	{
		for(int j=1; j<10; j++)
		{
			//printf("%s ",block[array_[i][j]][1]);
			printf("%d ",array_[i][j]);
		}
		printf("\n");
	}*/
	
	//Part Check
	
	print_blcok();
	Part_check(array_,4,5,5,5,val); // block check
	//printf("%d %d %d" ,val[1][0][0],val[1][1][0], val[1][2][0]);
	//Part_check(array_,2,7,3,7,val); 
	create_block(array_, val); // create new block
	printf("\n change1 \n");
	print_blcok();
	
	while(Entry_check(array_));
	
	printf("\n change2 \n");
	print_blcok();
	
	return 0;
}
