#include<stdio.h>

void bug2(void)
{
	printf("this is bug2\n");
}

int foo2(void)
{
	printf("foo2\n");
	return 0;
}

int main(void)
{
	printf("world\n");
	return 0;
}
