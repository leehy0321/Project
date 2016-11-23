#include <stdio.h>

int main()
{
	int a = 3;
	int *A;
	A =&a;
	
	printf("*A = %d\n",*A);
	printf("A = %f\n",A);
	printf("&A = %f\n",&A);
	return 0;
}
