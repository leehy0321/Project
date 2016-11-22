int check_size(char c, int x, int y)
{
	//c == s -> which is smaller? 
	//c == b -> which is bigger?
	
	if(x>y)
	{
		if( c == 's')//smaller
			return y;
		else//bigger
			return x;
	}
	else // x<y
	{
		if( c == 's') // smaller
			return x;
		else// bigger
			return y;
	}
}

int check_same(char c, int array[11][11], int j, int i)
{
	// r =  row  -
	// c =  col  |
	// d =  diagonal /

	int target, A, B, C;
	target = array[i][j];
	
	
	if(c == 'r')
	{
		if(j+1 > 0 && j+2 > 0)
		{
			A = array[i][j + 1];
			B = array[i][j + 2];
			C = array[i][j + 3];
			
			//printf("%d A : %d , B : %d, C : %d\n",j,A,B,C);
			if (A == target)
			{
				if (A == B)//3
				{
					if(B == C)//4
						return 4;
					else
						return 3;
				}
			}
		}
	}
	else if(c == 'c')// flag==1
	{
		if(i+1 < 10 && i+2 < 10)
		{
			A = array[i + 1][j];
			B = array[i + 2][j];
			C = array[i + 3][j];
			
			if (A == target)
			{
				if (A == B)//3
				{
					if(B == C)//4
						return 4;
					else
						return 3;
				}
			}
		}
	}
	return 0;
}

int Entry_check(int array[11][11])
{
	// 리턴 : 같은 게 하나라도 있다면 1  / 전부 다르다면 0 
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

void Part_check(int array[11][11], int sx, int sy, int dx, int dy, int re_val[2][3][5])
{
	int sn,bn,y,x,count=0; // smaller number, bigger number
	int i;

	if (sy == dy) // x좌표를 움직였을때 <->
	{
		sn = check_size('s',sx,dx); // smaller
		bn = check_size('b',sx,dx); // bigger
		
		y = sy;
		
		for(i = 3; i>=2; i--)//2,3
		{
			if(count = check_same('r',array,sn-i,y)) // sn으로부터 가로 같은거 구하기!
			{
				re_val[0][0][0] = count; // number
				re_val[0][0][1] = sn-i; // 시작 지점
				re_val[0][0][2] = y; 
				re_val[0][0][3] = sn; // 도착 지점
				re_val[0][0][4] = y;
				
				break;
			}
		}
			
		count = 0;
		
		if(count = check_same('r',array,bn,y)) // bn으로부터 가로 같은거 구하기!
		{
			re_val[1][0][0] = count;
			re_val[1][0][1] = bn;
			re_val[1][0][2] = y;
			re_val[1][0][3] = bn+count-1;
			re_val[1][0][4] = y;
		}
		
		count = 0;
		
		for(i = 3; i>=-1; i--)
		{
			if(count = check_same('c',array,sn,y-i))
			{
				re_val[0][1][0] = count;
				re_val[0][1][1] = sn;
				re_val[0][1][2] = y+i;
				re_val[0][1][3] = sn;
				re_val[0][1][4] = y+i+count-1;
				
				break;
			}
		}
		
		count = 0;
		
		for(i = 3; i>=-1; i--)
		{
			if(count = check_same('c',array,bn,y-i))
			{
				re_val[1][1][0] = count;
				re_val[1][1][1] = bn;
				re_val[1][1][2] = y+i;
				re_val[1][1][3] = bn;
				re_val[1][1][4] = y+i+count-1;
				
				break;
			}
		}
	}
}

void delete_and_create(int array[11][11], int flag, int count, int sx, int sy, int dx, int dy)
{
	//flag == 0 -> row / flag == 1 -> col / flag == 2 -> cross
	
	int copy_value, x_position = 0, y_position=100, pre_position=100;
	
	if( flag == 0 ) // row
	{
		x_position = sx;
		
		while(x_position < dx+1)
		{
			y_position = sy;
			
			while(pre_position != 0)
			{
				pre_position = y_position-1;
				copy_value = array[pre_position][x_position];
				
				array[pre_position][x_position] = copy_value;
				
				y_position--;
			}
			array[0][x_position] = change_number(0);
			x_position++;
		}
	}
}	
	
void create_block(int array[11][11],int re_val[2][3][5])
{
	int i,j;
	int num=0, count=0;
	for(i = 0; i < 2; i++) // loop 2times
	{
		for(j = 0; j < 3; j++) // loop 3times
		{
			if(re_val[i][j][0] != 0)
			{
				delete_and_create(array, j, re_val[i][j][0], re_val[i][j][1], re_val[i][j][2], re_val[i][j][3], re_val[i][j][4]);
			}
		}
	}
}
