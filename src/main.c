#include <stdio.h>
//#include <ncurses.h>  // gotoxy  (1~80,1~24)
//#include <windows.h>
#include <time.h> // random
#include <stdlib.h>

#include <termios.h>  // kbhit
#include <unistd.h>

//#define gotoxy(x,y) wmove(stdscr,y-1,x-1)

#define SHAPE_C 0  // "●"  circle
#define SHAPE_R 1  // "■"  rectangle
#define SHAPE_S 2  // "★"  star
#define SHAPE_H 3  // "♥"  heart
#define SHAPE_T 4  // "▲"  triangle

#define S_POSIT_X 2  // start position x
#define S_POSIT_Y 2  // start position y
#define B_SIZE_X 11  // board size x ( game size x )
#define B_SIZE_Y 11

// keyboard
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

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
void check_key(void);
void init_board();
int kbhit();

/////////////////////////////////////////////////////////////////////////
int main(void)
{
	/*
	for(int i=0; i<5; i++)
	{
		printf("block[%d][0] = %s\n",i,block[i][0]);
		printf("block[%d][1] = %s\n", i, block[i][1]);
	}
	* */
	int value = kbhit();
	while(1)
	{
		check_key();
	}
	return 0;
}

void gotoxy(int x, int y)
{
	//COORD Pos = { 2*x,y };  // why multiple 2 **
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
	printf("%c[%d;%df",0x1B,y,x);
}

void draw_gameBoard() // draw to 
{
	for (int i=0; i<B_SIZE_Y; i++)
	{
		for (int j = 0; j < B_SIZE_X; j++)
		{
			gotoxy(S_POSIT_X + j, S_POSIT_Y + i);
			switch (board[j][i])
			{

			}
		}
	}
}

void reset()
{
	//system("cls");
	init_board();// init game board
	// and draw 
}

void check_key(void)
{
		int key = 0;
		if( (key = kbhit()) != 0)  // if keyboard press
		{
				if(key==224) // if it is direction key
				{
					do{
						key = kbhit();
					}
					while( key== 224);
					switch(key){
						case LEFT:
							// move left
							printf("<-\n");
							break;
						case RIGHT:
							// move
							break;
						case DOWN:
							break;
						case UP:
							break;
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
			board[x][y]=rand()%5;
		}
	}
	// 3 match test fucntion -> retrun (x,y,shape)
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
