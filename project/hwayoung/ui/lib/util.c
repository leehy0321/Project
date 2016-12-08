// utility
#include "../include/total.h" 

void gotoxy(int x, int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}

void draw_gameBoard(int board[11][11], int board_cpy[11][11],int count,int S) // draw to 
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
					printf("\033[93m● \033[0m");
					break;
				case SHAPE_R: // "■"
					printf("\033[92m■ \033[0m");
					break;
				case SHAPE_S: // "★"
					printf("\033[31m★ \033[0m");
					break;
				case SHAPE_H: // "♥"
					printf("\033[94m♥ \033[0m");
					break;
				case SHAPE_T: // "▲"
					printf("\033[95m▲ \033[0m");
					break;	
					
				//91 now position
				case SHAPE_C_: // "●" 
					printf("● ");
					break;
				case SHAPE_R_: // "■"
					printf("■ ");
					break;
				case SHAPE_S_: // "★" 
					printf("★ ");
					break;
				case SHAPE_H_: // "♥"
					printf("♥ ");
					break;
				case SHAPE_T_: // "▲"
					printf("▲ ");
					break;	
					
				// enter key
				case SHAPE_C_E:
					printf("○ ");
					break;
				case SHAPE_R_E: // "■"
					printf("□ ");
					break;
				case SHAPE_S_E: // "★" 
					printf("☆ ");
					break;
				case SHAPE_H_E: // "♥"
					printf("△ ");
					break;
				case SHAPE_T_E: // "▲"
					printf("♡ ");
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
	
	gotoxy(47,7);
	printf(" %d ",count);
	
	gotoxy(46,13);
	printf(" %d ",S);

	gotoxy(2,80);
}

void title()
{
	gotoxy(25,2);
	printf("▦  3-MATCH GAME ▦");
	//printf("");
	//gotoxy(25,3);
	//printf("by hayoung, hwayoung");
	gotoxy(40,5);
	printf("┏━━━━ Count ━━━━┓");
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


void introScreen()
{
	gotoxy(20,10);
	printf("\033[91mEn\033[0m");
	printf("\033[92mter \033[0m");
	printf("\033[93man\033[0m");
	printf("\033[94my ke\033[0m");
	printf("\033[95my, S\033[0m");
	printf("\033[96mtar\033[0m");
	printf("\033[97mt Ga\033[0m");
	printf("\033[91mme\033[0m");
	//printf(""\033[91mE \033[0m" Enter any key, Start Game\n");
	//printf("\n");
	//printf("made by hwayoung, hayoung");
}

void endScreen()
{
	system("clear");
	gotoxy(20,10);
	printf("┏━━━━━━━━━━━━━━━┓");
	gotoxy(20,11);
	printf("┃");
	gotoxy(20,12);
	printf("┃");
	gotoxy(20,13);
	printf("┃");
	gotoxy(20,14);
	printf("┗━━━━━━━━━━━━━━━┛");
	gotoxy(36,11);
	printf("┃");
	gotoxy(36,12);
	printf("┃");
	gotoxy(36,13);
	printf("┃");
	gotoxy(24,12);
	printf("Game Over");
	gotoxy(2,80);
}

