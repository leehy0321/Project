#include <stdio.h>
#include <conio.h>  // gotoxy  (1~80,1~24)
#include <windows.h>

#define SHAPE_O 0  //'¡Ü'
#define SHAPE_D 1  //'¡á'
#define SHAPE_S 2  //'¡ã'
#define SHAPE_H 3  //'¢Ÿ'
#define SHAPE_A 4  //'¢Œ'

#define S_POSIT_X 2  // start position x
#define S_POSIT_Y 2  // start position y
#define B_SIZE_X 11  // board size x ( game size x )
#define B_SIZE_Y 11

///////////////////////////////////////////////////////////////////////
//variable

int block[5][2] = { { '¡Û', '¡Ü' },{ '¡à','¡á' },{ '¡â','¡ã' },
					{ '¢œ','¢Ÿ' },{ '¢»','¢Œ' } };
// [0][0] : '¡Û'
// [0][1] : '¡Ü'

int board[B_SIZE_X][B_SIZE_Y]; // board to draw
int board_cpy[B_SIZE_X][B_SIZE_Y];  // prior board(cpy)

/////////////////////////////////////////////////////////////////////////
// functions
void gotoxy(int x, int y);
void draw_gameBoard();


/////////////////////////////////////////////////////////////////////////
int main(void)
{
	for(int i=0; i<5; i++)
	{
		printf("block[%d][0] = %c\n",i,block[i][0]);
		printf("block[%d][1] = %c\n", i, block[i][1]);
	}
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { 2*x,y };  // why multiple 2 **
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
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
