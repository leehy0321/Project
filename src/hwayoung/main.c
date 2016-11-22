#include "total.h" 

#include "board.h" 				 // make board & reset board
#include "keyboard.h"			 // get keyboard
#include "util.h"				 // draw consol

/////////////////////////////////////////////////////////////////////////
int main(void)
{	
	reset_game();
	
	while(1)
	{
		check_key(board[][],&POSITION_X,&POSITION_Y);
		draw_gameBoard();
	}
	
	return 0;
}

void reset_game()
{
	// make & init board
	reset_gameBoard(board[][],B_SIZE_X,B_SIZE_Y,POSITION_X,POSITION_X);
	init_board(board[][],B_SIZE_X,B_SIZE_Y,POSITION_X,POSITION_X);
	
	// draw
	system("clear");
	title();
	draw_gameBoard(board[][],S_POSIT_X,S_POSIT_Y,B_SIZE_X,B_SIZE_Y);
}

