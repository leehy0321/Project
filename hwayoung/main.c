#include "total.h" 

#include "board.h" 				 // make board & reset board
#include "keyboard.h"			 // get keyboard
#include "util.h"				 // draw consol

// variable
int board[B_SIZE_X][B_SIZE_Y]; // board to draw
int board_cpy[B_SIZE_X][B_SIZE_Y];  // prior board(cpy)

int POSITION_X= 1, POSITION_Y= 1;  // now position

/////////////////////////////////////////////////////////////////////////
int main()
{	
	reset_game();
	
	while(1)
	{
		check_key(board,&POSITION_X,&POSITION_Y);
		draw_gameBoard(board,board_cpy);
	}
	
	return 0;
}

void reset_game()
{
	// make & init board
	reset_gameBoard(board, POSITION_X, POSITION_Y);
	make_board(board,POSITION_X, POSITION_Y);
	
	// draw
	system("clear");
	title();
	draw_gameBoard(board,board_cpy);
}

