#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int change_number(int input)
{
	srand(time(NULL));
	
	int origin = input;
	int change = origin;
	
	while(origin == change)
	{
		change = rand()%5;
	}
	return change;
}
