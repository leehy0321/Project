#include<stdio.h>

int check(int array[9][9], int sx, int sy, int dx, int dy)
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
					array[i][j] = change_number(target);
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
