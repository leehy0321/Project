// keyboard
#include "../include/total.h" 
#include "../../../hayoung/include/array.h"

#include <termios.h>  // kbhit
#include <unistd.h>

#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66

#define Q 113      // quit
//#define S 115      // Stop
//#define R 114      // Restart
#define ENTER 10   // Choose block

int posit_change_x1=0, posit_change_y1=0;
int posit_change_x2=0, posit_change_y2=0;
int Enter_flag = 0;  // 0: not store 

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

void check_key(int board[11][11], int *POSITION_X, int *POSITION_Y, int *drawFlag, int re_val[2][3][5],int *S)
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
							if( (*POSITION_X == posit_change_x1) && *POSITION_Y == posit_change_y1 ) // enter position -> left position
 							{
								if( *POSITION_X-1 >0 )
								{
									(*POSITION_X)--;
									temp = board[*POSITION_Y][*POSITION_X];
									board[*POSITION_Y][*POSITION_X] = -temp;
								}
							}
							else if( (*POSITION_X == posit_change_x1+1) && *POSITION_Y == posit_change_y1 ) // enter's right -> enter
							{
								// delete now position
								temp = board[*POSITION_Y][*POSITION_X];
								board[*POSITION_Y][*POSITION_X] = -temp;
								
								//move left
								(*POSITION_X)--;
							}
							// enter's left -> enter's left left
							// or other -> left
							
							// do not anything
						}
						else
						{
							temp = board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = -temp;
							
							//change thing to point now
							(*POSITION_X)--;
							if(*POSITION_X<1) *POSITION_X=9; 
							temp =board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = -temp;
						}
						break;
						
					case RIGHT:
						if( Enter_flag ==1 )
						{	
							if( (*POSITION_X == posit_change_x1) && *POSITION_Y == posit_change_y1 ) // enter position -> right position
 							{
								if( *POSITION_X+1 < 10 )
								{
									(*POSITION_X)++;
									temp = board[*POSITION_Y][*POSITION_X];
									board[*POSITION_Y][*POSITION_X] = -temp;
								}
							}
							else if( (*POSITION_X == posit_change_x1-1) && *POSITION_Y == posit_change_y1 ) // enter's left+ -> enter
							{
								// delete now position
								temp = board[*POSITION_Y][*POSITION_X];
								board[*POSITION_Y][*POSITION_X] = -temp;
								
								//move left
								(*POSITION_X)++;
							}
							// enter's left -> enter's left left
							// or other -> left
							
							// do not anything
						}
						else
						{
							temp = board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = -temp;
							
							//change thing to point now
							(*POSITION_X)++;
							if(*POSITION_X>9) *POSITION_X=1;
							temp = board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = -temp;
						}
						break;
						
					case DOWN:
						if( Enter_flag ==1 )
						{	
							if( (*POSITION_X == posit_change_x1) && *POSITION_Y == posit_change_y1 ) // enter position -> right position
 							{
								if( *POSITION_Y+1 < 10 )
								{
									(*POSITION_Y)++;
									temp = board[*POSITION_Y][*POSITION_X];
									board[*POSITION_Y][*POSITION_X] = -temp;
								}
							}
							else if( (*POSITION_X == posit_change_x1) && (*POSITION_Y == posit_change_y1-1) ) // enter's up -> enter
							{
								// delete now position
								temp = board[*POSITION_Y][*POSITION_X];
								board[*POSITION_Y][*POSITION_X] = -temp;
								
								//move left
								(*POSITION_Y)++;
							}
							// enter's down -> enter's down down
							// or other -> down
							
							// do not anything
						}
						else
						{
							temp = board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = -temp;
							
							//change thing to point now
							(*POSITION_Y)++;
							if(*POSITION_Y>9) *POSITION_Y=1;
							temp = board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X]= -temp;
						}
						break;
					
					case UP:
						if( Enter_flag ==1 )
						{
							if( (*POSITION_X == posit_change_x1) && *POSITION_Y == posit_change_y1 ) // enter position -> right position
 							{
								if( *POSITION_Y-1 > 0 )
								{
									(*POSITION_Y)--;
									temp = board[*POSITION_Y][*POSITION_X];
									board[*POSITION_Y][*POSITION_X] = -temp;
								}
							}
							else if( (*POSITION_X == posit_change_x1) && (*POSITION_Y == posit_change_y1+1) ) // enter's down -> enter
							{
								// delete now position
								temp = board[*POSITION_Y][*POSITION_X];
								board[*POSITION_Y][*POSITION_X] = -temp;
								
								//move left
								(*POSITION_Y)--;
							}
							// enter's left -> enter's left left
							// or other -> left
							
							// do not anything
						}
						else
						{
							temp = board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = -temp;
							
							//change thing to point now
							(*POSITION_Y)--;
							if(*POSITION_Y<1) *POSITION_Y=9; 
							temp = board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = -temp;
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
							// store now position  11
							posit_change_x1 = *POSITION_X; 
							posit_change_y1 = *POSITION_Y;
							
							temp = -board[*POSITION_Y][*POSITION_X];
							board[*POSITION_Y][*POSITION_X] = temp+10;
							
							Enter_flag=1;
						}
						else{
							// store now position  -1
							posit_change_x2 = *POSITION_X; 
							posit_change_y2 = *POSITION_Y;
							
							// change block each other
							
							temp = board[posit_change_y1][posit_change_x1];
							board[posit_change_y1][posit_change_x1]= board[posit_change_y2][posit_change_x2]; // -1 = board[*POSITION_X][*POSITION_Y];
							board[posit_change_y2][posit_change_x2] = temp;  //11
							
							
							// draw Game board to show exchange blocks
							
							
							if( board[posit_change_y1][posit_change_x1] < 0 )
							{
								board[posit_change_y1][posit_change_x1] =-board[posit_change_y1][posit_change_x1];
							}
							if( board[posit_change_y2][posit_change_x2] < 0)
							{
								board[posit_change_y2][posit_change_x2]= -board[posit_change_y2][posit_change_x2];
							}
							if(board[posit_change_y1][posit_change_x1] >10 )
							{
								board[posit_change_y1][posit_change_x1] =board[posit_change_y1][posit_change_x1]-10;
							}
							if(board[posit_change_y2][posit_change_x2] > 10)
							{
								board[posit_change_y2][posit_change_x2]= board[posit_change_y2][posit_change_x2]-10;
							}
							
							
							
							// check 3 match
							// @@
							//board[posit_change_x1][posit_change_y1] = -board[posit_change_x1][posit_change_y1];
							//board[posit_change_x2][posit_change_x2] = board[posit_change_x2][posit_change_x2] -10;
							
							printf("[keyboard] x: %d, y:%d :: (%d) / x: %d, y:%d :: (%d)",posit_change_x1,posit_change_y1,board[posit_change_y1][posit_change_x1],posit_change_x2,posit_change_y2,board[posit_change_y2][posit_change_x2]);
							
							Part_check(board,posit_change_x1,posit_change_y1,posit_change_x2,posit_change_y2,re_val,S);
							printf("[keyboard] x: %d, y:%d :: (%d) / x: %d, y:%d :: (%d)",posit_change_x1,posit_change_y1,board[posit_change_y1][posit_change_x1],posit_change_x2,posit_change_y2,board[posit_change_y2][posit_change_x2]);
							*drawFlag =1;
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
			// keyboard
			*drawFlag =1;
		}	
}
