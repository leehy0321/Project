#include "/home/hwayoung/TeamProject/Project/hwayoung/ui/include/total.h" 
#include "/home/hwayoung/TeamProject/Project/hwayoung/ui/include/board.h"
#include "/home/hwayoung/TeamProject/Project/hwayoung/ui/include/keyboard.h"
#include "/home/hwayoung/TeamProject/Project/hwayoung/ui/include/util.h"
#include "/home/hwayoung/TeamProject/Project/hwayoung/ui/include/timer.h"

#include <pthread.h>  // timer

// variable
int board[B_SIZE_X][B_SIZE_Y]; // board to draw
int board_cpy[B_SIZE_X][B_SIZE_Y];  // prior board(cpy)

int POSITION_X= 1, POSITION_Y= 1;  // now position

/////////////////////////////////////////////////////////////////////////
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

int main()
{	
	reset_game();
	pthread_t p_thread;
    int thr_id;
    int status;
    int time = 1;
    int drawFlag=0;
    
    int i=0;
	
	// 쓰레드 생성 아규먼트로 1 을 넘긴다.  
    thr_id = pthread_create(&p_thread, NULL, t_function,(void *)&drawFlag);
	if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
	
	while(1)
	{
		check_key(board,&POSITION_X,&POSITION_Y,&drawFlag);
		//draw_gameBoard(board,board_cpy);
		if( drawFlag==1)
		{
			draw_gameBoard(board,board_cpy);
			drawFlag=0;
		}
	}
 
    // 쓰레드 종료를 기다린다. 
    pthread_join(p_thread, (void **)&status);
	
	return 0;
}

