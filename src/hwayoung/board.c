// make board

void make_board(int board[][],int B_SIZE_X,int B_SIZE_Y,int POSITION_X, int POSITION_X)
{
	//make board
	srand(time(NULL));
	for(int y=1; y<B_SIZE_Y-1; y++)
	{
		for(int x=1; x<B_SIZE_X-1; x++)
		{
			board[x][y]=( rand()%5 )+1;
		}
	}
	// 3 match test fucntion -> retrun (x,y,shape)
	// *
	
	// know thing to point now
	int temp = board[POSITION_X][POSITION_Y];
	board[POSITION_X][POSITION_Y] = -temp;
}

void reset_gameBoard(int board[][],int B_SIZE_X,int B_SIZE_Y,int POSITION_X, int POSITION_X)
{
	for (int i=0; i<B_SIZE_Y; i++)
	{
		for (int j = 0; j <B_SIZE_X; j++)
		{
			// make wall
			if( i==0 || j==0 || i==(B_SIZE_X-1) || j==(B_SIZE_Y-1) )  // make wall
			{
				board[j][i] = WALL;  
			}
			else
			{
				board[j][i] = 0;  //init
			}
		}
	}
}
