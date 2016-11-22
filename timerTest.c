#include <pthread.h>
#include <stdio.h>
#include <unistd.h> // sleep
#include <stdlib.h>

// 쓰레드 함수
void *t_function(void *timeSet)  // miniutes
{
    int time[3]={0,}; // hour,min,sec // time[0]:hour time[1]:min time[2]:sec
    int flag =1;
    
    time[1] = *((int *)timeSet); //min
    
    while(flag)
    {
		printf("timer start\n");
		printf("timer %d : %d : %d \n",time[0],time[1],time[2]);
        sleep(1); // 1 sec
        
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
		
    }
}

int main()
{
    pthread_t p_thread;
    int thr_id;
    int status;
    int time = 1;
    
    int i=0;

    // 쓰레드 생성 아규먼트로 1 을 넘긴다.  
    thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&time);

    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }


	while(1)
	{
		//printf("main while : %d\n",i);
		i++;
		sleep(1);
	}
 

    // 쓰레드 종료를 기다린다. 
    pthread_join(p_thread, (void **)&status);

    return 0;
}

