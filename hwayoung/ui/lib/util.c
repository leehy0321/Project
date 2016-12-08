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
			switch (board[i][j])
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
					
				//91 now position
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
					
				// enter key
				case SHAPE_C_E:
					printf("\033[95m● \033[0m");
					break;
				case SHAPE_R_E: // "■"
					printf("\033[95m■ \033[0m");
					break;
				case SHAPE_S_E: // "★" 
					printf("\033[95m★ \033[0m");
					break;
				case SHAPE_H_E: // "♥"
					printf("\033[95m♥ \033[0m");
					break;
				case SHAPE_T_E: // "▲"
					printf("\033[95m▲ \033[0m");
					break;	
			}
		}
		gotoxy(S_POSIT_X, S_POSIT_Y+i+1);
	}
	
	// cpy
	for(int j=0; j<B_SIZE_Y; j++)
	{
		for(int i=0; i<B_SIZE_X; i++)
		{
				board_cpy[j][i] = board[j][i];
		}
	}
}

void title()
{
	gotoxy(25,2);
	printf("▦  3-MATCH GAME ▦");
	//printf("");
	//gotoxy(25,3);
	//printf("by hayoung, hwayoung");
	gotoxy(40,5);
	printf("┏━━━━ Timer ━━━━┓");
	gotoxy(40,6);
	printf("┃");
	gotoxy(40,7);
	printf("┃");
	gotoxy(40,8);
	printf("┃");
	gotoxy(40,9);
	printf("┗━━━━━━━━━━━━━━━┛");
	gotoxy(56,6);
	printf("┃");
	gotoxy(56,7);
	printf("┃");
	gotoxy(56,8);
	printf("┃");
	gotoxy(40,11);
	printf("┏━━━━ Score ━━━━┓");
	gotoxy(40,12);
	printf("┃");
	gotoxy(40,13);
	printf("┃");
	gotoxy(40,14);
	printf("┃");
	gotoxy(40,15);
	printf("┗━━━━━━━━━━━━━━━┛");
	gotoxy(56,12);
	printf("┃");
	gotoxy(56,13);
	printf("┃");
	gotoxy(56,14);
	printf("┃");
}
