// utility
#include "../include/total.h" 

void gotoxy(int x, int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}

void draw_gameBoard(int board[11][11], int board_cpy[11][11]) // draw to 
{
	gotoxy(S_POSIT_X, S_POSIT_Y);
	for (int i=0; i<B_SIZE_Y; i++)
	{
		for (int j = 0; j < B_SIZE_X; j++)
		{
			switch (board[j][i])
			{
				case WALL:
					printf("▦ ");
					break;
				case SHAPE_C: // "●" 
					printf("● ");
					break;
				case SHAPE_R: // "■"
					printf("■ ");
					break;
				case SHAPE_S: // "★"
					printf("★ ");
					break;
				case SHAPE_H: // "♥"
					printf("♥ ");
					break;
				case SHAPE_T: // "▲"
					printf("▲ ");
					break;	
					
				//91
				case SHAPE_C_: // "●" 
					printf("\033[94m● \033[0m");
					break;
				case SHAPE_R_: // "■"
					printf("\033[94m■ \033[0m");
					break;
				case SHAPE_S_: // "★" 
					printf("\033[94m★ \033[0m");
					break;
				case SHAPE_H_: // "♥"
					printf("\033[94m♥ \033[0m");
					break;
				case SHAPE_T_: // "▲"
					printf("\033[94m▲ \033[0m");
					break;	
			}
		}
		gotoxy(S_POSIT_X, S_POSIT_Y+i+1);
	}
	
	// cpy
	for(int i=0; i<B_SIZE_X; i++)
	{
		for(int j=0; j<B_SIZE_Y; j++)
		{
				board_cpy[i][j] = board[i][j];
		}
	}
}

void title()
{
	gotoxy(8,2);
	printf("------3 match game------");
	//gotoxy(25,3);
	//printf("by hayoung, hwayoung");
	gotoxy(27,5);
	printf("Timer :");
	gotoxy(27,10);
	printf("Score :");
}
