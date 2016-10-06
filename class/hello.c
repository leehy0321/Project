#include<stdio.h>

void bug1(void)
{
	printf("this is bug1\n");
}

int foo1(void)
{
	printf("foo1\n");
	return 0;
}

int main(void)
{
	printf("hello\n");
	return 0;
}
