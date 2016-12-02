#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
		if(j+3 < 10)
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
		if(i+3 < 11)
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
			if( check_same('r',array,j,i) || check_same('c',array,j,i) )//all of 3block are same -> row , array, x, y
			{	
				array[i][j] = change_number(array[i][j]);
				re_value = 1;
			}
		}
	}
	return re_value;

}

void Part_check(int array[11][11], int sx, int sy, int dx, int dy, int re_val[2][3][5]) // re_val setting
{
	int sn,bn,y,x,count=0; // smaller number, bigger number
	int i;
	if (sy == dy) // x좌표를 움직였을때 <->
	{
		sn = check_size('s',sx,dx); // smaller
		bn = check_size('b',sx,dx); // bigger
		
		y = sy;
		
		//----------------------------가로---------------------------//
		
		for(i = 3; i>=2; i--)//2,3
		{
			count = check_same('r',array,sn-i,y) ;
			if(count && sn-i > 0) // sn으로부터 가로 같은거 구하기!
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
		count = check_same('r',array,bn,y);
		if(count && bn > 0) // bn으로부터 가로 같은거 구하기!
		{
			re_val[1][0][0] = count;
			re_val[1][0][1] = bn;
			re_val[1][0][2] = y;
			re_val[1][0][3] = bn+count-1;
			re_val[1][0][4] = y;
		}
		
		count = 0;
		
		//-------------------세로------------------------------//  
		
		for(i = 3; i>=-1; i--)
		{
			count = check_same('c',array,sn,y-i);
			if( count && y-i > 0 && y-i < 10)
			{
				re_val[0][1][0] = count;
				re_val[0][1][1] = sn;
				re_val[0][1][2] = y-i;
				re_val[0][1][3] = sn;
				re_val[0][1][4] = y-i+count-1;
				//printf("%d : %d %d %d %d \n",re_val[0][1][0],re_val[0][1][1], re_val[0][1][2], re_val[0][1][3], re_val[0][1][4]);
				
				break;
			}
		}
		
		count = 0;
		
		for(i = 3; i>=-1; i--)
		{
			count = check_same('c',array,bn,y-i);
			if( count && y-i > 0 && y-i < 10)
			{
				re_val[1][1][0] = count;
				re_val[1][1][1] = bn;
				re_val[1][1][2] = y-i;
				re_val[1][1][3] = bn;
				re_val[1][1][4] = y-i+count-1;
				
				break;
			}
		}
		
		count = 0;
		//----대각선------//
	}
	
	
	else if (sx == dx) // y좌표를 움직였을때 ↕
	{
		
	}
	
}



int is_there(int same_array[2][5], int same_position[2])
{
	int i,j,sizex0, sizey0, sizex1, sizey1;
	int size0 = same_array[0][0] , size1 = same_array[1][0];
	int sx0=same_array[0][1], sy0 = same_array[0][2],dx0=same_array[0][3], dy0 = same_array[0][4];
	int sx1=same_array[1][1], sy1 = same_array[1][2],dx1=same_array[1][3], dy1 = same_array[1][4];
	
	sizex0 = dx0 - sx0;
	sizey0 = dy0 - sy0;
	sizex1 = dx1 - sx1;
	sizey1 = dy1 - sy1;
	
	for(i=0; i<size0; i++)
	{
		for(j=0; j<size1; j++)
		{
			if(sx0 + sizex0 == sx1 + sizex1)
			{
				if(sy0 + sizey0 == sy1 + sizey1)
				{
					same_position[0] = sx0+sizex0;
					same_position[1] = sy0+sizey0;
					return 1;
				}
			}
			if(sizex1 != 0)
				sizex1--;
			if(sizey1 != 0)
				sizey1--;
		}
		if(sizex0 != 0)
			sizex0--;
		if(sizey0 != 0)
			sizey0--;
		sizex1 = dx1 - sx1;
		sizey1 = dy1 - sy1;	
	}		
	return 0;
}

void delete_and_create(int array[11][11], int re_val[2][3][5], int Index)//start , end
{
	int i, j, count = 0, flag = 0, row_col_dia[2] = {-1, -1},remember=0;
	int same_x_y_position[2], position[2][5];
	int sx,sy,dx,dy;
	int copy_value, x_position = 0, y_position=100, pre_position=100, sub=0;
	
	for (i = 0; i < 3; i++)
	{
		if (re_val[Index][i][0] != 0)
		{
			position[count][0] = re_val[Index][i][0]; // size
			row_col_dia[count] = i;
			printf("%d " ,i);

			for (j = 1; j < 5; j++)
				position[count][j] = re_val[Index][i][j]; // put

			count++;
		}
		else
			continue;
			
	}
	
	if(count == 2)
		if(is_there(position, same_x_y_position))
			flag = 2;
			
	for (i = 0; i < count; i++)
	{
		sx = re_val[Index][row_col_dia[i]][1];
		sy = re_val[Index][row_col_dia[i]][2];
		dx = re_val[Index][row_col_dia[i]][3];
		dy = re_val[Index][row_col_dia[i]][4];
			
		if (row_col_dia[i] == 0) // row
		{
			x_position = sx;
			
			while (x_position < dx + 1)
			{
				y_position = sy;
				pre_position = y_position - 1;

				while (pre_position != 0)
				{
					copy_value = array[pre_position][x_position];
					array[y_position][x_position] = copy_value;

					y_position--;
					pre_position = y_position - 1;
				}
				
				array[1][x_position] = change_number(rand() % 5);
				x_position++;
			}
			
			if(flag == 2)
			{
				remember = array[same_x_y_position[1]][same_x_y_position[0]];
				flag--;
			}
		}

		else if (row_col_dia[i] == 1) // col
		{
			sub = dy - dx;

			y_position = dy;
			x_position = sx;
			pre_position = y_position - re_val[Index][row_col_dia[i]][0];

			//블록 위에서 아래로 내리기
			while (pre_position != 0)
			{
				if(x_position == same_x_y_position[0] && pre_position == same_x_y_position[1] && flag == 1)
					copy_value = remember;
				else
					copy_value = array[pre_position][x_position];
				array[y_position][x_position] = copy_value;
				pre_position--;
				y_position--;
			}

			y_position++;

			//make new block
			while (y_position != pre_position)
			{
				array[y_position][x_position] = change_number(rand() % 5);
				y_position--;
			}
		}
	}
	
}

void create_block(int array[11][11],int re_val[2][3][5])
{
	int i;
	
	for(i=0; i<2; i++)  // loop 2times
	{
		delete_and_create(array, re_val, i);
	}
}
