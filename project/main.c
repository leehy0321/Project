//backup

#include <stdio.h>
#include <time.h> // random
#include <stdlib.h>

#include <termios.h>  // kbhit
#include <unistd.h>

#define SHAPE_C 1  // "●"  circle
#define SHAPE_R 2  // "■"  rectangle
#define SHAPE_S 3  // "★"  star
#define SHAPE_H 4  // "♥"  heart
#define SHAPE_T 5  // "▲"  triangle

#define SHAPE_C_ -1  // "○"  now position ->other color
#define SHAPE_R_ -2  // "□"
#define SHAPE_S_ -3  // "☆"  
#define SHAPE_H_ -4  // "△"
#define SHAPE_T_ -5  // "♡"

#define SHAPE_C_E 11  // enter position -> other color
#define SHAPE_R_E 12  // 
#define SHAPE_S_E 13  //   
#define SHAPE_H_E 14  // 
#define SHAPE_T_E 15  // 

#define WALL -10 // "▦"  wall 

#define S_POSIT_X 10  // start position x
#define S_POSIT_Y 5 // start position y

#define B_SIZE_X 11  // board size x ( game size x )
#define B_SIZE_Y 11  // board size y ( game size y )

// keyboard
#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66

#define Q 113      // quit
//#define S 115      // Stop
//#define R 114      // Restart
#define ENTER 10   // Choose block

///////////////////////////////////////////////////////////////////////
//variable

int board[B_SIZE_X][B_SIZE_Y]; // board to draw
int board_cpy[B_SIZE_X][B_SIZE_Y];  // prior board(cpy)

int POSITION_X= 1, POSITION_Y= 1;  // now position
int posit_change_x1=0, posit_change_y1=0;
int posit_change_x2=0, posit_change_y2=0;
int Enter_flag = 0;  // 0: not store 

/////////////////////////////////////////////////////////////////////////
// functions
void gotoxy(int x, int y);
void draw_gameBoard();
void reset();
void reset_gameBoard();
void check_key(void);
void init_board();
int kbhit();
void title();

/////////////////////////////////////////////////////////////////////////
int main(void)
{
	
	// board 
	
	
	// keyboard
	
	
	//reset();
	system("clear");
	reset_gameBoard();  // init game board -> wall, ..
	init_board();       // random shape
	// and draw 
	draw_gameBoard();
	
	
	
	title();
	
	while(1)
	{
		check_key();
		draw_gameBoard();
	}
	
	return 0;
}

void title()
{
	gotoxy(25,2);
	printf("▦  3-MATCH GAME ▦");
	//printf("");
	//gotoxy(25,3);
	//printf("by hayoung, hwayoung");
	gotoxy(40,5);
	printf("---- Timer ----");
	gotoxy(40,12);
	printf("---- Score ----");
}

void gotoxy(int x, int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}

void draw_gameBoard() // draw to 
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
	/*
	for(int i=0; i<B_SIZE_X; i++)
	{
		for(int j=0; j<B_SIZE_Y; j++)
		{
				board_cpy[i][j] = board[i][j];
		}
	}
	* */
}

void reset()
{
	
}

void reset_gameBoard()
{
	for (int i=0; i<B_SIZE_Y; i++)
	{
		for (int j = 0; j <B_SIZE_X; j++)
		{
			// make wall
			if( i==0 || j==0 || i==(B_SIZE_X-1) || j==(B_SIZE_Y-1) )  // make wall
			{
				board[j][i] = WALL; 
				board_cpy[j][i] = WALL; 
			}
			else
			{
				board[j][i] = 0;  //initq
			}
		}
	}
}

