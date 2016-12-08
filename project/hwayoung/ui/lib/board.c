// make board
#include "../include/total.h" 

void make_board(int board[11][11], int POSITION_X, int POSITION_Y)
{
	//make board
	srand(time(0));
	
	for(int y=1; y<B_SIZE_Y-1; y++)
	{
		for(int x=1; x<B_SIZE_X-1; x++)
		{
			board[y][x]=( rand()%5 )+1;
		}
	}
	// 3 match test fucntion -> retrun (x,y,shape)
	// *
	
	// know thing to point now
	int temp = board[POSITION_Y][POSITION_X];
	board[POSITION_Y][POSITION_X] = -temp;
}

void reset_gameBoard(int board[11][11], int POSITION_X, int POSITION_Y)
{
	for (int i=0; i<B_SIZE_Y; i++)
	{
		for (int j = 0; j <B_SIZE_X; j++)
		{
			// make wall
			if( i==0 || j==0 || i==(B_SIZE_X-1) || j==(B_SIZE_Y-1) )  // make wall
			{
				board[i][j] = WALL;  
			}
			else
			{
				board[i][j] = 0;  //init
			}
		}
	}
}
