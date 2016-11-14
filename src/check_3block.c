#include<stdio.h>

int check(int array[11][11], int sx, int sy, int dx, int dy)
{
	int i, j;
	int target, A, B;
	int re_value = 0;

	if (sx == sy == 1 && dx == dy == 9)
	{
		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
			{
				target = array[i][j];

				A = array[i][j + 1];
				B = array[i][j + 2];

				if (A == target)
				{
					if (A == B)//3
					{
						array[i][j] = change_number(target);
						target = array[i][j];
						re_value = 1;
					}
				}
				A = array[i + 1][j];
				B = array[i + 2][j];

				if (A == target)
				{
					if (A == B)//3
					{
						array[i][j] = change_number(i, j);
						target = array[i][j];
						re_value = 1;
					}
				}
			}
		}
		return re_value;
	}
	else
	{
		if (sy == dy) // x좌표를 움직였을때 <->
		{


		}
	}
}
