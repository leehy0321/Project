#include<stdio.h>
#include<stdlib.h>
#include "array.h"

struct colum{
	int start;
	int end;
	int width;
};

int main()
{
	int i, j, c;
	int target, correct1=0, A,B,C,correct2=0,correct3=0,correct4=0;
	struct colum col;

	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			target = array[i][j];
			
			if(target != 0)
			{
				A = array[i][j+1];
				B = array[i][j+2];
				C = array[i][j+3];
				
				if(A==target)
				{
					if(A==B)//3
					{
						if(B==C)//4
						{
							correct2++;
							j=j+3;
						}
						else 
						{
							correct1++;
							j=j+2;
						}	
					}
				}
			
				A = array[i+1][j];
				B = array[i+2][j];
				C = array[i+3][j];
			
				if(A==target)
				{
					if(A==B)//3
					{
						if(B==C)//4
						{
							correct4++;
							col.start = i;
							col.end = i+3;
							col.width = j;
						}
						else 
						{
							correct3++;
							col.start = i;
							col.end = i+2;
							col.width = j;
						}	
					}
				}
			}
		}
	}
	
	printf("%d    %d    %d    %d     \n ",correct1, correct2, correct3, correct4);
	
}
