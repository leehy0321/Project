#include "ui/include/total.h" 
#include "ui/include/board.h"
#include "ui/include/keyboard.h"
#include "ui/include/util.h"
#include "ui/include/timer.h"
#include "../hayoung/include/check.h"
#include <pthread.h>  // timer
#include <stdlib.h>
#include <string.h>
// variable
// board to draw
int board_cpy[B_SIZE_X][B_SIZE_Y];  // prior board(cpy)

int _board[B_SIZE_X][B_SIZE_Y];
int POSITION_X= 1, POSITION_Y= 1;  // now position

int val[2][3][5];
int SCORE;
/////////////////////////////////////////////////////////////////////////
void reset_game()
{
	//make & init board
	reset_gameBoard(_board, POSITION_X, POSITION_Y);
	make_board(_board,POSITION_X, POSITION_Y);
	while(Entry_check(_board));
	
	// draw
	system("clear");
	title();
	draw_gameBoard(_board,board_cpy);
}

int main()
{	
	reset_game();
	pthread_t p_thread;
    int thr_id;
    int status;
    int time = 1;
    int drawFlag=0;
    
    int i=0;
	draw_gameBoard(_board,board_cpy);
	// 쓰레드 생성 아규먼트로 1 을 넘긴다.  
    thr_id = pthread_create(&p_thread, NULL, t_function,(void *)&drawFlag);
	if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
	
	while(1)
	{
		check_key(_board,&POSITION_X,&POSITION_Y,&drawFlag,val,&SCORE);
		while(Entry_check(_board));
		memset(val,0,sizeof(val));
		draw_gameBoard(_board,board_cpy);
		if( drawFlag==1)
		{
			draw_gameBoard(_board,board_cpy);
			drawFlag=0;
		}
	}
 
 
    // 쓰레드 종료를 기다린다. 
    pthread_join(p_thread, (void **)&status);
	return 0;
}

