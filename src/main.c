#include <stdio.h>
//#include <ncurses.h>  // gotoxy  (1~80,1~24)
//#include <windows.h>
#include <time.h> // random
#include <stdlib.h>

#include <termios.h>  // kbhit
#include <unistd.h>

//#define gotoxy(x,y) wmove(stdscr,y-1,x-1)

#define SHAPE_C 1  // "●"  circle
#define SHAPE_R 2  // "■"  rectangle
#define SHAPE_S 3  // "★"  star
#define SHAPE_H 4  // "♥"  heart
#define SHAPE_T 5  // "▲"  triangle
#define WALL -1 // ""  wall   // * have to modify

#define S_POSIT_X 2  // start position x
#define S_POSIT_Y 2  // start position y
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

char *block[5][2] = { {"□","■"}, {"△","▲"}, {"○","●"}, 
			{"♡","♥"}, {"☆","★"} };
// [0][0] : "□"
// [0][1] : "■"

int board[B_SIZE_X][B_SIZE_Y]; // board to draw
int board_cpy[B_SIZE_X][B_SIZE_Y];  // prior board(cpy)

/////////////////////////////////////////////////////////////////////////
// functions
void gotoxy(int x, int y);
void draw_gameBoard();
void reset();
void reset_gameBoard();
void check_key(void);
void init_board();
int kbhit();

/////////////////////////////////////////////////////////////////////////
int main(void)
{
	reset();
	/*
	while(1)
	{
		
		int value;
		
		if( (value = kbhit()) != 0)
		{
			printf("%d\n",value);
		}
		
		check_key();
		draw_gameBoard();
	}
	*/
	/*
	for(int i=0; i<B_SIZE_Y; i++)
	{
		for(int j=0; j<B_SIZE_X; j++)
		{
			printf("%d",board[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
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
					printf(". ");
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
			}
		}
		printf("\n ");
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

void reset()
{
	system("clear");
	reset_gameBoard();  // init game board -> wall, ..
	init_board();       // random shape
	// and draw 
	draw_gameBoard();
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
			}
			else
			{
				board[j][i] = 0;  //init
			}
		}
	}
}

void check_key(void)
{
		int key = 0;
		
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
						printf("<-\n");
						break;
					case RIGHT:
						printf("->\n");
						break;
					case DOWN:
						printf(".\n");
						break;
					case UP:
						printf("-\n");
						break;
				}
			}
			else  // not direction key
			{
				switch(key){
					case ENTER:
						printf("Enter\n");
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
			board[x][y]=(rand()%5 )+1;
		}
	}
	// 3 match test fucntion -> retrun (x,y,shape)
	// *
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
