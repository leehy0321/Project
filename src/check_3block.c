int check_size(int flag, int x, int y)
{
	//flag = 0 -> which is smaller? 
	//flag = 1 -> which is bigger?
	
	if(x>y)
	{
		if(flag==0)//smaller
			return y;
		else//bigger
			return x;
	}
	else // x<y
	{
		if(flag==0) // smaller
			return x;
		else// bigger
			return y;
	}
}

int check_same(int flag, int array[11][11], int j, int i)
{
	// flag = 0 -> row 
	// flag = 1 -> col
	
	int target, A, B;
	target = array[i][j];
	
	
	if(flag == 0)
	{
		if(j+1 > 0 && j+2 > 0)
		{
			A = array[i][j + 1];
			B = array[i][j + 2];
			printf("A : %d , B : %d\n",A,B);
			if (A == target)
				if (A == B)//3
					return 1;
		}
	}
	else // flag==1
	{
		if(i+1 < 10 && i+2 < 10)
		{
			A = array[i + 1][j];
			B = array[i + 2][j];

			if (A == target)
				if (A == B)
					return 1;
		}
	}
	
	return 0;
}
int Entry_check(int array[11][11])
{
	int i, j;
	int re_value = 0;

	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if(check_same(0,array,i,j))//all of 3block are same 
			{	
				array[i][j] = change_number(array[i][j]);
				re_value = 1;
			}
			if (check_same(1,array,i,j))
			{
				array[i][j] = change_number(array[i][j]);
				re_value = 1;
			}
		}
	}
		return re_value;
}

int Part_check(int array[11][11], int sx, int sy, int dx, int dy)
{
	int sn,bn,y,x; // smaller number, bigger number
		
	if (sy == dy) // x좌표를 움직였을때 <->
	{
		sn = check_size(0,sx,dx);
		bn = check_size(1,sx,dx);
		y = sy;
		
		printf("sn : %d\n",sn);
		printf("bn : %d\n",bn);
		printf("y : %d\n",y);
			
			
		if(check_same(0,array,sn-2,y))
			return 10+sn;
		if(check_same(0,array,bn,y))
			return 20+bn;
		return 0;
	}
}
