int change_number(int input)
{
	srand(time(0));
	
	int origin = input;
	int change = origin;
	
	while(origin == change)
	{
		change = rand()%5 +1; // 0~4
	}
	return change;
}