void check_key(void)
{
		int key = 0,temp=0;
		
		if( (key = kbhit()) != 0)  // if keyboard press
		{
			if(key==27 || key==91) // if it is direction key
			{
				do{
					key = kbhit();
				}
				while( key== 27 || key==91);
				switch(key){
					case LEFT:
						if( Enter_flag ==1 )
						{
							if( (POSITION_X == posit_change_x1) && POSITION_Y == posit_change_y1 ) // enter position -> left position
 							{
								if( POSITION_X-1 >0 )
								{
									POSITION_X--;
									temp = board[POSITION_X][POSITION_Y];
									board[POSITION_X][POSITION_Y] = -temp;
								}
							}
							else if( (POSITION_X == posit_change_x1+1) && POSITION_Y == posit_change_y1 ) // enter's right -> enter
							{
								// delete now position
								temp = board[POSITION_X][POSITION_Y];
								board[POSITION_X][POSITION_Y] = -temp;
								
								//move left
								POSITION_X--;
							}
							// enter's left -> enter's left left
							// or other -> left
							
							// do not anything
						}
						else
						{
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
							
							//change thing to point now
							POSITION_X--;
							if(POSITION_X<1) POSITION_X=9; 
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
						}
						break;
						
					case RIGHT:
						if( Enter_flag ==1 )
						{	
							if( (POSITION_X == posit_change_x1) && POSITION_Y == posit_change_y1 ) // enter position -> right position
 							{
								if( POSITION_X+1 < 10 )
								{
									POSITION_X++;
									temp = board[POSITION_X][POSITION_Y];
									board[POSITION_X][POSITION_Y] = -temp;
								}
							}
							else if( (POSITION_X == posit_change_x1-1) && POSITION_Y == posit_change_y1 ) // enter's left+ -> enter
							{
								// delete now position
								temp = board[POSITION_X][POSITION_Y];
								board[POSITION_X][POSITION_Y] = -temp;
								
								//move left
								POSITION_X++;
							}
							// enter's left -> enter's left left
							// or other -> left
							
							// do not anything
						}
						else
						{
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
							
							//change thing to point now
							POSITION_X++;
							if(POSITION_X>9) POSITION_X=1;
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
						}
						break;
						
					case DOWN:
						if( Enter_flag ==1 )
						{	
							if( (POSITION_X == posit_change_x1) && POSITION_Y == posit_change_y1 ) // enter position -> right position
 							{
								if( POSITION_Y+1 < 10 )
								{
									POSITION_Y++;
									temp = board[POSITION_X][POSITION_Y];
									board[POSITION_X][POSITION_Y] = -temp;
								}
							}
							else if( (POSITION_X == posit_change_x1) && (POSITION_Y == posit_change_y1-1) ) // enter's up -> enter
							{
								// delete now position
								temp = board[POSITION_X][POSITION_Y];
								board[POSITION_X][POSITION_Y] = -temp;
								
								//move left
								POSITION_Y++;
							}
							// enter's down -> enter's down down
							// or other -> down
							
							// do not anything
						}
						else
						{
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
							
							//change thing to point now
							POSITION_Y++;
							if(POSITION_Y>9) POSITION_Y=1;
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
						}
						break;
					
					case UP:
						if( Enter_flag ==1 )
						{
							if( (POSITION_X == posit_change_x1) && POSITION_Y == posit_change_y1 ) // enter position -> right position
 							{
								if( POSITION_Y-1 > 0 )
								{
									POSITION_Y--;
									temp = board[POSITION_X][POSITION_Y];
									board[POSITION_X][POSITION_Y] = -temp;
								}
							}
							else if( (POSITION_X == posit_change_x1) && (POSITION_Y == posit_change_y1+1) ) // enter's down -> enter
							{
								// delete now position
								temp = board[POSITION_X][POSITION_Y];
								board[POSITION_X][POSITION_Y] = -temp;
								
								//move left
								POSITION_Y--;
							}
							// enter's left -> enter's left left
							// or other -> left
							
							// do not anything
						}
						else
						{
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
							
							//change thing to point now
							POSITION_Y--;
							if(POSITION_Y<1) POSITION_Y=9; 
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -temp;
						}
						break;
				}
			}
			else  // not direction key
			{
				switch(key){
					case ENTER:
						if( Enter_flag==0 )
						{
							// store now position
							posit_change_x1 = POSITION_X; 
							posit_change_y1 = POSITION_Y;
							temp = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -board[POSITION_X][POSITION_Y]+ 10;  // store enter key
							
							Enter_flag=1;
						}
						else{
							// store now position
							posit_change_x2 = POSITION_X; 
							posit_change_y2 = POSITION_Y;
							
							// change block each other
							temp = board[posit_change_x1][posit_change_y1];
							//board[posit_change_x1][posit_change_y1] = board[POSITION_X][POSITION_Y];
							board[POSITION_X][POSITION_Y] = -board[POSITION_X][POSITION_Y]+10;
							
							// check 3 match
							// **!
							Enter_flag=0;
						}
						
						break;
					case Q:
						printf("quit\n");
						system("clear");
						exit(0);
						break;
						/*
					case S:
						printf("stop\n");
						pause();
						break;
						
					case R:
						printf("restart\n");
						break;
						*/
				}
			}
		}	
}

void init_board()
{
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

int kbhit()
{
	struct termios oldt, newt;
	int ch;
	
	tcgetattr(STDIN_FILENO, &oldt );
	newt = oldt;
	
	newt.c_lflag &= ~(ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt);
	
	ch = getchar();
	
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	
	return ch;
}

/*

#include <stdio.h>
#include <conio.h>

#define ENTER 13

int main(void)
{
	int ch;

	while ( ( ch=getch() )!= ENTER)
	{
		printf("¹®ÀÚ : (%c), ŸÆœºÅ° ÄÚµå : (%d) \n",ch,ch);
	}
	return 0;
}*/
