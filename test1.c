#include<stdio.h>
#include<stdlib.h>
#include "array.h"

int main()
{
	int i, j;
	int target, correct1=0, A,B,correct3=0;

	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			target = array[i][j];
			
			if(target != 0)
			{
				A = array[i][j+1];
				B = array[i][j+2];
				
				if(A==target)
				{
					if(A==B)//3
					{
						correct1++;
						j=j+3;
	
					}
				}
			
				A = array[i+1][j];
				B = array[i+2][j];
			
				if(A==target)
				{
					if(A==B)//3
					{
						correct3++;
					}
				}
			}
		}
	}
	
	printf("%d      %d       \n ",correct1,correct3);
	
}
