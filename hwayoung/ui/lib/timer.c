// timer
#include <pthread.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <stdlib.h>
#include "/home/hwayoung/TeamProject/Project/hwayoung/ui/include/util.h"
#include "/home/hwayoung/TeamProject/Project/hwayoung/ui/include/total.h" 

// 쓰레드 함수
void *t_function(void *_drawFlag)  // miniutes
{
    int time[3]={0,}; // hour,min,sec // time[0]:hour time[1]:min time[2]:sec
    int flag =1;
    int drawFlag=0;
    
    time[1] = 1;
    //time[1] = *((int *)timeSet); //min
    drawFlag = *((int *)_drawFlag);
    
    while(flag)
    {
		gotoxy(43,7);
		
		printf(" %d : %d : %d ",time[0],time[1],time[2]);
        sleep(1); // 1 sec
        
        drawFlag=1;
        if( time[1]==0 && time[2]==0 )
        {
			// terminate  // ** how to terminate thread
			flag = 0;
		}
        if( time[2] == 0 )
        {
			time[1]--;    //min
			time[2] = 60; //sec
		}
		time[2]--;
		drawFlag=0;
    }
}
