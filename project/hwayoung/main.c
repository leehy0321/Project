#include "ui/include/total.h" 
#include "ui/include/board.h"
#include "ui/include/keyboard.h"
#include "ui/include/util.h"
#include "ui/include/timer.h"
#include "../hayoung/include/check.h"

#include <stdlib.h>
#include <string.h>
// variable
// board to draw
int board_cpy[B_SIZE_X][B_SIZE_Y];  // prior board(cpy)

int _board[B_SIZE_X][B_SIZE_Y];
int POSITION_X= 1, POSITION_Y= 1;  // now position
int count = 10;  // move Count
int intro =1;
int val[2][3][5];
int SCORE;
/////////////////////////////////////////////////////////////////////////
void reset_game()
{
	//make & init board
	reset_gameBoard(_board, POSITION_X, POSITION_Y);
	make_board(_board,POSITION_X, POSITION_Y);
	while(Entry_check(_board));
	
	// draw
	system("clear");
	title();
	draw_gameBoard(_board,board_cpy,count,SCORE);
}

int main()
{	
    int drawFlag=0;
	
	system("clear");
    
    // Intro Screen
    introScreen();
    while(intro==1)
    {
		if(check_key_ret())
		{
			intro=0;
			break;
		}
	}
	
	reset_game();
	
	
	while(1)
	{
		check_key(_board,&POSITION_X,&POSITION_Y,&drawFlag,val,&SCORE,&count);
		while(Entry_check(_board));
		memset(val,0,sizeof(val));
		if(count==0)
		{
			endScreen();
			break;
		}
		draw_gameBoard(_board,board_cpy,count,SCORE);
		while(Entry_check(_board));
		if( drawFlag==1)
		{
			draw_gameBoard(_board,board_cpy,count,SCORE);
			while(Entry_check(_board));
			drawFlag=0;
		}
	}

	return 0;
}

